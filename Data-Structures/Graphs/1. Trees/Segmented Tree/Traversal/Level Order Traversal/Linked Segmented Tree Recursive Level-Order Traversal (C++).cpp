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
        if(!ptr) return h-1;
        int left=height(ptr->left,h+1);
        int right=height(ptr->right,h+1);
        return left>right?left:right;
    }

    void maxheapify()
    {
        int h=height(root,0);
        for(int i=h;i>=0;i--)
        maxheapify(root,i);
    }

    void maxheapify(vertex *ptr,int level)
    {
        if(!ptr) return;
        if(!level) maxheapify(ptr);
        else
        {
            maxheapify(ptr->left,level-1);
            maxheapify(ptr->right,level-1);
        }
    }

    void maxheapify(vertex *ptr)
    {
        if(ptr->right&&ptr->value<ptr->right->value)
        {
            swap(ptr->value,ptr->right->value);
            maxheapify(ptr->right);
        }
        if(ptr->left&&ptr->value<ptr->left->value)
        {
            swap(ptr->value,ptr->left->value);
            maxheapify(ptr->left);
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

    bool exists()
    {
        if(root)
        return true;
        return false;
    }

    void insert(int value)
    {
        if(root)
        {
            int h=height(root,0);
            if(!insert(root,h,value))
            insert(root,h+1,value);
            maxheapify();
        }
        else root=new vertex(value);
    }

    int height(){return height(root,0);}

    void levelorder()
    {
        int h=height();
        for(int i=0;i<=h;i++)
        {
            cout<<"\n Level ";
            cout<<i<<" : ";
            levelorder(root,i);
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

class list
{
    binary heap;
    int *array;
    int index;
    int size;

    binary construct(int low,int high)
    {
        int sum=0;
        if(low<=high)
        {
            int mid=(low+high)/2;
            for(int i=low;i<=high;i++)
            sum+=array[i];
            heap.insert(sum);
            construct(low,mid);
            construct(mid+1,high);
        }
    }

    public:
    list(int s)
    {
        array=new int[s];
        index=-1; size=s;
    }

    bool empty()
    {
        if(index==-1)
        return true;
        return false;
    }

    void append(int value)
    {
        if(index<size-1)
        {
            heap.kill();
            array[++index]=value;
            construct(0,index);
        }
    }

    int search(int value)
    {
        for(int i=0;i<=index;i++)
        if(array[i]==value)
        return i+1;
        return 0;
    }

    void remove(int value)
    {
        int found=search(value);
        if(found)
        {
            for(int i=found-1;i<index;i++)
            array[i]=array[i+1]; index--;
        }
        if(index==-1) delete array;
    }

    void display()
    {
        cout<<"\n Array is";
        if(index==size-1)
        cout<<" Full"; cout<<" : ";
        for(int i=0;i<=index;i++)
        cout<<array[i]<<", ";
        cout<<endl; heap.levelorder();
    }

    ~list()
    {
        delete array;
        index=-1;
    }
};

int main()
{
    list lst(5);
    int ch,value;
    do
    {
        system("cls");
        if(!lst.empty())
        lst.display();
        cout<<"\n 1. Insert ";
        cout<<"\n 2. Delete ";
        cout<<"\n 3. End Program ";
        cout<<"\n\n Enter>>";
        cin>>ch; switch(ch)
        {
            case 1 :
            cout<<"\n Enter a value : ";
            cin>>value; lst.append(value);
            break;

            case 2 :
            cout<<"\n Enter a value : ";
            cin>>value; lst.remove(value);
            break;

            case 0 : break;
        }
    }while(ch!=3);
}
