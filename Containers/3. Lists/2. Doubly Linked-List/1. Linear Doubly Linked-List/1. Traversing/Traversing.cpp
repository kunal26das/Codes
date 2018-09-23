#include<iostream>
#include<stdlib.h>
#include<conio.h>

using namespace std;

struct node
{
    int value;
    node *prev;
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
        x->prev=last;
        last=x;
    }
    int empty()
    {
        if(first==NULL)
        return 1;
        return 0;
    }
    void forward()
    {
        node *ptr=first;
        while(ptr!=NULL)
        {
            cout<<ptr->value<<", ";
            ptr=ptr->next;
        }
    }
    void backward()
    {
        node *ptr=last;
        while(ptr!=NULL)
        {
            cout<<ptr->value<<", ";
            ptr=ptr->prev;
        }
    }
};

node* create(int value)
{
    node *x=new node;
    x->value=value;
    x->prev=NULL;
    x->next=NULL;
    return x;
}

int main()
{
    list lst;
    int value,ch;
    do
    {
        system("cls");
        cout<<"\n 1. Add      ";
        cout<<"\n 2. Backward ";
        cout<<"\n 3. Forward  ";
        cout<<"\n 4. Exit     ";
        cout<<"\n\n Enter>>";
        cin>>ch;
        switch(ch)
        {
            case 1 :
            cout<<"\n Enter a value : ";
            cin>>value;
            lst.append(create(value));
            break;

            case 2 :
            cout<<"\n The list is : ";
            if(!lst.empty())
            lst.backward();
            else cout<<"empty";
            getch();
            break;

            case 3 :
            cout<<"\n The list is : ";
            if(!lst.empty())
            lst.forward();
            else cout<<"empty!";
            getch();
            break;
        }
    }while(ch!=4);
}
