#include<iostream>
#include<stdlib.h>
#include<conio.h>

using namespace std;

class vertex
{
    public:
    int value;
    vertex *up;
    vertex *left;
    vertex *right;
    vertex()
    {
        up=NULL;
        left=NULL;
        right=NULL;
    }
};

class binary
{
    void place(vertex **ptr,vertex *x)
    {
        if(*ptr==NULL)
        {
            *ptr=x;
            x->up=*ptr;
        }
        else if((*ptr)->value>x->value)
        place(&(*ptr)->left,x);
        else if((*ptr)->value<x->value)
        place(&(*ptr)->right,x);
        else return;
    }
    public:
    vertex *root;
    binary(){root=NULL;}
    void insert(int value)
    {
        vertex *x=new vertex;
        x->value=value;
        place(&root,x);
    }
    int height(vertex *ptr,int h=0)
    {
        if(!ptr->left&&!ptr->right) return h;
        else if(ptr->left&&!ptr->right)
            height(ptr->left,h+1);
        else if(!ptr->left&&ptr->right)
            height(ptr->right,h+1);
        else if(ptr->left&&ptr->right)
        {
            int left=height(ptr->left,h+1);
            int right=height(ptr->right,h+1);
            return left>right?left:right;
        }
        else return -1;
    }
    void recursive(vertex *ptr,int lvl)
    {
        if(!ptr) return;
        if(!lvl) cout<<ptr->value<<", ";
        else
        {
            recursive(ptr->left,lvl-1);
            recursive(ptr->right,lvl-1);
        }
    }
};

int main()
{
    binary tree;
}
