#include<stdio.h>
#include<conio.h>

int array[5],size=5,x=-1;

void add();
void binary();
void display();

int main()
{
	int choice;
	do
	{
		system("cls");
		printf("\n MENU :            \n");
		printf("\n 1. Add            \n");
		printf("\n 2. Binary Search  \n");
		printf("\n 3. Display        \n");
		printf("\n 4. Exit           \n");
		printf("\n Enter your choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1 : add();		    break;

			case 2 : binary();    break;

			case 3 : display();		break;
		}
	}while(choice!=4);
}

void add()
{
    if(x<size-1)
	{
	    int temp;
		printf("\n Enter the value : ");
		scanf("%d",&temp);

		if(temp<=array[x])
		{
			printf("\n Violation of precondition! \n");
			getch();
		}
		else array[++x]=temp;
	}
	else
	{
		printf("\n Array is full!");
		getch();
	}
}

void binary()
{
	if(x!=-1)
	{
	    int value,low=0,high=x,mid;

		printf("\n Enter the value to be searched : ");
		scanf("%d",&value);

		while(low<high)
		{
			mid=(low+high)/2;

			if(array[mid]==value)
            {
                printf("\n Element found at position %d",mid+1);
                break;
            }

			else if(array[mid]<value)
                low=mid;

			else if(array[mid]>value)
                high=mid;
		}
	}
	else printf("\n Array is empty!");
	getch();
}

void display()
{
	if(x!=-1)
	{
	    int i;
		printf("\n Array is : ");
		for(i=0;i<=x;i++)
            printf("%d ",array[i]);
	}
	else printf("\n Array is empty!");
	getch();
}
