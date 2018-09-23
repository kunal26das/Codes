#include<iostream.h>
#include<conio.h>
float square(float a)
{
	return(a*a);
}
void main()
{
	clrscr();
	float a,x;
	cout<<"\n Enter a number : ";
	cin>>a;
	x=square(a);
	cout<<"\n Square of "<<a<<" is : "<<x;
	getch();
	return;
}
