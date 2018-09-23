#include<iostream.h>
#include<conio.h>
#include<math.h>
void main()
{
	clrscr();
	int n,s;
	cout<<"\n For a regular polygon      : \n";
	cout<<"\n Enter the no. of sides     : ";
	cin>>n;
	if(n<3)
	{
		cout<<"\n Mathematical Error!";
		getch();
		return;
	}
	cout<<"\n Enter the length of a side : ";
	cin>>s;
	cout<<"\n Perimeter              = "<<(n*s)<<" units \n";
	cout<<"\n Area			 = ";
	cout<<"\n Internal angle         = "<<(n-2)*180/n<<" degrees \n";
	cout<<"\n External angle	 = ";
	cout<<"\n Sum of internal angles = "<<(n-2)*180<<" degrees \n";
	cout<<"\n Sum of external angles = ";
	getch();
}