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
    void insert(vertex **ptr,vertex *x)
    {
        if(*ptr==NULL) *ptr=x;
        else if((*ptr)->value>x->value)
        insert(&(*ptr)->left,x);
        else if((*ptr)->value<x->value)
        insert(&(*ptr)->right,x);
        else return;
    }
    int height(vertex *ptr,int h)
    {
        int left=h,right=h;
        if(ptr->left) left=height(ptr->left,h+1);
        if(ptr->right) right=height(ptr->right,h+1);
        return left>right?left:right;
    }
    void inorder(vertex *ptr)
    {
        if(!ptr) return;
        inorder(ptr->left);
        cout<<ptr->value<<", ";
        inorder(ptr->right);
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
        vertex *x=new vertex(value);
        insert(&root,x);
    }
    int height(){return height(root,0);}
    void inorder(){inorder(root);}
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
        cout<<"\n 1. Insert ";
        cout<<"\n 2. Height ";
        cout<<"\n 3. Inorder ";
        cout<<"\n 4. End Program ";
        cout<<"\n\n Enter>>";
        cin>>ch; switch(ch)
        {
            case 1 :
            cout<<"\n Enter a value : ";
            cin>>value; tree.insert(value);
            break;

            case 2 :
            cout<<"\n Tree is : ";
            if(tree.exists())
            cout<<"of height  "<<tree.height();
            else cout<<"empty!";
            cout<<"\n "; system("pause");
            break;

            case 3 :
            cout<<"\n The tree is : ";
            if(tree.exists())
            tree.inorder();
            else cout<<"empty!";
            cout<<"\n "; system("pause");
            break;

            case 0 :
            tree.kill();
            break;
        }
    }while(ch!=4);
}
