#include<iostream>
#include<stdlib.h>
#include<conio.h>

using namespace std;

int cost[10][10],dist[10],x=0;

void add();
void dijkstra();
void display();

 main()
{
	int choice;
	do
	{
		system("cls");
		cout<<"\n MENU :- \n";
		cout<<"\n 1. Add Node \n";
		cout<<"\n 2. Shortest Path \n";
		cout<<"\n 3. Display \n";
		cout<<"\n 4. Exit \n";
		cout<<"\n Enter your choice : ";
		cin>>choice;
		switch(choice)
		{
			case 1 :
			add();
			display(); system("pause");
			break;

			case 2 :
			dijkstra();
			break;

			case 3 :
			display(); system("pause");
			break;
		}
	}while(choice!=4);
}

void add()
{
	++x;
	cost[x][x]=0;

	for(int i=1;i<x;i++)
	{
		cout<<"\n Enter the cost from node "<<i<<" to "<<x<<" : ";
		cin>>cost[i][x];

		cout<<"\n Enter the cost from node "<<x<<" to "<<i<<" : ";
		cin>>cost[x][i];
	}
}

void dijkstra()
{
	int visited[10],min,u,source;

	cout<<"\n Enter the source node : ";
	cin>>source;

	for(int i=1;i<=x;i++)
	{
		dist[i]=cost[source][i];
		visited[i]=0;
	}

	visited[source]=1;

	for(int i=1;i<=x;i++)
	{
		min=999;

		for(int j=1;j<=x;j++)
		if(visited[j]==0&&dist[j]<min)
		{
			min=dist[j];
			u=j;
		}

		visited[u]=1;

		for(int j=1;j<=x;j++)
		if(visited[j]==0&&dist[u]+cost[u][j]<dist[j])
		dist[j]=dist[u]+cost[u][j];
	}

	display();

	for(int i=1;i<=x;i++)
	cout<<"\n Shortest dist from "<<source<<" to "<<i<<" is "<<dist[i]<<endl;

	system("pause");
}

void display()
{
	if(x!=-1)
	{
		cout<<"\n Cost matrix : \n\n";
		for(int i=1;i<=x;i++)
		{
			for(int j=1;j<=x;j++)
			cout<<" "<<cost[i][j]<<"\t";
			cout<<"\n\n";
		}
	}
	else
	cout<<"\n No solution! ";
}
