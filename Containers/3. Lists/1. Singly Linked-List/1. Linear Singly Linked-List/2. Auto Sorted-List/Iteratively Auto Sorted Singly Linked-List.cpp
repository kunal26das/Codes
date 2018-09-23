#include<iostream>
#include<stdlib.h>
#include<conio.h>

using namespace std;

class list
{
    class node
    {
        public:
        int value;
        node *next;
        node()
        {
            next=NULL;
            value=_value;
        }
    }*first,*last;
    node* findnode(int value)
    {
        node *ptr=first;
        while(ptr!=NULL)
        {
            if(ptr->next->value<value)
            ptr=ptr->next;
            else break;
        }
        return ptr;
    }
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
    void insert(node *x)
    {
        if(first==NULL)
        {
            first=x;
            last=x;
        }
        else if(x->value<first->value)
        {
            x->next=first;
            first=x;
        }
        else if(x->value>last->value)
        {
            last->next=x;
            last=x;
        }
        else
        {
            node *ptr=findnode(x->value);
            x->next=ptr->next;
            ptr->next=x;
        }
    }
    void forward()
    {
        node *ptr=first;
        while(ptr)
        {
            cout<<ptr->value<<", ";
            ptr=ptr->next;
        }
    }
    void backward()
    {
        node *temp,*ptr;
        node *mark=last;
        while(mark!=first)
        {
            temp=first;
            ptr=temp->next;
            while(ptr!=mark)
            {
                temp=temp->next;
                ptr=temp->next;
            }
            mark=temp;
            cout<<ptr->value<<", ";
        }
        cout<<first->value;
    }
};

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
            lst.insert(create(value));
            break;

            case 2 :
            cout<<"\n The list is : ";
            if(!lst.empty())
            lst.backward();
            else cout<<"empty!";
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
