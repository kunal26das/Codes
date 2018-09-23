#include<stdio.h>

typedef struct
{
	int value;
	struct node *next;
}node;

node *front=NULL,*rear=NULL;

void enqueue();
void dequeue();
void display();

void main()
{
	int ch;
	do
	{
		system("cls");
		printf("\n MENU :- \n");
		printf("\n 1. Enqueue \n");
		printf("\n 2. Dequeue \n");
		printf("\n 3. Display \n");
		printf("\n 4. Exit \n");
		printf("\n Enter your choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:	enqueue(); break;
			case 2:	dequeue(); break;
			case 3:	display(); break;
		}
	}while(ch!=4);
}

void enqueue()
{
    node *x;
    x=(node*)malloc(sizeof(node));
	printf("\n Enqueue : ");
	scanf("%d",&x->value);
	x->next=NULL;
	if(front==NULL)	front=x;
	else rear->next=x;
	rear=x;
}

void dequeue()
{
	if(front!=NULL)
	{
	    node *x=front;
		printf("\n Dequeued value : %d",x->value);
		front=front->next;
	}
	else
	printf("\n Queue is underflowing!");
	getch();
}

void display()
{
	if(front!=NULL)
	{
		node *x=front;
		printf("\n The queue is : ");
		while(x!=NULL)
		{
			printf("%d, ",x->value);
			x=x->next;
		}
	}
	else
	printf("\n Queue is underflowing!");
	getch();
}
