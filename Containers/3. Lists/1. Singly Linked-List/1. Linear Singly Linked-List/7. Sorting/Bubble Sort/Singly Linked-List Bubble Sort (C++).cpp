#include<iostream>
#include<stdlib.h>

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
    void destroy(node *ptr)
    {
        if(!ptr) return;
        destroy(ptr->next);
        delete ptr;
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
    void append(int value)
    {
        node *x=new node(value);
        if(last) last->next=x;
        else first=x; last=x;
    }
    void bubblesort()
    {
        node *temp,*ptr=first;
        while(ptr)
        {
            temp=ptr->next;
            while(temp)
            {
                if(ptr->value>temp->value)
                swap(ptr->value,temp->value);
                temp=temp->next;
            }
            ptr=ptr->next;
        }
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
    void destroy()
    {
        if(!first) return;
        destroy(first);
        first=NULL;
        last=NULL;
    }
};

int main()
{
    list lst;
    int ch,value;
    do
    {
        system("cls");
        cout<<"\n 1. Append ";
        cout<<"\n 2. Bubble Sort ";
        cout<<"\n 3. Display ";
        cout<<"\n 4. End Program ";
        cout<<"\n\n Enter>>";
        cin>>ch; switch(ch)
        {
            case 1 :
            cout<<"\n Enter a value : ";
            cin>>value; lst.append(value);
            break;

            case 2 :
            cout<<"\n List is : ";
            if(!lst.empty())
            {
                lst.bubblesort();
                lst.display();
            }
            else cout<<"empty!";
            cout<<"\n ";
            system("pause");
            break;

            case 3 :
            cout<<"\n List is : ";
            if(!lst.empty())
            lst.display();
            else cout<<"empty!";
            cout<<"\n ";
            system("pause");
            break;

            case 0 :
            lst.destroy();
            break;
        }
    }while(ch!=4);
}
