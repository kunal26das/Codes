#include<iostream>
#include<stdlib.h>
#include<conio.h>

using namespace std;

void TOH(int,char,char,char);

int main()
{
	int n;
	cout<<"\n Enter no. of plates : ";
	cin>>n;
	TOH(n,'A','B','C');
	getch();
}

void TOH(int n,char x,char y,char z)
{
	if(n>0)
	{
		TOH(n-1,x,z,y);
		cout<<"\n Move disk "<<n<<" from "<<x<<" to "<<z<<endl;
		TOH(n-1,y,x,z);
	}
}
