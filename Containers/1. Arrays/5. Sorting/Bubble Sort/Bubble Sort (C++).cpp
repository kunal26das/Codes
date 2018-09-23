#include<iostream>
#include<stdlib.h>

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
        size=s; index=-1;
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
    void bubblesort()
    {
        for(int i=0;i<=index-1;i++)
        for(int j=0;j<=index-1-i;j++)
        if(array[j]>array[j+1])
        swap(array[j],array[j+1]);
    }
    void display()
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
        cout<<"\n 1. Append ";
        cout<<"\n 2. Bubble Sort ";
        cout<<"\n 3. Display ";
        cout<<"\n 4. End Program ";
        cout<<"\n\n Enter>>";
        cin>>ch; switch(ch)
        {
            case 1 :
            if(!lst.full())
            {
                cout<<"\n Enter a value : ";
                cin>>value; lst.append(value);
            }
            else
            {
                cout<<"\n Array is full!\n ";
                system("pause");
            }
            break;

            case 2 :
            cout<<"\n Array is : ";
            if(!lst.empty())
            {
                lst.bubblesort();
                lst.display();
            }
            else cout<<"empty!";
            cout<<"\n "; system("pause");
            break;

            case 3 :
            cout<<"\n Array is : ";
            if(!lst.empty()) lst.display();
            else cout<<"empty!";
            cout<<"\n "; system("pause");
            break;

            case 0 :
            lst.destroy();
            break;
        }
    }while(ch!=4);
}
