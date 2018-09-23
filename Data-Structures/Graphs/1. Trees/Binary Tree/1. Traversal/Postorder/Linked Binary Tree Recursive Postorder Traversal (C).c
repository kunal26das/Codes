#include<stdlib.h>
#include<stdio.h>
#include<conio.h>

struct vertex
{
    int value;
    struct vertex *left;
    struct vertex *right;
};
typedef struct vertex vertex;

struct binary{vertex *root;};
typedef struct binary binary;

int exists(binary tree)
{
    if(tree.root)
    return 1;
    return 0;
}

int insert(vertex *ptr,int level,int value)
{
    if(!ptr) return 2;
    if(!level) return 0;
    else
    {
        int flag=insert(ptr->left,level-1,value);
        if(flag==2)
        {
            ptr->left=(vertex*)malloc(sizeof(vertex));
            ptr->left->value=value;
            ptr->left->left=NULL;
            ptr->left->right=NULL;
            return 1;
        }
        else if(flag) return 1;
        else if(!flag)
        {
            flag=insert(ptr->right,level-1,value);
            if(flag==2)
            {
                ptr->right=(vertex*)malloc(sizeof(vertex));
                ptr->right->value=value;
                ptr->right->left=NULL;
                ptr->right->right=NULL;
                return 1;
            }
            else return flag;
        }
    }
}

int height(vertex *ptr,int h)
{
    int left=h,right=h;
    if(ptr->left) left=height(ptr->left,h+1);
    if(ptr->right) right=height(ptr->right,h+1);
    return left>right?left:right;
}

void postorder(vertex *ptr)
{
    if(!ptr) return;
    else
    {
        postorder(ptr->left);
        postorder(ptr->right);
        printf("%d, ",ptr->value);
    }
}

void kill(vertex *ptr,int level)
{
    if(!ptr) return;
    if(!level) free(ptr);
    else
    {
        kill(ptr->left,level-1);
        ptr->left=NULL;
        kill(ptr->right,level-1);
        ptr->right=NULL;
    }
}

int main()
{
    binary tree;
    tree.root=NULL;
    int ch,i,h,value;
    do
    {
        system("cls");
        printf("\n 1. Insert ");
        printf("\n 2. Height ");
        printf("\n 3. Postorder ");
        printf("\n 4. End Program ");
        printf("\n\n Enter>>");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1 :
            printf("\n Enter a value : ");
            scanf("%d",&value);
            if(tree.root)
            {
                h=height(tree.root,0);
                if(!insert(tree.root,h,value))
                insert(tree.root,h+1,value);
            }
            else
            {
                tree.root=(vertex*)malloc(sizeof(vertex));
                tree.root->value=value;
                tree.root->left=NULL;
                tree.root->right=NULL;
            }
            break;

            case 2 :
            printf("\n Tree is "); if(exists(tree))
            printf("of height %d",height(tree.root,0));
            else printf("empty!");
            getch();
            break;

            case 3 :
            printf("\n Tree is : ");
            if(exists(tree))
            postorder(tree.root);
            else printf("empty!");
            getch();
            break;

            case 0 :
            if(exists(tree))
            {
                h=height(tree.root,0);
                for(i=h;i>=0;i--)
                kill(tree.root,i);
                tree.root=NULL;
            }
            break;
        }
    }while(ch!=4);
}
