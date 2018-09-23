#include<iostream.h>
#include<conio.h>

int cost[10][10],min[10][10],x=0;

void add();
void floyd();
void display();

void main()
{
	int choice;
	do
	{
		clrscr();
		cout<<"\n    MENU :- \n";
		cout<<"\n 1. Add Vertex \n";
		cout<<"\n 2. Shortest Path \n";
		cout<<"\n 3. Display \n";
		cout<<"\n 4. Exit \n";
		cout<<"\n    Enter your choice : ";
		cin>>choice;
		switch(choice)
		{
			case 1 :
			add();
			display();
			break;

			case 2 :
			floyd();
			break;

			case 3 :
			display();
			break;
		}
	}while(choice!=4);
}

void add()
{
	++x;
	cost[x][x]=0;
	 min[x][x]=0;

	for(int i=1;i<x;i++)
	{
		cout<<"\n    Enter the cost from vertex "<<i<<" to "<<x<<" : ";
		cin>>cost[i][x]; min[i][x]=cost[i][x];

		cout<<"\n    Enter the cost from vertex "<<x<<" to "<<i<<" : ";
		cin>>cost[x][i]; min[x][i]=cost[x][i];
	}
}

void floyd()
{
	for(int k=1;k<=x;k++)
	for(int i=1;i<=x;i++)
	for(int j=1;j<=x;j++)
	{
		if(cost[i][j]<(cost[i][k]+cost[k][j]))
		min[i][j]=cost[i][j];

		if(cost[i][j]>(cost[i][k]+cost[k][j]))
		min[i][j]=cost[i][k]+cost[k][j];
	}

	if(x!=0)
	{
		cout<<"\n    Minimum cost matrix : \n\n";
		for(int i=1;i<=x;i++)
		{
			for(int j=1;j<=x;j++)
			cout<<"    "<<min[i][j]<<"\t";
			cout<<"\n\n";
		}
	}
	else
	cout<<"\n    No solution! ";
	getch();
}

void display()
{
	if(x!=0)
	{
		cout<<"\n    Original cost matrix : \n\n";
		for(int i=1;i<=x;i++)
		{
			for(int j=1;j<=x;j++)
			cout<<"    "<<cost[i][j]<<"\t";
			cout<<"\n\n";
		}
	}
	else
	cout<<"\n    No solution! ";
	getch();
}