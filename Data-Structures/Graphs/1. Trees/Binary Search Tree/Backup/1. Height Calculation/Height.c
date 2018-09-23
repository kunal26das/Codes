#include<stdio.h>
#include<stdlib.h>

typedef struct
{
    int value;
    struct vertex *left;
    struct vertex *right;
}vertex;

vertex *root=NULL;

void add();
int  height(vertex*);
int  search();

void main()
{
    int key,level,ch;
    do
    {
        system("cls");
        printf("\n MENU :- \n");
        printf("\n 1. Add ");
        printf("\n 2. Height ");
        printf("\n 3. Search ");
        printf("\n 0. Exit ");
        printf("\n\n Enter your choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1 :
                add();
                break;
            case 2 :
                printf("\n Height of binary tree is : %d",height(root));
                getch();
                break;
            case 3 :
                printf("\n Enter the value to search : ");
                scanf("%d",&key);
                level=search(key);
                if(level!=-1) printf("\n Value found at level %d",level);
                else printf("\n Value not found!");
                getch();
                break;
        }
    }while(ch!=0);
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

int search(int key)
{
    int flag=0,level=-1;
    vertex *x=root;
    while(x!=NULL)
    {
        level++;
        if(key==x->value)
        {
            flag=1;
            break;
        }
        else if(key<x->value) x=x->left;
        else if(key>x->value) x=x->right;
    }
    if(flag) return level;
    else return -1;
}
