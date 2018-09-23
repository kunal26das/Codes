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

//Function Declarations.

void add();
int  height(vertex*);
void iterative();
void recursive(vertex*,int);

void main()
{
    int i,h,ch;
    do
    {
        system("cls");
        printf("\n MENU :- \n");
        printf("\n 1. Add Node ");
        printf("\n 2. Iterative Level Order ");
        printf("\n 3. Recursive Level Order ");
        printf("\n 4. End Program ");
        printf("\n\n Enter your choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1 : add(); break;
            case 2 : iterative(); break;
            case 3 :
                printf("\n Binary tree is :");
                if(root==NULL) printf(" Empty!");
                h=height(root);
                for(i=0;i<=h;i++) recursive(root,i);
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

int height(vertex *x)
{
    if(x!=NULL)
    {
        int lheight=height(x->left);
        int rheight=height(x->right);
        if(lheight>=rheight)
            return lheight+1;
        else if(lheight<=rheight)
            return rheight+1;
    }
    else return -1;
}

void iterative()
{
    printf("\n Binary tree is :");
    if(root==NULL) printf(" Empty!");
    getch();
}

void recursive(vertex *x,int level)
{
    if(x==NULL) return;
    if(level==0) printf(" %d",x->value);
    else if(level>0)
    {
        recursive(x->left,level-1);
        recursive(x->right,level-1);
    }
}
