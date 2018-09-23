#include<iostream>
#include<stdlib.h>
#include<conio.h>

using namespace std;

class stack
{
    int *array;
    int size;
    int top;
    public:
    stack(int s)
    {
        array=new int[s];
        size=s;
        top=-1;
    }
    int overflow()
    {
        if(top==size-1)
        return 1;
        return 0;
    }
    int underflow()
    {
        if(top==-1)
        return 1;
        return 0;
    }
    void push(int value)
    {
        array[++top]=value;
    }
    int pop()
    {
        return array[top--];
    }
    void display()
    {
        for(int i=top;i>=0;i--)
        cout<<"\n "<<array[i];
    }
};

int main()
{
    stack stk(5);
    int ch,value;
    do
    {
        system("cls");
        cout<<"\n 1. Push ";
        cout<<"\n 2. Pop ";
        cout<<"\n 3. Display ";
        cout<<"\n\n Enter>>";
        cin>>ch;
        switch(ch)
        {
            case 1 :
            if(!stk.overflow())
            {
                cout<<"\n Enter a value : ";
                cin>>value;
                stk.push(value);
            }
            else
            {
                cout<<"\n Stack is overflowing! ";
                getch();
            }
            break;

            case 2 :
            if(!stk.underflow())
            cout<<"\n Popped value : "<<stk.pop();
            else cout<<"\n Stack is underflowing! ";
            getch();
            break;

            case 3 :
            cout<<"\n Stack is : ";
            if(!stk.underflow())
            stk.display();
            else cout<<"underflowing! ";
            getch();
            break;
        }
    }while(ch!=4);
}
