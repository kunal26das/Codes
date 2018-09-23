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
        vertex *parent;
        vertex(int _value)
        {
            left=NULL;
            right=NULL;
            parent=NULL;
            value=_value;
        }
    }*root;

    int height(vertex *ptr,int h)
    {
        if(!ptr) return h-1;
        int left=height(ptr->left,h+1);
        int right=height(ptr->right,h+1);
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

    vertex* insert(vertex *ptr,vertex *x)
    {
        if(!ptr) return x;
        else if(ptr->value>x->value)
        {
            ptr->left=insert(ptr->left,x);
            ptr->left->parent=ptr;
        }
        else if(ptr->value<x->value)
        {
            ptr->right=insert(ptr->right,x);
            ptr->right->parent=ptr;
        }
        return ptr;
    }

    vertex* balance(vertex *ptr)
    {
        vertex *save;
        int value=ptr->value;
        while(ptr)
        {
            save=ptr;
            if(!balanced(ptr))
            {
                int left=height(ptr->left,0)+1;
                int right=height(ptr->right,0)+1;
                if(left>right)
                {
                    if(value>ptr->left->value)
                    ptr->left=leftrotate(ptr->left);
                    if(ptr->parent)
                    {
                        if(ptr->parent->left==ptr)
                            ptr->parent->left=rightrotate(ptr);
                        else ptr->parent->right=rightrotate(ptr);
                    }
                    else return rightrotate(ptr);
                }
                if(left<right)
                {
                    if(value<ptr->right->value)
                    ptr->right=rightrotate(ptr->right);
                    if(ptr->parent)
                    {
                        if(ptr->parent->left==ptr)
                            ptr->parent->left=leftrotate(ptr);
                        else ptr->parent->right=leftrotate(ptr);
                    }
                    else return leftrotate(ptr);
                }
            }
            else ptr=ptr->parent;
        }
        return save;
    }

    vertex* leftrotate(vertex *ptr)
    {
        vertex *r=ptr->right;
        vertex *rl=r->left;
        r->parent=ptr->parent;
        r->left=ptr;
        ptr->right=rl;
        ptr->parent=r;
        return r;
    }

    vertex* rightrotate(vertex *ptr)
    {
        vertex *l=ptr->left;
        vertex *lr=l->right;
        l->parent=ptr->parent;
        l->right=ptr;
        ptr->left=lr;
        ptr->parent=l;
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
        vertex *x=new vertex(value);
        root=insert(root,x);
        root=balance(x);
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
