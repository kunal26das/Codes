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

class node
{
    public:
    vertex *value;
    node *next;
    node(){next=NULL;}
};

class stack
{
    node *top;
    public:
    stack(){top=NULL;}
    int underflow()
    {
        if(top==NULL)
        return 1;
        return 0;
    }
    void push(vertex *ptr)
    {
        node *x=new node;
        x->value=ptr;
        if(top!=NULL)
        x->next=top;
        top=x;
    }
    vertex* pop()
    {
        vertex *ptr=top->value;
        node *temp=top;
        top=top->next;
        delete temp;
        return ptr;
    }
    int chktop(vertex *ptr)
    {
        if(top->value==ptr)
        return 1;
        return 0;
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
    void iterative()
    {
        stack stk;
        vertex *x=root;
        do
        {
            while(x)
            {
                if(x->right)
                stk.push(x->right);
                stk.push(x);
                x=x->left;
            }
            x=stk.pop();
            if(x->right&&!stk.underflow()&&stk.chktop(x->right))
            {
                stk.pop();
                stk.push(x);
                x=x->right;
            }
            else
            {
                cout<<x->value<<", ";
                x=NULL;
            }
        }while(!stk.underflow());
    }
    void recursive(vertex *x)
    {
        if(x->left) recursive(x->left);
        if(x->right) recursive(x->right);
        cout<<x->value<<", ";
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
        cout<<"\n 2. Iterative Postorder ";
        cout<<"\n 3. Recursive Postorder ";
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
            cout<<"\n The tree is : ";
            if(tree.exists())
            tree.iterative();
            else cout<<"empty!";
            getch();
            break;

            case 3 :
            cout<<"\n The tree is : ";
            if(tree.exists())
            tree.recursive(tree.root);
            else cout<<"empty!";
            getch();
            break;
        }
    }while(ch!=4);
}
