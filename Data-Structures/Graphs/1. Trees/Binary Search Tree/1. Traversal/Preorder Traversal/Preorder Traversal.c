#include<stdio.h>
#include<stdlib.h>

//Binary-Tree Structure.
struct vertex
{
    int value;
    struct vertex *left;
    struct vertex *right;
}*root=NULL;
typedef struct vertex vertex;

//Linked-Stack Structure.
struct node
{
    vertex *value;
    struct node *next;
}*top=NULL;
typedef struct node node;

//Function Declarations.
void add();
void find(vertex**,vertex*);
void push(vertex*);
vertex* pop();
void iterative();
void recursive(vertex*);

void main()
{
    int ch,value;
    do
    {
        system("cls");
        printf("\n 1. Add Node ");
        printf("\n 2. Iterative Preorder ");
        printf("\n 3. Recursive Preorder ");
        printf("\n 4. End Program ");
        printf("\n\n Enter>>");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1 :
                printf("\n Enter a value : ");
                scanf("%d",&value);
                add(value);
                break;
            case 2 :
                printf("\n Binary tree is : ");
                iterative();
                getch();
                break;
            case 3 :
                printf("\n Binary tree is :");
                recursive(root);
                getch();
                break;
        }
    }while(ch!=4);
}

void add(int value)
{
    vertex *x,*ptr=root;
    x=(vertex*)malloc(sizeof(vertex));
    x->value=value;
    x->left=NULL;
    x->right=NULL;
    find(&root,x);
}

void find(vertex **ptr,vertex *x)
{
    if(*ptr==NULL) *ptr=x;
    else if((*ptr)->value>x->value)
        find(&(*ptr)->left,x);
    else if((*ptr)->value<x->value)
        find(&(*ptr)->right,x);
    else return;
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
    vertex *x;
    if(root==NULL) printf("Empty!");
    else
    {
        push(root);
        while(top!=NULL)
        {
            x=pop();
            printf("%d ",x->value);
            if(x->right!=NULL) push(x->right);
            if(x->left!=NULL) push(x->left);
        }
    }
    getch();
}

void recursive(vertex *x)
{
    if(root==NULL) printf("Empty!");
    else
    {
        printf("%d ",x->value);
        if(x->left!=NULL)  recursive(x->left);
        if(x->right!=NULL) recursive(x->right);
    }
}
