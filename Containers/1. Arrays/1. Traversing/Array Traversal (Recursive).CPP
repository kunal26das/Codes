#include<iostream>
#include<stdlib.h>
#include<conio.h>

using namespace std;

class list
{
    int *array;
    int size;
    int index;
    public:
    list(int s)
    {
        array=new int[s];
        size=s;
        index=-1;
    }
    void append(int value)
    {
        array[++index]=value;
    }
    int empty()
    {
        if(index==-1)
        return 1;
        return 0;
    }
    int full()
    {
        if(index==size-1)
        return 1;
        return 0;
    }
    void backward(int i=0)
    {
        if(i<=index)
        {
            backward(i+1);
            cout<<array[i]<<", ";
        }
    }
    void forward(int i=0)
    {
        if(i<=index)
        {
            cout<<array[i]<<", ";
            forward(i+1);
        }
    }
};

int main()
{
    list lst(5);
    int ch,value;
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
            if(!lst.full())
            {
                cout<<"\n Enter a value : ";
                cin>>value;
                lst.append(value);
            }
            else
            {
                cout<<"\n Array is full! ";
                getch();
            }
            break;

            case 2 :
            cout<<"\n Array is : ";
            if(!lst.empty())
            lst.backward();
            else cout<<"empty!";
            getch();
            break;

            case 3 :
            cout<<"\n Array is : ";
            if(!lst.empty())
            lst.forward();
            else cout<<"empty!";
            getch();
            break;
        }
    }while(ch!=4);
}
