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
        int left=height(ptr->left,h+1);
        int right=height(ptr->right,h+1);
        return left>right?left:right;
    }
    int smallest(vertex *ptr)
    {
        if(ptr->left)
        smallest(ptr->left);
        else return ptr->value;
    }
    int largest(vertex *ptr)
    {
        if(ptr->right)
        largest(ptr->right);
        else return ptr->value;
    }
    int remove(vertex *ptr,int value)
    {
        int flag=0;
        if(!ptr) return flag;
        if(ptr->value==value)
        {
            int temp;
            if(ptr->left)
            {
                temp=largest(ptr->left);
                ptr->value=temp;
                flag=remove(ptr->left,temp);
                if(flag==2)
                {
                    ptr->left=NULL;
                    return 1;
                }
                else return flag;
            }
            else if(ptr->right)
            {
                temp=smallest(ptr->right);
                ptr->value=temp;
                if(remove(ptr->right,temp)==2)
                {
                    ptr->right=NULL;
                    return 1;
                }
                else return flag;
            }
            else
            {
                delete ptr;
                return 2;
            }
        }
        else if(ptr->value>value)
        {
            flag=remove(ptr->left,value);
            if(flag==2)
            {
                ptr->left=NULL;
                return 1;
            }
            else return flag;
        }
        else if(ptr->value<value)
        {
            flag=remove(ptr->right,value);
            if(flag==2)
            {
                ptr->right=NULL;
                return 1;
            }
            else return flag;
        }
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
        insert(&root,x);
    }
    int height()
    {return height(root,0);}
    int removed(int value)
    {
        int flag=remove(root,value);
        if(flag==2)
        {
            root=NULL;
            return 1;
        }
        else return flag;
    }
    void levelorder()
    {
        int h=height(root);
        for(int i=0;i<=h;i++)
        {
            levelorder(root,i);
            cout<<" ";
        }
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
    int value,ch;
    do
    {
        system("cls");
        cout<<"\n 1. Insert ";
        cout<<"\n 2. Height ";
        cout<<"\n 3. Delete ";
        cout<<"\n 4. Level-Order ";
        cout<<"\n 5. End Program ";
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
            cout<<"of height : "<<tree.height();
            else cout<<"empty! ";
            system("pause");
            break;

            case 3 :
            if(tree.exists())
            {
                cout<<"\n Enter a value : ";
                cin>>value;
                cout<<"\n "<<value<<" ";
                if(tree.removed(value))
                cout<<"removed from tree. ";
                else cout<<"is not in the tree. ";
            }
            else cout<<"\n Tree is empty. ";
            system("pause");
            break;

            case 4 :
            cout<<"\n Tree is : ";
            if(tree.exists())
            tree.levelorder();
            else cout<<"empty! ";
            system("pause");
            break;
        }
    }while(ch!=5);
}
