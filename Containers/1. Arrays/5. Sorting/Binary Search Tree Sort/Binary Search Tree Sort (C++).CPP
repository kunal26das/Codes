#include<iostream>
#include<stdlib.h>
#include<stack>

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
    }*root; int count;
    void insert(vertex **ptr,vertex *x)
    {
        if(*ptr==NULL)
        {
            *ptr=x;
            count++;
        }
        else if((*ptr)->value>x->value)
        insert(&(*ptr)->left,x);
        else if((*ptr)->value<x->value)
        insert(&(*ptr)->right,x);
        else return;
    }
    public:
    binary()
    {
        count=0;
        root=NULL;
    }
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
    int* inorder()
    {
        int i=0;
        vertex *ptr=root;
        stack<vertex*> stk;
        int *inorder=new int(count);
        do
        {
            while(ptr)
            {
                stk.push(ptr);
                ptr=ptr->left;
            }
            if(!stk.empty())
            {
                ptr=stk.top(); stk.pop();
                inorder[i++]=ptr->value;
                ptr=ptr->right;
            }
        }while(!stk.empty()||ptr);
        return inorder;
    }
};

class list
{
    int *array;
    int index;
    int size;
    public:
    list(int s)
    {
        array=new int[s];
        size=s; index=-1;
    }
    int empty()
    {
        if(index==-1)
        return 1;
        return 0;
    }
    int full()
    {
        if(index==size-1)
        return 1;
        return 0;
    }
    void append(int value)
    {array[++index]=value;}
    void bstsort()
    {
        binary tree;
        for(int i=0;i<=index;i++)
        tree.insert(array[i]);
        int *temp=tree.inorder();
        for(int i=0;i<=index;i++)
        array[i]=temp[i];
    }
    void display()
    {
        for(int i=0;i<=index;i++)
        cout<<array[i]<<", ";
    }
    void destroy()
    {
        index=-1;
        delete array;
        array=new int[size];
    }
};

int main()
{
    list lst(5);
    int ch,value;
    do
    {
        system("cls");
        cout<<"\n 1. Append ";
        cout<<"\n 2. BST Sort ";
        cout<<"\n 3. Display ";
        cout<<"\n 4. End Program ";
        cout<<"\n\n Enter>>";
        cin>>ch; switch(ch)
        {
            case 1 :
            if(!lst.full())
            {
                cout<<"\n Enter a value : ";
                cin>>value; lst.append(value);
            }
            else
            {
                cout<<"\n Array is full!\n ";
                system("pause");
            }
            break;

            case 2 :
            cout<<"\n Array is : ";
            if(!lst.empty())
            {
                lst.bstsort();
                lst.display();
            }
            else cout<<"empty!";
            cout<<"\n "; system("pause");
            break;

            case 3 :
            cout<<"\n Array is : ";
            if(!lst.empty()) lst.display();
            else cout<<"empty!";
            cout<<"\n "; system("pause");
            break;

            case 0 :
            lst.destroy();
            break;
        }
    }while(ch!=4);
}
