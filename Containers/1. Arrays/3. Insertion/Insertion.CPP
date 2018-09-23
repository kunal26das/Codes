#include<iostream.h>
#include<conio.h>

int array[5],size=5,x=-1;

void add();
void insert();
void display();

void main()
{
	int choice;
	do
	{
		clrscr();
		cout<<"\n    MENU :- \n";
		cout<<"\n 1. Add     \n";
		cout<<"\n 2. Insert  \n";
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
			insert();
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

void insert()
{
	int loc,value;

	if(x>=size-1)
	{
		cout<<"\n    Array is full!";
		getch();
		return;
	}

	else if(x!=-1)
	{
		cout<<"\n    Enter the location : ";
		cin>>loc;
		loc--;
		if(loc<0||loc>x)
		{
			cout<<"\n    Insertion not possible!";
			getch();
			return;
		}
		cout<<"\n    Enter the value : ";
		cin>>value;
		for(int i=x;i>=loc;i--)
		array[i+1]=array[i];
		array[loc]=value;
		x++;
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