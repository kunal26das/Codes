#include<iostream>
#include<stdlib.h>
#include<conio.h>

using namespace std;

struct node
{
    int value;
    int index;
    node *next;
};

struct head
{
    head *down;
    node *next;
};

class list
{
    head *first;
    head *last;
    int rows()
    {
        int row=0;
        head *temp=first;
        while(temp)
        {
            row++;
            temp=temp->down;
        }
        return row;
    }
    int cols()
    {
        int col=-1;
        node *ptr;
        head *temp=first;
        while(temp)
        {
            ptr=temp->next;
            while(ptr)
            {
                if(ptr->index>col)
                col=ptr->index;
                ptr=ptr->next;
            }
            temp=temp->down;
        }
        return col+1;
    }
    head* newhead()
    {
        head *x=new head;
        x->down=NULL;
        x->next=NULL;
        if(first)
        last->down=x;
        else first=x;
        last=x;
        return x;
    }
    node* newnode(int val,int col)
    {
        node *x=new node;
        x->value=val;
        x->index=col;
        x->next=NULL;
        return x;
    }
    void insertnode(head *temp,node *x)
    {
        node *ptr=temp->next;
        if(!ptr) temp->next=x;
        else if(x->index<ptr->index)
        {
            x->next=temp->next;
            temp->next=x;
        }
        else if(x->index>ptr->index)
        {
            while(ptr->next&&x->index>ptr->next->index)
            ptr=ptr->next;
            x->next=ptr->next;
            ptr->next=x;
        }
        else delete x;
    }
    int search(int row,int col)
    {
        head *temp=first;
        for(int i=0;i<row;i++)
        if(temp) temp=temp->down;

        node *ptr=temp->next;
        for(int j=0;j<col;j++)
        if(ptr) ptr=ptr->next;

        if(ptr) return ptr->value;
        else    return 0;
    }
    public:
    list()
    {
        first=NULL;
        last=NULL;
    }
    int empty()
    {
        if(first==NULL)
        return 1;
        return 0;
    }
    int multiply(list &x,list &y)
    {
        if(x.cols()==y.rows())
        return 1;
        return 0;
    }
    void append(int val,int row,int col)
    {
        head *temp=first;
        for(int i=0;i<row;i++)
        {
            if(!temp)
            temp=newhead();
            temp=temp->down;
        }
        if(!temp) temp=newhead();
        if(!val)  return;
        node *x=newnode(val,col);
        insertnode(temp,x);
    }
    list operator*(list &x)
    {
        list l3;
        node *ptr;
        int n=0,sum=0;
        int row=rows();
        int col=x.cols();
        head *temp=first;
        while(temp)
        {
            for(int i=0;i<col;i++)
            {
                sum=0; ptr=temp->next;
                for(int j=0;j<row;j++)
                {
                    if(ptr&&ptr->index==j)
                    {
                        sum+=ptr->value*x.search(j,n);
                        ptr=ptr->next;
                    }
                }
                l3.append(sum,n,i);
            }
            temp=temp->down;
            n++;
        }
        return l3;
    }
    void inverse()
    {
        int row=rows();
        int col=cols();
        for(int i=0;i<col;i++)
        {
            for(int j=0;j<row;j++)
            {
                if(search(j,i))
                cout<<search(j,i);
                else cout<<0;
            }
            cout<<endl;
        }
    }
    void display()
    {
        int row=rows();
        int col=cols();
        int i; node *ptr;
        head *temp=first;
        while(temp)
        {
            cout<<"  ";
            ptr=temp->next;
            for(i=0;i<col;i++)
            cout<<"--- "; cout<<"\n ";
            for(i=0;i<col;i++)
            {
                if(ptr&&ptr->index==i)
                {
                    cout<<"| ";
                    cout<<ptr->value<<" ";
                    ptr=ptr->next;
                }
                else cout<<"|   ";
            }
            temp=temp->down;
            cout<<"| \n";
        }
        cout<<"  "; for(i=0;i<col;i++)
        cout<<"--- ";
    }
};

int main()
{
    list l1,l2,l3;

    int i,a[][5]=
    {
        {1,1,1,1},
        {2,2,2,2},
        {2,2,2,2},
        {2,2,2,2},
        {1,1,1,1}
    };

    int j,b[][5]=
    {
        {1,1,1},
        {1,1,1},
        {1,1,1},
        {1,1,1}
    };

    for(i=0;i<5;i++)
    for(j=0;j<4;j++)
    l1.append(a[i][j],i,j);

    for(i=0;i<4;i++)
    for(j=0;j<3;j++)
    l2.append(b[i][j],i,j);

    l1.display(); cout<<"\n\n";
    l2.display(); cout<<"\n\n";
    if(l3.multiply(l1,l2))
    {
        l3=l1*l2;
        l3.display();
        cout<<"\n\n";
    }
}
