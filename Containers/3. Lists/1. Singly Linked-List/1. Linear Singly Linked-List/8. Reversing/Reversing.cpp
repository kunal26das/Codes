#include<iostream>
#include<stdlib.h>
#include<conio.h>

using namespace std;

struct node
{
    int value;
    node *next;
};
class list
{
    node *first;
    node *last;
    public:
    list()
    {
        first=NULL;
        last=NULL;
    }
    void append(node *x)
    {
        if(first==NULL) first=x;
        else last->next=x;
        last=x;
    }
    void reverse()
    {
        int temp;
        node *t,*p=first,*q=last,*mark=last;
        cout<<"\n Reversing... \n";
        while(p!=q)
        {
            t=first;
            q=t->next;
            while(q!=mark)
            {
                t=t->next;
                q=t->next;
            }
            mark=t;
            temp=p->value;
            p->value=q->value;
            q->value=temp;
            p=p->next;
        }
    }
    void display()
    {
        node *ptr=first;
        cout<<"\n The list is : ";
        if(ptr==NULL) cout<<"Empty!";
        else while(ptr!=NULL)
        {
            cout<<ptr->value<<", ";
            ptr=ptr->next;
        }
        cout<<endl;
    }
};

node* create(int value)
{
    node *x=new node;
    x->value=value;
    x->next=NULL;
    return x;
}

int main()
{
    list l;
    int value,ch;
    do
    {
        system("cls");
        cout<<"\n 1. Add     ";
        cout<<"\n 2. Reverse ";
        cout<<"\n 3. Display ";
        cout<<"\n 4. Exit    ";
        cout<<"\n\n Enter>>";
        cin>>ch;
        switch(ch)
        {
            case 1 :
                cout<<"\n Enter a value : ";
                cin>>value;
                l.append(create(value));
                break;
            case 2 :
                l.display();
                l.reverse();
                l.display();
                getch();
                break;
            case 3 :
                l.display();
                getch();
                break;
        }
    }while(ch!=4);
}
