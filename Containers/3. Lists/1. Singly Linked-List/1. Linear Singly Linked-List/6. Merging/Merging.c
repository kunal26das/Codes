#include<stdio.h>
#include<stdlib.h>

struct node
{
    int value;
    struct node *next;
}*f1=NULL,*l1=NULL,*f2=NULL,*l2=NULL;
typedef struct node node;

node* add();
void display(node *ptr);

void main()
{
    int ch;
    node *x;
    do
    {
        system("cls");
        printf("\n 1. List 1  ");
        printf("\n 2. List 2  ");
        printf("\n 3. Merge   ");
        printf("\n 4. Display ");
        printf("\n 5. Exit    ");
        printf("\n\n Enter>>");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1 :
                x=add();
                if(f1==NULL) f1=x;
                else l1->next=x;
                l1=x;
                break;
            case 2 :
                x=add();
                if(f2==NULL) f2=x;
                else l2->next=x;
                l2=x;
                break;
            case 3 :
                merge(f1,f2);

            case 4 :
                display(f1);
                break;
        }
    }while(ch!=5);
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

void display(node *ptr)
{
    printf("\n The list is : ");
    if(ptr==NULL) printf("Empty!");
    else while(ptr!=NULL)
    {
        printf("%d, ",ptr->value);
        ptr=ptr->next;
    }
    getch();
}
