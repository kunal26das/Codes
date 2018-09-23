#include<iostream>
#include<stdlib.h>
#include<conio.h>

using namespace std;

class list
{
    int *array;
    int index;
    int size;
    public:
    list(int s)
    {
        array=new int[s];
        index=-1; size=s;
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
    void append(int value)
    {array[++index]=value;}
    void backward()
    {
        for(int i=index;i>=0;i--)
        cout<<array[i]<<", ";
    }
    void forward()
    {
        for(int i=0;i<=index;i++)
        cout<<array[i]<<", ";
    }
    void destroy()
    {
        index=-1;
        delete array;
        array=new int[size];
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
        cin>>ch; switch(ch)
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

            case 0 :
            lst.destroy();
            break;
        }
    }while(ch!=4);
}
