#include<iostream>
#include<stdlib.h>
#include<conio.h>

using namespace std;

#include <iostream>
using namespace std;

class list
{
    int *array,size,index;
    void heapify(int lb,int ub)
    {
        int largest=lb,l=2*lb+1,r=2*lb+2;
        if(l<ub&&array[l]>array[largest]) largest=l;
        if(r<ub&&array[r]>array[largest]) largest=r;
        if(largest!=lb)
        {
            swap(array[lb],array[largest]);
            heapify(largest,ub);
        }
    }
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
    void sort()
    {
        for(int i=index/2;i>=0;i--)
        heapify(i,index);
        for(int i=index;i>=0;i--)
        {
            swap(array[0],array[i]);
            heapify(0,i);
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
                system("pause");
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
            system("pause");
            break;

			case 3 :
            cout<<"\n Array is : ";
            if(!lst.empty())
            lst.forward();
            else cout<<"empty!";
            system("pause");
            break;
		}
	}while(ch!=4);
}
