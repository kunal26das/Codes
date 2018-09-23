#include<iostream>
#include<stdlib.h>
#include<conio.h>

using namespace std;

class vertex
{
    public:
    int value;
    vertex **child;
    vertex(int v,int k)
    {
        child=new vertex*[k];
        for(int i=0;i<k;i++)
        *(child+i)=NULL;
        value=v;
    }
};

int max(int*,int);
void swap(int*,int*);

class k_ary
{
    int k; vertex *root;
    int insert(vertex *ptr,int level,int value)
    {
        if(!ptr) return 2;
        if(!level) return 0;
        else
        {
            int i,flag;
            for(i=0;i<k;i++)
            {
                flag=insert(ptr->child[i],level-1,value);
                if(flag==2)
                {
                    ptr->child[i]=new vertex(value,k);
                    return 1;
                }
                else if(flag==1) return 1;
                else if(flag==0&&i==k-1) return 0;
            }
        }
    }
    int height(vertex *ptr,int h)
    {
        int c[k]; for(int i=0;i<k;i++)
        {
            c[i]=h; if(ptr->child[i])
            c[i]=height(ptr->child[i],h+1);
        }
        return max(c,k);
    }
    void minheapify()
    {
        int h=height(root,0);
        for(int i=h;i>=0;i--)
        minheapify(root,i);
    }
    void minheapify(vertex *ptr)
    {
        for(int i=0;i<k;i++)
        if(ptr->child[i]&&ptr->value>ptr->child[i]->value)
        {
            swap(&ptr->value,&ptr->child[i]->value);
            minheapify(ptr->child[i]);
        }
    }
    void minheapify(vertex *ptr,int level)
    {
        if(!ptr) return;
        if(!level) minheapify(ptr);
        else for(int i=k-1;i>=0;i--)
        minheapify(ptr->child[i],level-1);
    }
    void levelorder(vertex *ptr,int level)
    {
        if(!ptr) return;
        if(!level) cout<<ptr->value<<", ";
        else for(int i=0;i<k;i++)
        levelorder(ptr->child[i],level-1);
    }
    void kill(vertex *ptr,int level)
    {
        if(!ptr) return;
        if(!level) delete ptr;
        else for(int i=0;i<k;i++)
        {
            kill(ptr->child[i],level-1);
            ptr->child[i]=NULL;
        }
    }
    public:
    k_ary(int n)
    {k=n;root=NULL;}
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
        else root=new vertex(value,k);
    }
    int height(){return height(root,0);}
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

int max(int *array,int size)
{
    int large=*array;
    for(int i=1;i<size;i++)
    if(*(array+i)>large)
    large=*(array+i);
    return large;
}

void swap(int *p,int *q)
{
    int temp=*p;
    *p=*q; *q=temp;
}

int main()
{
    k_ary heap(3);
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
