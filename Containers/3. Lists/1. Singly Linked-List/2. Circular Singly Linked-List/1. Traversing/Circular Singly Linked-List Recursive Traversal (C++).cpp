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
    }*head;
    void forward(node *ptr)
    {
        cout<<ptr->value<<", ";
        if(ptr->next==head) return;
        forward(ptr->next);
    }
    void backward(node *ptr)
    {
        if(ptr->next==head)
        {
            cout<<ptr->value<<", ";
            return;
        }
        backward(ptr->next);
        cout<<ptr->value<<", ";
    }
    void destroy(node *ptr)
    {
        if(ptr->next==head)
        {
            delete ptr;
            return;
        }
        destroy(ptr->next);
        delete ptr;
    }
    public:
    list(){head=NULL;}
    int empty()
    {
        if(!head)
        return 1;
        return 0;
    }
    void append(int value)
    {
        node *x=new node(value);
        if(head)
        {
            node *ptr=head;
            while(ptr->next!=head)
            ptr=ptr->next;
            ptr->next=x;
        }
        else head=x;
        x->next=head;
    }
    void forward(){forward(head);}
    void backward(){backward(head);}
    void destroy()
    {
        if(!head) return;
        destroy(head);
        head=NULL;
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
            cin>>value; lst.append(value);
            break;

            case 2 :
            cout<<"\n The list is : ";
            if(!lst.empty()) lst.forward();
            else cout<<"empty!";
            cout<<"\n "; system("pause");
            break;

            case 3 :
            cout<<"\n The list is : ";
            if(!lst.empty()) lst.backward();
            else cout<<"empty!";
            cout<<"\n "; system("pause");
            break;

            case 0 :
            lst.destroy();
            break;
        }
    }while(ch!=4);
}
