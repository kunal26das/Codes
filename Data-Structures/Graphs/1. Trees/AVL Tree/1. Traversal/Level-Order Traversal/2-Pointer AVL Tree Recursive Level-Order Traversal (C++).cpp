#include<iostream>
#include<stdlib.h>

using namespace std;

class AVL
{
    class vertex
    {
        public:
        int value;
        vertex *left;
        vertex *right;
        vertex(int _value)
        {
            left=NULL;
            right=NULL;
            value=_value;
        }
    }*root;

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

    void kill(vertex *ptr,int level)
    {
        if(!ptr) return;
        if(!level) delete ptr;
        else
        {
            kill(ptr->left,level-1);
            ptr->left=NULL;
            kill(ptr->right,level-1);
            ptr->right=NULL;
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

    int height(){return height(root,0);}

    void levelorder()
    {
        int h=height(root,0);
        for(int i=0;i<=h;i++)
        {
            cout<<"\n Level "<<i<<" : ";
            levelorder(root,i); cout<<" ";
        }
        cout<<endl;
    }

    void kill()
    {
        if(!root) return;
        int h=height(root,0);
        for(int i=h;i>=0;i--)
        kill(root,i);
        root=NULL;
    }
};

int main()
{
    AVL tree;
    int ch,value;
    do
    {
        system("cls");
        if(tree.exists())
        tree.levelorder();
        cout<<"\n 1. Insert ";
        cout<<"\n 2. End Program ";
        cout<<"\n\n Enter>>";
        cin>>ch; switch(ch)
        {
            case 1 :
            cout<<"\n Enter a value : ";
            cin>>value; tree.insert(value);
            break;

            case 0 : tree.kill(); break;
        }
    }while(ch!=2);
}
