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
    vertex(int v)
    {
        value=v;
        left=NULL;
        right=NULL;
    }
};

class AVL
{
    vertex *root;
    int height(vertex *ptr,int h)
    {
        int left=h,right=h;
        if(!ptr) return h-1;
        left=height(ptr->left,h+1);
        right=height(ptr->right,h+1);
        return left>right?left:right;
    }
    int balanced(vertex *ptr)
    {
        int left=height(ptr->left,0)+1;
        int right=height(ptr->right,0)+1;
        if(left>right&&(left-right)>1) return 0;
        if(left<right&&(right-left)>1) return 0;
        return 1;
    }
    void insert(vertex **ptr,vertex *x)
    {
        if(!(*ptr)) *ptr=x;
        else if((*ptr)->value>x->value)
        insert(&(*ptr)->left,x);
        else if((*ptr)->value<x->value)
        insert(&(*ptr)->right,x);
        if(!balanced(*ptr))
        (*ptr)=balance((*ptr),x->value);
    }
    vertex* balance(vertex *ptr,int value)
    {
        int left=height(ptr->left,0)+1;
        int right=height(ptr->right,0)+1;
        if(left>right)
        {
            if(value>ptr->left->value)
            ptr->left=leftrotate(ptr->left);
            return rightrotate(ptr);
        }
        if(left<right)
        {
            if(value<ptr->right->value)
            ptr->right=rightrotate(ptr->right);
            return leftrotate(ptr);
        }
    }
    vertex* leftrotate(vertex *ptr)
    {
        vertex *r=ptr->right;
        vertex *rl=r->left;
        ptr->right=rl;
        r->left=ptr;
        return r;
    }
    vertex* rightrotate(vertex *ptr)
    {
        vertex *l=ptr->left;
        vertex *lr=l->right;
        ptr->left=lr;
        l->right=ptr;
        return l;
    }
    void levelorder(vertex *ptr,int level)
    {
        if(!ptr) return;
        if(!level) cout<<ptr->value<<", ";
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
    void insert(int value)
    {
        vertex *x;
        x=new vertex(value);
        insert(&root,x);
    }
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

class hash
{
    int size;
    AVL *tree;
    public:
    hash(int s)
    {
        size=s;
        tree=new AVL[s];
    }
    void insert(int value)
    {tree[value%size].insert(value);}
    void display()
    {
        for(int i=0;i<size;i++)
        {
            cout<<"\n "<<i<<" : ";
            if(tree[i].exists())
            tree[i].levelorder();
            cout<<endl;
        }
    }
};

int main()
{
    int ch,value;
    hash table(10);
    do
    {
        system("cls");
        cout<<"\n 1. Insert ";
        cout<<"\n 2. Display ";
        cout<<"\n 3. End Program ";
        cout<<"\n\n Enter>>";
        cin>>ch; switch(ch)
        {
            case 1 :
            cout<<"\n Enter a value : ";
            cin>>value; table.insert(value);
            break;

            case 2 :
            cout<<"\n Hash table is : \n";
            table.display(); getch();
            break;
        }
    }while(ch!=3);
}
