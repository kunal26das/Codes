#include<iostream.h>
#include<conio.h>
void main()
{
	start:
	clrscr();
	int x;
	char ch;
	cout<<"\n Enter the number for the required table : ";
	cin>>x;
	for(int i=1;i<=10;i++)
	cout<<"\n "<<x<<" x "<<i<<" = "<<x*i<<endl;
	cout<<"\n Try again? : ";
	cin>>ch;
	if(ch=='Y'||ch=='y')
	goto start;
	return;
}

