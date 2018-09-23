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
    int checksum(list &x,list &y)
    {
        if(x.rows()==y.rows())
        if(x.cols()==y.cols())
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
    list operator+(list &x)
    {
        list l3; int n=0;
        node *ptr1,*ptr2;
        head *temp1=first;
        head *temp2=x.first;
        while(temp1&&temp2)
        {
            ptr1=temp1->next;
            ptr2=temp2->next;
            while(ptr1&&ptr2)
            {
                if(ptr1->index==ptr2->index)
                {
                    l3.append(ptr1->value+ptr2->value,n,ptr1->index);
                    ptr1=ptr1->next; ptr2=ptr2->next;
                }
                else if(ptr1->index<ptr2->index)
                {
                    l3.append(ptr1->value,n,ptr1->index);
                    ptr1=ptr1->next;
                }
                else if(ptr2->index<ptr1->index)
                {
                    l3.append(ptr2->value,n,ptr2->index);
                    ptr2=ptr2->next;
                }
            }
            while(ptr1)
            {
                l3.append(ptr1->value,n,ptr1->index);
                ptr1=ptr1->next;
            }
            while(ptr2)
            {
                l3.append(ptr2->value,n,ptr2->index);
                ptr2=ptr2->next;
            }
            temp1=temp1->down;
            temp2=temp2->down;
            n++;
        }
        return l3;
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

    int a[][5]=
    {
        {1,0,0,0,1},
        {0,1,0,1,0},
        {0,0,1,0,0},
        {0,1,0,1,0},
        {1,0,0,0,1}
    };

    int b[][5]=
    {
        {0,0,1,0,0},
        {0,0,1,0,0},
        {1,1,1,1,1},
        {0,0,1,0,0},
        {0,0,1,0,0}
    };

    for(int i=0;i<5;i++)
    for(int j=0;j<5;j++)
    {
        l1.append(a[i][j],i,j);
        l2.append(b[i][j],i,j);
    }

    l1.display(); cout<<"\n\n";
    l2.display(); cout<<"\n\n";
    if(l3.checksum(l1,l2))
    {
        l3=l1+l2;
        l3.display();
        cout<<"\n\n";
    }
}
