#include<stdio.h>
#include<conio.h>

void main()
{
	char ch;
	printf("\n Enter a character : ");
	ch=getche();

	if(ch>=48&&ch<=57)
	 printf("\n\n '%c' is a numeral digit. \n",ch);
	else if(ch>=65&&ch<=90)
	 printf("\n\n '%c' is an uppercase alphabet. \n",ch);
	else if(ch>=97&&ch<=122)
	 printf("\n\n '%c' is a lowercase alphabet. \n",ch);
	else
	 printf("\n\n '%c' is a special character. \n",ch);
	getch();
}
