#include<stdio.h>

struct node
{
    int value;
    struct node *next;
};typedef struct node node;

node* createnode(int value)
{
    node *x=(node*)malloc(sizeof(node));
    x->value=value; x->next=NULL;
    return x;
}

struct list{node *head;};
typedef struct list list;

int empty(list lst)
{
    if(lst.head==NULL)
    return 1;
    return 0;
}

void append(list lst,int value)
{
    node *x=createnode(value);
    if(lst.head)
    {
        node *ptr=lst.head;
        while(ptr->next!=lst.head)
        ptr=ptr->next; ptr->next=x;
    }
    else lst.head=x;
    x->next=lst.head;
}

void forward(list lst)
{
    node *ptr=lst.head;
    do
    {
        printf("%d, ",ptr->value);
        ptr=ptr->next;
    }while(ptr!=lst.head);
}

void backward(list lst)
{
    node *ptr=lst.head;
    node *mark=lst.head;
    while(lst.head->next!=mark)
    {
        while(ptr->next!=mark)
        ptr=ptr->next;
        printf("%d, ",ptr->value);
        mark=ptr; ptr=lst.head;
    }
    if(lst.head) printf("%d",lst.head->value);
}

void main()
{
    list lst;
    int ch,value;
    do
    {
        system("cls");
        printf("\n 1. Add ");
        printf("\n 2. Backward ");
        printf("\n 3. Forward ");
        printf("\n 4. Exit ");
        printf("\n\n Enter>>");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            printf("\n Enter a value : ");
            scanf("%d",&value);
            append(lst,value);
            break;

            case 2:
            printf("\n The list is : ");
            if(!empty(lst)) backward(lst);
            else printf("empty!");
            printf("\n ");
            system("pause");
            break;

            case 3:
            printf("\n The list is : ");
            if(!empty(lst)) forward(lst);
            else printf("empty!");
            printf("\n ");
            system("pause");
            break;
        }
    }while(ch!=4);
}
