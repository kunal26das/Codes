#include<stdio.h>
#include<stdlib.h>

struct node
{
    int value;
    struct node *next;
}*first=NULL,*last=NULL;
typedef struct node node;

node* add();
void insert(node*);
void display();

void main()
{
    node *x;
    int value,ch;
    do
    {
        system("cls");
        printf("\n 1. Add     ");
        printf("\n 2. Insert  ");
        printf("\n 3. Display ");
        printf("\n 4. Exit    ");
        printf("\n\n Enter>>");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1 :
                x=add();
                if(first==NULL) first=x;
                else last->next=x;
                last=x;
                break;
            case 2 :
                printf("\n Enter a value : ");
                scanf("%d",&value);
                insert(search(value));
                break;
            case 3 : display(); break;
        }
    }while(ch!=4);
}

node* add()
{
    node *x;
    x=(node*)malloc(sizeof(node));
    printf("\n Enter a value : ");
    scanf("%d",&x->value);
    x->next=NULL;
    return x;
}

void insert(node *ptr)
{
	if(ptr!=NULL)
	{
	    node *x=add();
	    if(ptr==last)
        {
            last->next=x;
            last=x;
        }
        else
        {
            x->next=ptr->next;
            ptr->next=x;
        }
        display();
	}
	else
	{
		printf("\n Insertion not possible!");
		getch();
	}
}

void display()
{
    node *ptr=first;
    printf("\n The list is : ");
    if(first==NULL) printf("Empty!");
    while(ptr!=NULL)
    {
        printf("%d, ",ptr->value);
        ptr=ptr->next;
    }
    getch();
}
