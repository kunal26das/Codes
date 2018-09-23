#include<iostream.h>
#include<conio.h>
void main()
{
	int ch;
	float f,c;
	do
	{
		clrscr();
		cout<<"\n    Menu :- \n";
		cout<<"\n 1. Fahrenheir -> Celcius \n";
		cout<<"\n 2. Celcius -> Fahrenheit \n";
		cout<<"\n 3. Exit \n";
		cout<<"\n    Enter your choice : ";
		cin>>ch;
		switch(ch)
		{
			case 1 :
			cout<<"\n    Enter fahrenheit temperature : ";
			cin>>f;
			c=(f-32)/1.8;
			cout<<"\n    Celcius temperature : "<<c<<" degC";
			getch();
			break;

			case 2 :
			cout<<"\n    Enter celcius temperature : ";
			cin>>c;
			f=(c*1.8)+32;
			cout<<"\n    Fahrenheit temperature : "<<f<<" degF";
			getch();
			break;
		}
	}while(ch!=3);
}

