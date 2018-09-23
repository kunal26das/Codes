#include<iostream.h>
#include<conio.h>
#include<math.h>
void main()
{
	clrscr();
	float a,b,c,r1,r2,d;

	cout<<"\n (a)x^2 + (b)x + c = 0 \n";

	cout<<"\n Enter the value of coefficient 'a' : ";
	cin>>a;

	cout<<"\n Enter the value of coefficient 'b' : ";
	cin>>b;

	cout<<"\n Enter the value of coefficient 'c' : ";
	cin>>c;

	cout<<"\n ("<<a<<")x^2 + ("<<b<<")x + ("<<c<<") = 0 \n";

	if(a==0)
	{
		cout<<"\n Invalid input for coefficient 'a'!";
		getch();
		return;
	}

	else
	{
		d=(b*b)-(4*a*c);
		if(d>0)
		{
			r1=(-b+sqrt(d))/(2*a);
			r2=(-b-sqrt(d))/(2*a);
			cout<<"\n Roots of the quadratic equation are : "<<r1<<" & "<<r2;
		}
		else if(d=0)
		{
			r1=r2=-b/(2*a);
			cout<<"\n "<<r1<<" is the only root of the quadratic equation";
		}
		else
		cout<<"\n Roots are complex and imaginary";
	}
	getch();
	return;
}