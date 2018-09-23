#include<iostream>
#include<stdlib.h>
#include<conio.h>

using namespace std;

struct node
{
    int low;
    int high;
    node *next;
};

class stack
{
    node *top;
    public:
    stack()
    {top=NULL;}
    int underflow()
    {
        if(top==NULL)
        return 1;
        return 0;
    }
    void push(int low,int high)
    {
        node *x=new node;
        x->low=low;
        x->high=high;
        x->next=NULL;
        if(top!=NULL)
        x->next=top;
        top=x;
    }
    node pop()
    {
        node save;
        node *temp=top;
        save.low=top->low;
        save.high=top->high;
        top=top->next;
        delete temp;
        return save;
    }
};

class list
{
    int *array;
    int index;
    int size;
    void swap(int p,int q)
    {
        int temp=*(array+p);
        *(array+p)=*(array+q);
        *(array+q)=temp;
    }
    public:
    list(int s)
    {
        array=new int[s];
        index=-1; size=s;
    }
    int empty()
    {
        if(index==-1)
        return 1;
        return 0;
    }
    int full()
    {
        if(index==size-1)
        return 1;
        return 0;
    }
    void append(int value)
    {
        array[++index]=value;
    }
    void sort()
    {
        int i,j,n,p,q; for(n=1;n<=index;n*=2)
        for(i=0,j=n;i<=index,j<=index;i+=n*2,j+=n*2)
        for(p=i;p<j+0;p++) for(q=j;q<j+n;q++)
        if(array[p]>array[q]) swap(p,q);
    }
    void display()
    {
        for(int i=0;i<=index;i++)
        cout<<array[i]<<", ";
    }
};

int main()
{
    list lst(5);
    int ch,value;
    do
    {
        system("cls");
        cout<<"\n 1. Add ";
        cout<<"\n 2. Sort ";
        cout<<"\n 3. Display ";
        cout<<"\n 4. Exit ";
        cout<<"\n\n Enter>>";
        cin>>ch;
        switch(ch)
        {
            case 1 :
            if(!lst.full())
            {
                cout<<"\n Enter a value : ";
                cin>>value;
                lst.append(value);
            }
            else
            {
                cout<<"\n Array is full!";
                getch();
            }
            break;

            case 2 :
            cout<<"\n Array is : ";
            if(!lst.empty())
            {
                lst.sort();
                lst.display();
            }
            else cout<<"empty!";
            getch();
            break;

            case 3 :
            cout<<"\n Array is : ";
            if(!lst.empty())
            lst.display();
            else cout<<"empty!";
            getch();
            break;
        }
    }while(ch!=4);
}
