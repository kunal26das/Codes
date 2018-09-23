#include<iostream>
#include<conio.h>

using namespace std;

int main()
{
	char ch;
	cout<<"\n Enter a character : ";
	ch=getche();

	if(ch>=48&&ch<=57)
	 cout<<"\n\n '"<<ch<<"' is a numeral digit. \n";
	else if(ch>=65&&ch<=90)
	 cout<<"\n\n '"<<ch<<"' is an uppercase alphabet. \n";
	else if(ch>=97&&ch<=122)
	 cout<<"\n\n '"<<ch<<"' is a lowercase alphabet. \n";
	else
	 cout<<"\n\n '"<<ch<<"' is a special character. \n";
	getch();
}
