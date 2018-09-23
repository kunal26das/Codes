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
        index=-1;
        size=s;
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
    {
        array[++index]=value;
    }
    void sort()
    {
        int i,j,temp;
        for(i=1;i<=index;i++)
        {
            temp=array[i];
            for(j=i-1;j>=0;j--)
            {
                if(temp<array[j])
                array[j+1]=array[j];
                else break;
            }
            array[j+1]=temp;
        }
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
	int ch,value;
	do
	{
		system("cls");
		cout<<"\n 1. Add     ";
		cout<<"\n 2. Sort    ";
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
            cout<<"\n Array is : ";
            if(!lst.empty())
            {
                lst.sort();
                lst.forward();
            }
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
