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

void swap(int*,int*);

class binary
{
    vertex *root;
    int insert(vertex *ptr,int level,int value)
    {
        if(!ptr) return 2;
        if(!level) return 0;
        else
        {
            int flag;
            flag=insert(ptr->left,level-1,value);
            if(flag==2)
            {
                ptr->left=new vertex(value);
                return 1;
            }
            else if(flag) return 1;
            else if(!flag)
            {
                flag=insert(ptr->right,level-1,value);
                if(flag==2)
                {
                    ptr->right=new vertex(value);
                    return 1;
                }
                else return flag;
            }
        }
    }
    int height(vertex *ptr,int h)
    {
        int left=h,right=h;
        if(ptr->left) left=height(ptr->left,h+1);
        if(ptr->right) right=height(ptr->right,h+1);
        return left>right?left:right;
    }
    void minheapify()
    {
        int h=height(root,0);
        for(int i=h;i>=0;i--)
        minheapify(root,i);
    }
    void minheapify(vertex *ptr,int level)
    {
        if(!ptr) return;
        if(!level) minheapify(ptr);
        else
        {
            minheapify(ptr->left,level-1);
            minheapify(ptr->right,level-1);
        }
    }
    void minheapify(vertex *ptr)
    {
        if(ptr->right&&ptr->value>ptr->right->value)
        {
            swap(&ptr->value,&ptr->right->value);
            minheapify(ptr->right);
        }
        if(ptr->left&&ptr->value>ptr->left->value)
        {
            swap(&ptr->value,&ptr->left->value);
            minheapify(ptr->left);
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
        if(root)
        {
            int h=height(root,0);
            if(!insert(root,h,value))
            insert(root,h+1,value);
            minheapify();
        }
        else root=new vertex(value);
    }
    int height()
    {return height(root,0);}
    void levelorder()
    {
        int h=height(root,0);
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

void swap(int *p,int *q)
{
    int temp=*p;
    *p=*q; *q=temp;
}

int main()
{
    binary heap;
    int ch,value;
    do
    {
        system("cls");
        cout<<"\n 1. Insert ";
        cout<<"\n 2. Height ";
        cout<<"\n 3. Level-Order ";
        cout<<"\n 4. End Program ";
        cout<<"\n\n Enter>>";
        cin>>ch; switch(ch)
        {
            case 1 :
            cout<<"\n Enter a value : ";
            cin>>value; heap.insert(value);
            break;

            case 2 :
            cout<<"\n Heap is ";
            if(heap.exists())
            cout<<"of height "<<heap.height();
            else cout<<"empty!";
            getch();
            break;

            case 3 :
            cout<<"\n Heap is : ";
            if(heap.exists())
            heap.levelorder();
            else cout<<"empty!";
            getch();
            break;

            case 0 :
            heap.kill();
            break;
        }
    }while(ch!=4);
}
