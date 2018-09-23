#include<iostream>
#include<stdlib.h>
#include<conio.h>

using namespace std;

class vertex
{
    public:
    int key;
    vertex *left;
    vertex *right;
    vertex(int k)
    {
        key=k;
        left=NULL;
        right=NULL;
    }
};

class AVL
{
    vertex *root;
    void place(vertex **ptr,vertex *x)
    {
        if(!(*ptr)) *ptr=x;
        else if((*ptr)->key>x->key)
        place(&(*ptr)->left,x);
        else if((*ptr)->key<x->key)
        place(&(*ptr)->right,x);
    }
    int height(vertex *ptr,int h)
    {
        int left=h,right=h;
        if(ptr->left) left=height(ptr->left,h+1);
        if(ptr->right) right=height(ptr->right,h+1);
        return left>right?left:right;
    }
    void levelorder(vertex *ptr,int level)
    {
        if(!ptr) return;
        if(!level) cout<<ptr->key<<", ";
        else
        {
            levelorder(ptr->left,level-1);
            levelorder(ptr->right,level-1);
        }
    }
    public:
    AVL(){root=NULL;}
    int exists()
    {
        if(root)
        return 1;
        return 0;
    }
    void insert(int key)
    {
        vertex *x;
        x=new vertex(key);
        place(&root,x);
    }
    int height()
    {return height(root,0);}
    void levelorder()
    {
        int h=height(root,0);
        for(int i=0;i<=h;i++)
        {
            levelorder(root,i);
            cout<<" ";
        }
    }
};

int main()
{
    AVL tree;
    int ch,value;
    do
    {
        system("cls");
        cout<<"\n 1. Insert ";
        cout<<"\n 2. Height ";
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
            cout<<"\n Tree is ";
            if(tree.exists())
            cout<<"of height "<<tree.height();
            else cout<<"empty!";
            getch();
            break;

            case 3 :
            cout<<"\n The tree is : ";
            if(tree.exists())
            tree.levelorder();
            else cout<<"empty!";
            getch();
            break;
        }
    }while(ch!=4);
}
