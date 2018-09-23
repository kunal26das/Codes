#include<iostream.h>
#include<conio.h>
#include<string.h>
void main()
{
	clrscr();
	char s1[50],s2[50],s3[100];
	int i,j,k;

	cout<<"\n Enter first string  : ";
	cin.getline(s1,50);

	for(i=0;s1[i]!='\0';i++)
	s3[i]=s1[i];

	cout<<"\n Enter second string : ";
	cin.getline(s2,50);

	for(j=0;s2[j]!='\0';j++)
	s3[i+j]=s2[j];

	s3[i+j]='\0';
	k=strlen(s3);

	cout<<"\n Concatinated string : ";
	for(i=0;i<k;i++)
	cout<<s3[i];

	getch();
	return;
}