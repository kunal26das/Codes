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
        node(int _value)
        {
            next=NULL;
            value=_value;
        }
    }*first,*last;
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
    void insert(int value)
    {
        node *x=new node(value);
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
        cout<<"\n 1. Append ";
        cout<<"\n 2. Forward ";
        cout<<"\n 3. Backward ";
        cout<<"\n 4. End Program ";
        cout<<"\n\n Enter>>";
        cin>>ch; switch(ch)
        {
            case 1 :
            cout<<"\n Enter a value : ";
            cin>>value;
            lst.insert(create(value));
            break;

            case 2 :
            cout<<"\n The list is : ";
            if(!lst.empty())
            lst.forward();
            else cout<<"empty!";
            cout<<"\n ";
            system("pause");
            break;

            case 3 :
            cout<<"\n The list is : ";
            if(!lst.empty())
            lst.backward();
            else cout<<"empty!";
            cout<<"\n ";
            system("pause");
            break;
        }
    }while(ch!=4);
}
