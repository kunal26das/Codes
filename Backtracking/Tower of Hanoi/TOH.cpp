#include<iostream>
#include<stdlib.h>
#include<conio.h>

using namespace std;

struct node
{
	int value;
	node *next;
};

class stack
{
    public:
    node *top;
    stack(){top=NULL;}
    void push(int value)
    {
        node *x=new node;
        x->value=value;
        x->next=NULL;
        if(top!=NULL)
        x->next=top;
        top=x;
    }
    int pop()
    {
        int value=top->value;
        node *temp=top;
        top=top->next;
        delete temp;
        return value;
    }
}a,b,c;

int stage=0;

void display()
{
    node *p=a.top,*q=b.top,*r=c.top;
    cout<<"\n Stage "<<stage++<<" ---------- \n";
    while(p!=NULL || q!=NULL || r!=NULL)
    {
        cout<<"\n ";
        if(p!=NULL)
        {
            cout<<p->value;
            p=p->next;
        }
        cout<<"\t ";
        if(q!=NULL)
        {
            cout<<q->value;
            q=q->next;
        }
        cout<<"\t ";
        if(r!=NULL)
        {
            cout<<r->value;
            r=r->next;
        }
    }
    cout<<endl;
}

void hanoi(int n,stack &x,stack &y,stack &z)
{
	if(n>0)
	{
		hanoi(n-1,x,z,y);
		display();
        z.push(x.pop());   //"Move disk n from stack x to stack z"
		hanoi(n-1,y,x,z);
	}
}

int main()
{
    int i,n=10;
    for(i=n;i>=1;i--) a.push(i);
    hanoi(n,a,b,c);
    display();
    cout<<"\n ------------------ \n";
}
