#include<iostream>
#include<stdlib.h>

using namespace std;

class binary
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

    vertex* insert(vertex *ptr,vertex *x)
    {
        if(!ptr) return x;
        else if(ptr->value>x->value)
        ptr->left=insert(ptr->left,x);
        else if(ptr->value<x->value)
        ptr->right=insert(ptr->right,x);
        return ptr;
    }

    int height(vertex *ptr,int h=0)
    {
        if(!ptr) return h-1;
        int left=height(ptr->left,h+1);
        int right=height(ptr->right,h+1);
        return left>right?left:right;
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

    binary(){root=NULL;}

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
        root=insert(root,x);
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
    binary tree;
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
