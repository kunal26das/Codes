#include<iostream>
#include<stdlib.h>
#include<conio.h>

using namespace std;

class vertex
{
    public:
    int value;
    vertex *left;
    vertex *right;
    vertex *parent;
    vertex(int v)
    {
        value=v;
        left=NULL;
        right=NULL;
        parent=NULL;
    }
};

class binary
{
    vertex *root;
    void insert(vertex **ptr,vertex *x)
    {
        if(*ptr==NULL) *ptr=x;
        else if((*ptr)->value>x->value)
        {
            x->parent=*ptr;
            insert(&(*ptr)->left,x);
        }
        else if((*ptr)->value<x->value)
        {
            x->parent=*ptr;
            insert(&(*ptr)->right,x);
        }
        else return;
    }
    public:
    binary(){root=NULL;}
    int exists()
    {
        if(root)
        return 1;
        return 0;
    }
    void insert(int value)
    {
        vertex *x=new vertex(value);
        insert(&root,x);
    }
    void preorder()
    {
        vertex *ptr=root;
        while(ptr)
        {
            while(ptr->left)
            {
                cout<<ptr->value;
                ptr=ptr->left;
            }
            ptr=ptr->parent;
            ptr=ptr->right;
        }
    }
};

int main()
{
    binary tree;
    int value,ch;
    do
    {
        system("cls");
        cout<<"\n 1. Insert ";
        cout<<"\n 2. Height ";
        cout<<"\n 3. Preorder ";
        cout<<"\n 4. End Program ";
        cout<<"\n\n Enter>>";
        cin>>ch;
        switch(ch)
        {
            case 1 :
            cout<<"\n Enter a value : ";
            cin>>value; tree.insert(value);
            break;

            case 2 :
            break;

            case 3 :
            cout<<"\n Tree is : ";
            if(tree.exists())
            tree.preorder();
            else cout<<"empty!";
            getch();
            break;
        }
    }while(ch!=4);
}
