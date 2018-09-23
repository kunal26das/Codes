#include<iostream.h>
#include<conio.h>

int queue[5],front=-1,rear=-1,size=5;

void     add();
void deleter();
void display();

void main()
{
	int ch;
	do
	{
		clrscr();
		cout<<"\n    MENU :- \n";
		cout<<"\n 1. Add \n";
		cout<<"\n 2. Delete \n";
		cout<<"\n 3. Display \n";
		cout<<"\n 4. Exit \n";
		cout<<"\n    Enter your choice : ";
		cin>>ch;
		switch(ch)
		{
			case 1:
			add();
			break;

			case 2:
			deleter();
			break;

			case 3:
			display();
			break;
		}
	}while(ch!=4);
}

void add()
{
	if(front==(rear+1)%size)
	{
		cout<<"\n    Queue is overflowing!";
		getch();
		return;
	}

	cout<<"\n    Enter the value : ";

	if(front==-1&&rear==-1)
	{
		front=0;
		rear=0;
		cin>>queue[rear];
	}
	else
	{
		rear=(rear+1)%size;
		cin>>queue[rear];
	}
}

void deleter()
{
	if(front==-1&&rear==-1)
	{
		cout<<"\n    Queue is underflowing!";
		getch();
		return;
	}

	cout<<"\n    The deleted value is : "<<queue[front];

	if(front==rear)
	{
		front=-1;
		rear=-1;
	}
	else
	front=(front+1)%size;
	getch();
}

void display()
{
	if(front!=-1&&rear!=-1)
	{
		cout<<"\n    The queue is : ";
		for(int i=front;i<rear;i=(i+1)%size)
		cout<<queue[i]<<" ";
		cout<<queue[rear];
		cout<<"\n\n    Front = "<<front+1;
		cout<<"\n\n    Rear  = "<<rear+1;
	}
	else
	cout<<"\n    Queue is underflowing!";
	getch();
}