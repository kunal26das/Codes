#include<iostream.h>
#include<conio.h>

int array[5],size=5,x=-1;

void add();
void deleter();
void display();

void main()
{
	int choice;
	do
	{
		clrscr();
		cout<<"\n    MENU :- \n";
		cout<<"\n 1. Add     \n";
		cout<<"\n 2. Delete  \n";
		cout<<"\n 3. Display \n";
		cout<<"\n 4. Exit    \n";
		cout<<"\n    Enter your choice : ";
		cin>>choice;
		switch(choice)
		{
			case 1 :
			add();
			break;

			case 2 :
			deleter();
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
	}
	else
	{
		cout<<"\n    Array is full!";
		getch();
	}
}

void deleter()
{
	int loc,value;

	if(x!=-1)
	{
		cout<<"\n    Enter the location : ";
		cin>>loc;
		loc--;
		if(loc<0||loc>x)
		{
			cout<<"\n    Deletion not possible!";
			getch();
			return;
		}
		value=array[loc];
		cout<<"\n    Deleted value is : "<<value<<endl;
		for(int i=loc;i<=x;i++)
		array[i]=array[i+1];
		x--;
		display();
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