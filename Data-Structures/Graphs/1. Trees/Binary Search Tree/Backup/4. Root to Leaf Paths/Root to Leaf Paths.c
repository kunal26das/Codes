#include<stdio.h>
#include<stdlib.h>

struct vertex
{
    int value;
    struct vertex *left;
    struct vertex *right;
};

typedef struct vertex vertex;

vertex *root=NULL;

void add();
void paths(vertex*,int*,int);

void main()
{
    int array[0],ch;
    do
    {
        system("cls");
        printf("\n MENU :- \n");
        printf("\n 1. Add Node ");
        printf("\n 2. Display Paths ");
        printf("\n 3. End Program ");
        printf("\n\n Enter your choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1 : add(); break;
            case 2 :
                paths(root,array,0);
                getch();
                break;
        }
    }while(ch!=3);
}

void add()
{
    vertex *x;
    x=(vertex*)malloc(sizeof(vertex));
    printf("\n Enter a value : ");
    scanf("%d",&x->value);
    x->left=NULL;
    x->right=NULL;
    if(root==NULL) root=x;
    else
    {
        vertex *ptr=root;
        while(ptr!=NULL)
        {
            if(x->value==ptr->value)
            {
                free(x);
                break;
            }
            else if(x->value<ptr->value && ptr->left!=NULL) ptr=ptr->left;
            else if(x->value<ptr->value && ptr->left==NULL)
            {
                ptr->left=x;
                break;
            }
            else if(x->value>ptr->value && ptr->right!=NULL) ptr=ptr->right;
            else if(x->value>ptr->value && ptr->right==NULL)
            {
                ptr->right=x;
                break;
            }
        }
    }
}

void paths(vertex *x,int array[],int i)
{
    if(x==NULL) return;

    array[i]=x->value;
    i++;

    if(x->left==NULL && x->right==NULL)
    {
        int j;
        printf("\n ");
        for(j=0;j<i;j++)
            printf("%d->",array[j]);
        printf("NULL \n");
    }
    else
    {
        paths(x->left,array,i);
        paths(x->right,array,i);
    }
}
