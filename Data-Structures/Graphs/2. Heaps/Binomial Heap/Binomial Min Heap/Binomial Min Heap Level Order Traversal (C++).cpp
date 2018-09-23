#include<iostream>
#include<stdlib.h>

using namespace std;

class binomial
{
    int count;
    class vertex
    {
        public:
        int value;
        vertex *up;
        vertex *next;
        vertex *down;
        vertex(int _value)
        {
            up=NULL;
            down=NULL;
            next=NULL;
            value=_value;
        }
    }*head;

    int trees(vertex *ptr,int count)
    {
        if(!ptr) return count;
        trees(ptr->next,count+1);
    }

    int rank(vertex *ptr)
    {
        int count=0;
        if(ptr->down)
        {
            count=1;
            vertex *temp=ptr->down;
            while(temp->next)
            {
                count++;
                temp=temp->next;
            }
            temp=ptr->down;
            int array[count];
            for(int i=0;i<count;i++)
            {
                array[i]=rank(temp);
                temp=temp->next;
            }
            int max=array[0];
            for(int i=1;i<count;i++)
            if(max<array[i])
            max=array[i];
            if(max>count)
            count=max;
        }
        return count;
    }

    int height(vertex *ptr)
    {
        int h=-1; while(ptr)
        {h++; ptr=ptr->down;}
        return h;
    }

    vertex* previous(vertex *x)
    {
        vertex *ptr=head;
        if(ptr==x) return NULL;
        while(ptr->next&&ptr->next!=x)
        ptr=ptr->next; return ptr;
    }

    void heapify(vertex *ptr)
    {
        if(!ptr->next) return;
        heapify(ptr->next);
        if(height(ptr)==height(ptr->next))
        {
            vertex *temp;
            vertex *first=ptr;
            vertex *second=ptr->next;
            if(first->value<second->value)
            {
                temp=second->next;
                second->up=first;
                second->next=first->down;
                first->down=second;
                first->next=temp;
            }
            else if(first->value>second->value)
            {
                temp=previous(first);
                first->up=second;
                first->next=second->down;
                second->down=first;
                if(temp) temp->next=second;
                else head=second;
            }
            heapify(head);
        }
    }

    vertex* find(vertex *ptr,int value)
    {
        vertex *temp;
        if(!ptr||ptr->value==value)
        return ptr;
        else
        {
            temp=find(ptr->next,value);
            if(!temp) temp=find(ptr->down,value);
        }
        return temp;
    }

    void meld(vertex *child)
    {
        if(!child) return;
        child->up=NULL;
        vertex *save=child;
        while(child->next)
        {
            child=child->next;
            child->up=NULL;
        }
        child->next=head;
        head=save;
    }

    void decrease(vertex *ptr,int value)
    {
        ptr->value=value;
        while(ptr->up&&ptr->value<ptr->up->value)
        {
            swap(ptr->value,ptr->up->value);
            ptr=ptr->up;
        }
    }

    void extract(vertex *ptr)
    {
        vertex *parent=ptr->up;
        vertex *child=ptr->down;
        vertex *temp,*save=ptr->down;
        meld(child);
        if(parent)
        {
            if(parent->down==ptr)
            parent->down=ptr->next;
            else temp=parent->down;
        }
        else
        {
            if(head==ptr)
            head=head->next;
            else temp=head;
        }
        while(temp->next!=ptr)
        temp=temp->next;
        temp->next=ptr->next;
        delete ptr;
    }

    void levelorder(vertex *ptr,int level)
    {
        if(!ptr) return;
        if(!level) cout<<ptr->value<<", ";
        else levelorder(ptr->down,level-1);
        levelorder(ptr->next,level);
    }

    void destroy(vertex *ptr)
    {
        if(!ptr) return;
        if(ptr->down)
        {
            destroy(ptr->down);
            ptr->down=NULL;
        }
        if(ptr->next)
        {
            destroy(ptr->next);
            ptr->next=NULL;
        }
        delete(ptr);
    }

    public:

    binomial()
    {
        count=0;
        head=NULL;
    }

    bool exists()
    {
        if(head)
        return true;
        return false;
    }

    int trees()
    {return trees(head,0);}

    int rank()
    {
        if(!head) return 0;
        int count=trees();
        int array[count];
        vertex *ptr=head;
        int max=0;
        for(int i=0;i<count;i++)
        {
            array[i]=rank(ptr);
            ptr=ptr->next;
            if(max<array[i])
            max=array[i];
        }
        return max;
    }

    void insert(int value)
    {
        vertex *x=new vertex(value);
        if(head) x->next=head;
        head=x; heapify(head);
        count++;
    }

    bool find(int value)
    {
        if(find(head,value))
        return true;
        return false;
    }

    int minimum()
    {
        int small=head->value;
        vertex *ptr=head->next;
        while(ptr)
        {
            if(small>ptr->value)
            small=ptr->value;
            ptr=ptr->next;
        }
        return small;
    }

    void decrease(int value,int change)
    {
        vertex *found=find(head,value);
        if(found) decrease(found,change);
    }

    void extract(int value)
    {
        vertex *found;
        found=find(head,value);
        if(!found) return;
        extract(found);
        count--;
    }

    void levelorder()
    {
        int n=0,temp=1;
        while(temp<=count)
        {n++; temp*=2;}
        for(int i=0;i<n;i++)
        {
            cout<<"\n Level ";
            cout<<i<<" : ";
            levelorder(head,i);
            cout<<" ";
        }
        cout<<endl;
    }

    void destroy()
    {
        if(!head) return;
        destroy(head);
        head=NULL;
        count=0;
    }
};

int main()
{
    binomial heap;
    int ch,value,change;
    do
    {
        system("cls");
        if(heap.exists())
        {
            cout<<"\n Trees = ";
            cout<<heap.trees();
            cout<<", Rank = ";
            cout<<heap.rank();
            cout<<endl;
            heap.levelorder();
        }
        cout<<"\n 1. Insert ";
        cout<<"\n 2. Search ";
        cout<<"\n 3. Delete ";
        cout<<"\n 4. Minimum ";
        cout<<"\n 5. Decrease ";
        cout<<"\n 6. Extract-Min ";
        cout<<"\n 7. End program ";
        cout<<"\n\n Enter>>";
        cin>>ch; switch(ch)
        {
            case 1 :
            cout<<"\n Enter a value : ";
            cin>>value; heap.insert(value);
            break;

            case 2 :
            cout<<"\n Enter a value : ";
            cin>>value; if(heap.find(value))
            cout<<"\n Element found ";
            else cout<<"\n Element not found ";
            cout<<"\n "; system("pause");
            break;

            case 3 :
            if(heap.exists())
            {
                cout<<"\n Enter a value : ";
                cin>>value;
                heap.decrease(value,INT_MIN);
                heap.extract(INT_MIN);
            }
            else cout<<"\n Heap is empty! ";
            cout<<"\n "; system("pause");
            break;

            case 4 :
            if(heap.exists())
            {
                cout<<"\n Minimum element is ";
                cout<<heap.minimum();
            }
            else cout<<"\n Heap is empty! ";
            cout<<"\n "; system("pause");
            break;

            case 5 :
            cout<<"\n Enter the value to decrease : ";
            cin>>value;
            cout<<"\n Enter the decreased value : ";
            cin>>change; if(change<value)
            heap.decrease(value,change);
            break;

            case 6 :
            if(heap.exists())
            heap.extract(heap.minimum());
            else cout<<"\n Heap is empty! ";
            cout<<"\n "; system("pause");
            break;

            case 0 : heap.destroy(); break;
        }
    }while(ch!=7);
}
