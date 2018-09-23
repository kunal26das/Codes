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
    vertex()
    {
        left=NULL;
        right=NULL;
    }
};

class binary
{
    void place(vertex **ptr,vertex *x)
    {
        if(*ptr==NULL) *ptr=x;
        else if((*ptr)->value>x->value)
        place(&(*ptr)->left,x);
        else if((*ptr)->value<x->value)
        place(&(*ptr)->right,x);
        else return;
    }
    public:
    vertex *root;
    binary(){root=NULL;}
    int exists()
    {
        if(root)
        return 1;
        return 0;
    }
    void insert(int value)
    {
        vertex *ptr=root;
        vertex *x=new vertex;
        x->value=value;
        place(&root,x);
    }
    int small()
    {
        vertex *ptr=root;
        while(ptr->left) ptr=ptr->left;
        return ptr->value;
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
    void lorder(vertex *ptr,int lvl)
    {
        if(!ptr) return;
        if(!lvl) cout<<ptr->value<<", ";
        else
        {
            lorder(ptr->left,lvl-1);
            lorder(ptr->right,lvl-1);
        }
    }
};

int main()
{
    binary tree;
    vertex *temp;
    int i,h,value,ch;
    do
    {
        system("cls");
        cout<<"\n 1. Insert ";
        cout<<"\n 2. Smallest ";
        cout<<"\n 3. Level-Order ";
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
            if(tree.exists())
            cout<<"\n Smallest element is : "<<tree.small();
            else cout<<"\n Tree is empty! ";
            getch();
            break;

            case 3 :
            cout<<"\n The tree is : ";
            if(tree.exists())
            {
                h=tree.height(tree.root);
                for(i=0;i<=h;i++)
                tree.lorder(tree.root,i);
            }
            else cout<<"empty!";
            getch();
            break;
        }
    }while(ch!=4);
}
