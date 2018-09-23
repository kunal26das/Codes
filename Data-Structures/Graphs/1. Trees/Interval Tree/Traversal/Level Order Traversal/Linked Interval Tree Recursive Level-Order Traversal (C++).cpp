#include<iostream>
#include<stdlib.h>

using namespace std;

class interval
{
    public:
    int low;
    int high;
    interval(int l,int h)
    {
        low=l;
        high=h;
    }
};

class binary
{
    class vertex
    {
        public:
        int max;
        interval i;
        vertex *left;
        vertex *right;
        vertex(int l,int h):interval(low,high)
        {
            left=NULL;
            right=NULL;
            high=h;max=h;
        }
    }*root;

    vertex* insert(vertex *ptr,vertex *x)
    {
        if(!ptr) return x;
        else if(ptr->low>x->low)
        {
            ptr->left=insert(ptr->left,x);
            if(ptr->left->max>ptr->max)
            ptr->max=ptr->left->max;
        }
        else if(ptr->low<x->low)
        {
            ptr->right=insert(ptr->right,x);
            if(ptr->right->max>ptr->max)
            ptr->max=ptr->right->max;
        }
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
        if(!level)
        {
            cout<<"("<<ptr->low;
            cout<<" "<<ptr->high;
            cout<<" m"<<ptr->max;
            cout<<"), ";
        }
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

    void insert(int low,int high)
    {
        vertex *x;
        if(low<high)
        {
            x=new vertex(low,high);
            root=insert(root,x);
        }
    }

    int height(){return height(root,0);}

    bool search(int low,int high)
    {

    }

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
    int ch,low,high;
    do
    {
        system("cls");
        if(tree.exists())
        tree.levelorder();
        cout<<"\n 1. Insert ";
        cout<<"\n 2. Search ";
        cout<<"\n 3. End Program ";
        cout<<"\n\n Enter>>";
        cin>>ch; switch(ch)
        {
            case 1 :
            cout<<"\n Enter a low value : ";  cin>>low;
            cout<<"\n Enter a high value : "; cin>>high;
            tree.insert(low,high);
            break;

            case 2 :
            cout<<"\n Enter a low value : ";  cin>>low;
            cout<<"\n Enter a high value : "; cin>>high;
            if(tree.search(low,high))


            break;

            case 0 : tree.kill(); break;
        }
    }while(ch!=2);
}
