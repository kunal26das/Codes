#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
void main()
{
	clrscr();
	char string[18];
	int i,j,flag=1,length;

	cout<<"\n Enter the string : ";
	gets(string);
	length=strlen(string);

	for(i=0,j=length-1;i<length/2;i++,j--)
	if(string[i]!=string[j])
	flag=0;

	if(flag==1)
	cout<<"\n The given string is palindrome";

	else
	cout<<"\n The given string is not palindrome";

	getch();
	return;
}