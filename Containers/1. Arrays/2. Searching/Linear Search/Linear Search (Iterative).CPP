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
        size=s;
        index=-1;
    }
    void append(int value)
    {
        array[++index]=value;
    }
    int search(int value)
    {
        for(int i=0;i<=index;i++)
        if(array[i]==value)
        return i+1;
        return -1;
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
    void forward()
    {
        for(int i=0;i<=index;i++)
        cout<<array[i]<<", ";
    }
};

int main()
{
    list lst(5);
    int ch,pos,value;
    do
    {
        system("cls");
        cout<<"\n 1. Add     ";
        cout<<"\n 2. Search  ";
        cout<<"\n 3. Display ";
        cout<<"\n 4. Exit    ";
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
            if(!lst.empty())
            {
                cout<<"\n Enter a value : ";
                cin>>value;
                pos=lst.search(value);
                cout<<"\n '"<<value<<"' ";
                if(pos!=-1)
                cout<<"found at position "<<pos;
                else cout<<"not found";
            }
            else
            cout<<"\n Array is empty! ";
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
