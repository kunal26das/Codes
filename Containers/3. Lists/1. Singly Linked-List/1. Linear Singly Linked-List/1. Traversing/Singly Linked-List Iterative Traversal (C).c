#include<stdlib.h>
#include<stdio.h>

struct node
{
    int value;
    struct node *next;
};
typedef struct node node;

struct list
{
    node *first;
    node *last;
};
typedef struct list list;

void initlist(list *lst)
{
    (*lst).first=NULL;
    (*lst).last=NULL;
}

int empty(list lst)
{
    if(lst.first)
    return 0;
    return 1;
}

void append(list *lst,int value)
{
    node *x=(node*)malloc(sizeof(node));
    x->value=value; x->next=NULL;
    if((*lst).first) (*lst).last->next=x;
    else (*lst).first=x; (*lst).last=x;
}

void forward(list lst)
{
    node *ptr=lst.first;
    while(ptr)
    {
        printf("%d, ",ptr->value);
        ptr=ptr->next;
    }
}

void backward(list lst)
{
    node *temp,*ptr;
    node *mark=lst.last;
    while(mark!=lst.first)
    {
        temp=lst.first;
        ptr=temp->next;
        while(ptr!=mark)
        {
            temp=temp->next;
            ptr=temp->next;
        }
        mark=temp;
        printf("%d, ",ptr->value);
    }
    printf("%d",lst.first->value);
}

void destroy(node *ptr)
{
    if(!ptr) return;
    destroy(ptr->next);
    free(ptr);
}

void main()
{
    list lst;
    initlist(&lst);
    int ch,value;
    do
    {
        system("cls");
        printf("\n 1. Append ");
        printf("\n 2. Forward ");
        printf("\n 3. Backward ");
        printf("\n 4. End Program ");
        printf("\n\n Enter>>");
        scanf("%d",&ch); switch(ch)
        {
            case 1:
            printf("\n Enter a value : ");
            scanf("%d",&value);
            append(&lst,value);
            break;

            case 2:
            printf("\n List is : ");
            if(!empty(lst)) forward(lst);
            else printf("empty!");
            printf("\n "); system("pause");
            break;

            case 3:
            printf("\n List is : ");
            if(!empty(lst)) backward(lst);
            else printf("empty!");
            printf("\n "); system("pause");
            break;

            case 0 :
            if(lst.first)
            {
                destroy(lst.first);
                lst.first=NULL;
                lst.last=NULL;
            }
            break;
        }
    }while(ch!=4);
}
