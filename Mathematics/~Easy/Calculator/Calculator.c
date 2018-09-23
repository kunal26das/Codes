#include<stdio.h>
#include<conio.h>

void main()
{
	float a,b,c;
	char ch;
	clrscr();
	printf("\n Enter first number  : ");
	scanf("%f",&a);
	printf("\n Enter second number : ");
	scanf("%f",&b);
	printf("\n Enter the operator  : ");
	scanf("%s",&ch);
	switch(ch)
	{
		case '+': c=a+b;
		printf("\n %.1f + %.1f = %.1f",a,b,c);
		break;

		case '-': c=a-b;
		printf("\n %.1f - %.1f = %.1f",a,b,c);
		break;

		case '*': c=a*b;
		printf("\n %.1f * %.1f = %.1f",a,b,c);
		break;

		case '/': c=a/b;
		printf("\n %.1f / %.1f = %.1f",a,b,c);
		break;

		default: printf("\n Error!");
		break;
	}
	getch();
}

