#include<iostream>
#include<stdlib.h>

using namespace std;

class queue
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
    }*front;
    void destroy(node *ptr)
    {
        if(ptr->next==front)
        {
            delete ptr;
            return;
        }
        destroy(ptr->next);
        delete ptr;
    }
    public:
    queue(){front=NULL;}
    int empty()
    {
        if(!front)
        return 1;
        return 0;
    }
    int peek()
    {return front->value;}
    void enqueue(int value)
    {
        node *x=new node(value);
        if(front)
        {
            node *ptr=front;
            while(ptr->next!=front)
            ptr=ptr->next;
            ptr->next=x;
        }
        else front=x;
        x->next=front;
    }
    int dequeue()
    {
        node *temp=front;
        int value=front->value;
        if(front->next!=front)
        {
            node *ptr=front;
            while(ptr->next!=front)
            ptr=ptr->next;
            ptr->next=front->next;
            front=front->next;
        }
        else front=NULL;
        delete temp;
        return value;
    }
    void display()
    {
        node *ptr=front;
        do
        {
            cout<<ptr->value<<", ";
            ptr=ptr->next;
        }while(ptr!=front);
    }
    void destroy()
    {
        if(!front) return;
        destroy(front);
        front=NULL;
    }
};

int main()
{
    queue que;
    int value,ch;
    do
    {
        system("cls");
        cout<<"\n 1. Peek ";
        cout<<"\n 2. Enqueue ";
        cout<<"\n 3. Dequeue ";
        cout<<"\n 4. Display ";
        cout<<"\n 5. End Program ";
        cout<<"\n\n Enter>>";
        cin>>ch; switch(ch)
        {

            case 1 :
            if(!que.empty())
            cout<<"\n Front is : "<<que.peek();
            else cout<<"\n Queue is empty!";
            cout<<"\n "; system("pause");
            break;

            case 2 :
            cout<<"\n Enter a value : ";
            cin>>value; que.enqueue(value);
            break;

            case 3 :
            if(!que.empty())
            cout<<"\n Dequeued value is : "<<que.dequeue();
            else cout<<"\n Queue is empty!";
            cout<<"\n "; system("pause");
            break;

            case 4 :
            cout<<"\n Queue is : ";
            if(!que.empty()) que.display();
            else cout<<"empty!";
            cout<<"\n "; system("pause");
            break;

            case 0 :
            que.destroy();
            break;
        }
    }while(ch!=5);
}
