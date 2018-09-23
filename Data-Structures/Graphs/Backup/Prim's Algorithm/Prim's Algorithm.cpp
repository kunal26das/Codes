#include<iostream>
#include<stdlib.h>
#include<conio.h>

using namespace std;

struct node
{
	int fr,to,cost;
}p[6];

int n,c=0,temp1=0,temp=0;

void prims(int *a,int b[10][10],int i,int j)
{
	a[i]=1;
	while(c<n-1)
	{
		int min=999;
		for(int i=0;i<n;i++) if(a[i])
        for(int j=0;j<n;)
        {
            if(b[i][j]>=min||b[i][j]==0)
            j++;
            else if(b[i][j]<min)
            {
                min=b[i][j];
                temp=i;
                temp1=j;
            }
        }
		a[temp1]=1;
		p[c].fr=temp;
		p[c].to=temp1;
		p[c].cost=min;
		c++;
		b[temp][temp1]=b[temp1][temp]=1000;
	}
	for (int k=0;k<6;k++)
	{
		cout<<"\n Source node	   : "<<p[k].fr;
		cout<<"\n Destination node : "<<p[k].to;
		cout<<"\n Weight of node   : "<<p[k].cost;
		cout<<endl;
	}
}

int main()
{
	system("cls");

	int a[10],b[10][10];

	cout<<"\n Enter the no. of vertices : ";
	cin>>n;

	system("cls");

	for(int i=0;i<n;i++)
	a[i]=0;

	for(int i=0;i<n;i++)
	{
		cout<<"\n Enter values for "<<i+1<<" row : ";
		for(int j=0;j<n;j++)
		{
			cout<<"\n ";
			cin>>b[i][j];
		}
		system("cls");
	}

	prims(a,b,0,0);
	system("pause");
	return 1;
}
