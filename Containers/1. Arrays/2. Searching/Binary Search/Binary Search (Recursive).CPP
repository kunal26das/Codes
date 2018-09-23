#include<iostream.h>
#include<process.h>
#include<conio.h>

int array[5],size=5,x=-1;
int value,pos=-1;

void add();

void process();
void b_search(int low,int high);

void display();

void main()
{
	int choice;
	do
	{
		clrscr();
		cout<<"\n    MENU :-       \n";
		cout<<"\n 1. Add           \n";
		cout<<"\n 2. Binary Search \n";
		cout<<"\n 3. Display       \n";
		cout<<"\n 4. Exit          \n";
		cout<<"\n    Enter your choice : ";
		cin>>choice;
		switch(choice)
		{
			case 1 :
			add();
			break;

			case 2 :
			process();
			break;

			case 3 :
			display();
			break;
		}
	}while(choice!=4);
}

void add()
{
	if(x<size-1)
	{
		x++;
		cout<<"\n    Enter the value : ";
		cin>>array[x];
		if(array[x]<array[x-1])
		{
			cout<<"\n    Binary search precondition violated! \n";
			cout<<"\n    Closing program";
			getch();
			exit(0);
		}
	}
	else
	{
		cout<<"\n    Array is full!";
		getch();
	}
}

void process()
{
	cout<<"\n    Enter the value to be searched : ";
	cin>>value;

	b_search(0,x);

	if(pos>-1)
	cout<<"\n    The position of the element is : "<<pos+1;

	else
	cout<<"\n    Element not found in the array!";

	getch();
}

void b_search(int low,int high)
{
	int mid;

	if(x!=-1 && low<=high)
	{
		mid=(low+high)/2;

		if(array[mid]==value)
		{
			pos=mid;
			return;
		}

		else if(array[mid]<value)
		b_search(mid+1,high);

		else if(array[mid]>value)
		b_search(low,mid-1);
	}

	else
	{
		cout<<"\n    Array is empty!";
		getch();
	}
}

void display()
{
	if(x!=-1)
	{
		cout<<"\n    Array is : ";
		for(int i=0;i<=x;i++)
		cout<<array[i]<<" ";
	}
	else
	cout<<"\n    Array is empty!";
	getch();
}