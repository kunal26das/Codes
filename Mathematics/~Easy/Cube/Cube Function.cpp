#include<iostream.h>
#include<conio.h>
float cube(float a)
{
	return(a*a*a);
}
void main()
{
	clrscr();
	float a,x;
	cout<<"\n Enter a number : ";
	cin>>a;
	x=cube(a);
	cout<<"\n Cube of "<<a<<" is : "<<x;
	getch();
	return;
}
