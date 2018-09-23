#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
void main()
{
	clrscr();
	char s1[50],s2[50];
	int  length,pos,count;

	delete s2;

	cout<<"\n Enter the main string   : ";
	gets(s1);

	length=strlen(s1);

	cout<<"\n Enter the position      : ";
	cin>>pos;
	pos=pos-1;

	if(pos<0||pos>length)
	{
		cout<<"\n Error!";
		getch();
		return;
	}

	cout<<"\n Enter no. of characters : ";
	cin>>count;

	if((pos+count-1)>length)
	{
		cout<<"\n Error!";
		getch();
		return;
	}

	for(int i=pos,j=0;i<(pos+count);i++,j++)
	s2[j]=s1[i];

	cout<<"\n Extracted substring is  : ";
	puts(s2);

	getch();
}