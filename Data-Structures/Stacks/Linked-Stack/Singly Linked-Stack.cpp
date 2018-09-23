#include<iostream>
#include<stdlib.h>
#include<conio.h>

using namespace std;

struct node
{
    int value;
    node *next;
};
class stack
{
    node *top;
    public:
    stack(){top=NULL;}
    void push(int value)
    {
        node *x=new node;
        x->value=value;
        x->next=NULL;
        if(top!=NULL)
        x->next=top;
        top=x;
    }
    int pop()
    {
        int value=top->value;
        node *temp=top;
        top=top->next;
        delete temp;
        return value;
    }
    int underflow()
    {
        if(top==NULL)
        return 1;
        return 0;
    }
    void display()
    {
        node *ptr=top;
        while(ptr!=NULL)
        {
            cout<<"\n "<<ptr->value;
            ptr=ptr->next;
        }
    }
};

int main()
{
    stack stk;
    int value,ch;
    do
    {
        system("cls");
        cout<<"\n 1. Push    ";
        cout<<"\n 2. Pop     ";
        cout<<"\n 3. Display ";
        cout<<"\n 4. Exit    ";
        cout<<"\n\n Enter>>";
        cin>>ch;
        switch(ch)
        {
            case 1:
            cout<<"\n Enter a value : ";
            cin>>value;
            stk.push(value);
            break;

            case 2:
            if(!stk.underflow())
            cout<<"\n Popped value is "<<stk.pop();
            else cout<<"\n Stack is underflowing! ";
            getch();
            break;

            case 3:
            cout<<"\n Stack is ";
            if(!stk.underflow())
            stk.display();
            else cout<<"underflowing! ";
            getch();
            break;
        }
    }while(ch!=4);
}
