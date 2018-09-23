#include<iostream.h>
#include<conio.h>
#include<stdio.h>
void main()
{
	clrscr();
	char string[50];
	int x=0;
	cout<<"\n Enter a string : ";
	gets(string);
	for(int i=0;i<50;i++)
	{
		switch(string[i])
		{
			case 'a':
			case 'A':
			case 'e':
			case 'E':
			case 'i':
			case 'I':
			case 'o':
			case 'O':
			case 'u':
			case 'U':
			++x;
		}
	}
	cout<<"\n There are "<<x<<" vowels in the given string";
	getch();
	return;
}
