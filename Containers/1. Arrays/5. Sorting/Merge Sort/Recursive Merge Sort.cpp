#include<iostream>
#include<stdlib.h>

using namespace std;

class list
{
    int *array;
    int index;
    int size;
    void divide(int low,int high)
    {
        int mid;
        if(low<high)
        {
            mid=(low+high)/2;
            divide(low,mid);
            divide(mid+1,high);
            conquer(low,mid,high);
        }
    }
    void conquer(int low,int mid,int high)
    {
        int temp[high+1];
        int i=low,j=mid+1,k=low;
        while(i<=mid&&j<=high)
        {
            if(array[i]<array[j])
            temp[k]=array[i++];
            else if(array[j]<array[i])
            temp[k]=array[j++];
            k++;
        }
        for(i;i<=mid;i++,k++)  temp[k]=array[i];
        for(j;j<=high;j++,k++) temp[k]=array[j];
        for(i=low;i<k;i++)     array[i]=temp[i];
    }
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
    int append(int value)
    {array[++index]=value;}
    void mergesort()
    {divide(0,index);}
    int display()
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
		cout<<"\n 2. Merge Sort ";
		cout<<"\n 3. Display ";
		cout<<"\n 4. End Program ";
		cout<<"\n\n Enter>>";
		cin>>ch; switch(ch)
		{
			case 1:
            if(!lst.full())
            {
                cout<<"\n Enter a value : ";
                cin>>value; lst.append(value);
            }
            else
            {
                cout<<"\n Array is full! ";
                cout<<"\n "; system("pause");
            }
			break;

			case 2:
            cout<<"\n Array is : ";
            if(!lst.empty())
            {
                lst.mergesort();
                lst.display();
            }
            else cout<<"empty!";
            cout<<"\n "; system("pause");
			break;

			case 3:
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
