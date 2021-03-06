#include<stdio.h>
#include<stdlib.h>

//Binary-Tree Structure.

typedef struct
{
    int value;
    struct vertex *left;
    struct vertex *right;
}vertex;

vertex *root=NULL;

//Linked-Stack Structure.

typedef struct
{
    vertex *value;
    struct node *next;
}node;

node *top=NULL;

//Function Declarations.

void add();
void push(vertex*);
vertex* pop();
void iterative();
void recursive(vertex*);

void main()
{
    int ch;
    do
    {
        system("cls");
        printf("\n MENU :- \n");
        printf("\n 1. Add Node ");
        printf("\n 2. Iterative Postorder ");
        printf("\n 3. Recursive Postorder ");
        printf("\n 4. End Program ");
        printf("\n\n Enter your choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1 : add(); break;
            case 2 : iterative(); break;
            case 3 :
                printf("\n Binary tree is : ");
                recursive(root);
                getch();
                break;
        }
    }while(ch!=4);
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

void push(vertex *ptr)
{
    node *x;
    x=(node*)malloc(sizeof(node));
    x->value=ptr;
    x->next=NULL;
    if(top==NULL) top=x;
    else x->next=top;
    top=x;
}

vertex* pop()
{
    vertex *ptr=top->value;
    node *x=top;
    top=top->next;
    free(x);
    return ptr;
}

void iterative()
{
    vertex *x=root;
    printf("\n Binary tree is :");
    if(root==NULL) printf(" Empty! ");
    else do
    {
        while(x!=NULL)
        {
            if(x->right!=NULL) push(x->right);
            push(x);
            x=x->left;
        }
        x=pop();
        if(x->right!=NULL && top!=NULL && top->value==x->right)
        {
            pop();
            push(x);
            x=x->right;
        }
        else
        {
            printf(" %d",x->value);
            x=NULL;
        }
    }while(top!=NULL);
    getch();
}

void recursive(vertex *x)
{
    if(root==NULL) printf("Empty!");
    else
    {
        if(x->left!=NULL)  recursive(x->left);
        if(x->right!=NULL) recursive(x->right);
        printf("%d ",x->value);
    }
}
