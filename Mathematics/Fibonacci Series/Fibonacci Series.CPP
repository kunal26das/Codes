#include<iostream.h>
#include<conio.h>
void main()
{
	clrscr();
	int a=0,b=1,c,n;
	cout<<"\n Enter the range : ";
	cin>>n;
	cout<<"\n "<<a<<" , "<<b;
	for(int i=2;i<n;i++)
	{
		c=a+b;
		cout<<" , "<<c;
		a=b;
		b=c;
	}
	cout<<" ...";
	getch();
	return;
}

