#include<iostream>
#include<stdlib.h>
#include<conio.h>

using namespace std;

class node
{
    public:
    int value;
    node *next;
    node(int v)
    {
        value=v;
        next=NULL;
    }
};

class list
{
    node *first,*last;
    public:
    list()
    {
        first=NULL;
        last=NULL;
    }
    int empty()
    {
        if(!first)
        return 1;
        return 0;
    }
    void append(int value)
    {
        node *x=new node(value);
        if(first) last->next=x;
        else first=x; last=x;
    }
    void display()
    {
        node *ptr=first;
        while(ptr)
        {
            cout<<ptr->value<<", ";
            ptr=ptr->next;
        }
    }
};

class hash
{
    int size;
    list *lst;
    public:
    hash(int s)
    {
        size=s;
        lst=new list[s];
    }
    void insert(int value)
    {lst[value%size].append(value);}
    void display()
    {
        for(int i=0;i<size;i++)
        {
            cout<<"\n "<<i<<" : ";
            if(!lst[i].empty())
            lst[i].display();
            cout<<endl;
        }
    }
};

int main()
{
    int ch,value;
    hash table(10);
    do
    {
        system("cls");
        cout<<"\n 1. Insert ";
        cout<<"\n 2. Display ";
        cout<<"\n 3. End Program ";
        cout<<"\n\n Enter>>";
        cin>>ch; switch(ch)
        {
            case 1 :
            cout<<"\n Enter a value : ";
            cin>>value; table.insert(value);
            break;

            case 2 :
            cout<<"\n Hash table is : \n";
            table.display(); getch();
            break;
        }
    }while(ch!=3);
}
