#include<iostream.h>
#include<conio.h>

void main()
{
	clrscr();
	float a,b,c;
	char ch;
	cout<<"\n Enter first number  : ";
	cin>>a;
	cout<<"\n Enter second number : ";
	cin>>b;
	cout<<"\n Enter the operator  : ";
	cin>>ch;
	switch(ch)
	{
		case '+': c=a+b;
		cout<<"\n "<<a<<" + "<<b<<" = "<<c;
		break;

		case '-': c=a-b;
		cout<<"\n "<<a<<" - "<<b<<" = "<<c;
		break;

		case '*': c=a*b;
		cout<<"\n "<<a<<" x "<<b<<" = "<<c;
		break;

		case '/': c=a/b;
		cout<<"\n "<<a<<" / "<<b<<" = "<<c;
		break;

		default: cout<<"\n Error!";
		break;
	}
	getch();
}

