#include<iostream>
#include<stdlib.h>
#include<conio.h>

using namespace std;

class list
{
    int *array;
    int index;
    int size;
    void swap(int p,int q)
    {
        int temp=*(array+p);
        *(array+p)=*(array+q);
        *(array+q)=temp;
    }
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
    void sort(){divide(0,index);}
    void divide(int low,int high)
    {
        int mid;
        if(low<high)
        {
            mid=conquer(low,high);
            divide(low,mid-1);
            divide(mid+1,high);
        }
    }
    int conquer(int low,int high)
    {
        int pivot=array[low],i=low;
        for(int j=low+1;j<=high;j++)
        if(array[j]<=pivot)
        {
            i++;
            swap(i,j);
        }
        swap(i,low);
        return i;
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

			case 2:
            cout<<"\n Array is : ";
			if(!lst.empty())
            {
                lst.sort();
                lst.forward();
            }
            else cout<<"empty!";
            getch();
			break;

			case 3:
			cout<<"\n Array is : ";
			if(!lst.empty())
            lst.forward();
            else cout<<"empty!";
            getch();
			break;
		}
	}while(ch!=4);
}
