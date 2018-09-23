#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<queue>

using namespace std;

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
};

class binary
{
    vertex *root;
    void insert(vertex **ptr,vertex *x)
    {
        if(*ptr==NULL) *ptr=x;
        else if((*ptr)->value>x->value)
        insert(&(*ptr)->left,x);
        else if((*ptr)->value<x->value)
        insert(&(*ptr)->right,x);
        else return;
    }
    int height(vertex *ptr,int h=0)
    {
        if(!ptr) return h;
        int left=h,right=h;
        if(ptr->left) left=height(ptr->left,h+1);
        if(ptr->right) right=height(ptr->right,h+1);
        return left>right?left:right;
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
    void levelorder()
    {
        queue<vertex*> que;
        vertex *x=root;
        while(x||!que.empty())
        {
            if(x)
            {
                cout<<x->value<<", ";
                que.push(x->left);
                que.push(x->right);
            }
            x=que.front();
            que.pop();
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
            {
                cout<<"of height : ";
                cout<<tree.height();
            }
            else cout<<"empty!";
            cout<<"\n "; system("pause");
            break;

            case 3 :
            cout<<"\n Tree is : ";
            if(tree.exists())
            tree.levelorder();
            else cout<<"empty!";
            cout<<"\n "; system("pause");
            break;
        }
    }while(ch!=4);
}
