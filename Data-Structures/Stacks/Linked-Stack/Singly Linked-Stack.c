#include<stdio.h>
#include<stdlib.h>

struct node
{
    int value;
    struct node *next;
};
typedef struct node node;
typedef node* stack;

void push(node**,int);
int  pop(node**);
void display(node*);

void main()
{
    stack stk=NULL;
    int value,ch;
    do
    {
        system("cls");
        printf("\n 1. Push    ");
        printf("\n 2. Pop     ");
        printf("\n 3. Display ");
        printf("\n 4. Exit    ");
        printf("\n\n Enter>>");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1 :
            printf("\n Enter a value : ");
            scanf("%d",&value);
            push(&stk,value);
            break;

            case 2 :
            if(!underflow(stk))
            printf("\n Popped value : %d",pop(&stk));
            else printf("\n Stack is underflowing! ");
            getch();
            break;

            case 3 :
            printf("\n Stack is : ");
            if(!underflow(stk))
            display(stk);
            else printf("empty!");
            getch();
            break;
        }
    }while(ch!=4);
}

void push(node **top,int value)
{
    node *x=(node*)malloc(sizeof(node));
    x->value=value;
    x->next=NULL;
    if(*top!=NULL)
    x->next=*top;
    *top=x;
}

int pop(node **top)
{
    int value=(*top)->value;
    node *temp=*top;
    *top=(*top)->next;
    free(temp);
    return value;
}

int underflow(node *top)
{
    if(top==NULL)
    return 1;
    return 0;
}

void display(node *ptr)
{
    while(ptr!=NULL)
    {
        printf("\n %d",ptr->value);
        ptr=ptr->next;
    }
}
