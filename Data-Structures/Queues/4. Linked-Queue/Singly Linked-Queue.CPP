#include<iostream>
#include<stdlib.h>
#include<conio.h>

using namespace std;

struct node
{
    int value;
    node *next;
};
class queue
{
    node *front;
    node *rear;
    public:
    queue()
    {
        front=NULL;
        rear=NULL;
    }
    void enqueue(int value)
    {
        node *x=new node;
        x->value=value;
        x->next=NULL;
        if(!front) front=x;
        else rear->next=x;
        rear=x;
    }
    int dequeue()
    {
        node *temp=front;
        int value=front->value;
        front=front->next;
        delete temp;
        return value;
    }
    int empty()
    {
        if(!front)
        return 1;
        return 0;
    }
    void display()
    {
        node *ptr=front;
        while(ptr)
        {
            cout<<ptr->value<<", ";
            ptr=ptr->next;
        }
    }
};

int main()
{
    queue que;
    int ch,value;
    do
    {
        system("cls");
        cout<<"\n 1. Enqueue ";
        cout<<"\n 2. Dequeue ";
        cout<<"\n 3. Display ";
        cout<<"\n 4. Exit    ";
        cout<<"\n\n Enter>>";
        cin>>ch;
        switch(ch)
        {
            case 1 :
            cout<<"\n Enter a value : ";
            cin>>value;
            que.enqueue(value);
            break;

            case 2 :
            if(!que.empty())
            cout<<"\n Dequeued value is "<<que.dequeue();
            else cout<<"\n Queue is empty! ";
            getch();
            break;

            case 3 :
            cout<<"\n Queue is : ";
            if(!que.empty())
            que.display();
            else cout<<"empty!";
            getch();
            break;
        }
    }while(ch!=4);
}
