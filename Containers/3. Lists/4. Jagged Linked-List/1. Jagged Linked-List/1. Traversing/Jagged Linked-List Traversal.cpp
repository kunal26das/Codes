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
    void inverse()
    {
        node *ptr;
        head *temp;
        int i,j,flag;
        int row=rows();
        int col=cols();
        for(i=0;i<col;i++)
        {
            cout<<"  ";
            for(j=0;j<row;j++)
            cout<<"--- "; cout<<"\n ";
            temp=first;
            while(temp)
            {
                flag=0;
                ptr=temp->next;
                while(ptr)
                {
                    if(ptr->index==i)
                    {
                        flag=1;
                        cout<<"| ";
                        cout<<ptr->value<<" ";
                        break;
                    }
                    ptr=ptr->next;
                }
                if(!flag) cout<<"|   ";
                temp=temp->down;
            }
            cout<<"| \n";
        }
        cout<<"  "; for(i=0;i<row;i++)
        cout<<"--- ";
    }
    void straight()
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
    list lst;
    int ch,val;
    int row,col;
    do
    {
        system("cls");
        cout<<"\n 1. Add ";
        cout<<"\n 2. Inverse ";
        cout<<"\n 3. Display ";
        cout<<"\n 4. Exit ";
        cout<<"\n\n Enter>>";
        cin>>ch; switch(ch)
        {
            case 1 :
            cout<<"\n Enter a value : "; cin>>val;
            cout<<"\n Enter row no. : "; cin>>row;
            cout<<"\n Enter col no. : "; cin>>col;
            lst.append(val,row-1,col-1);
            break;

            case 2 :
            cout<<"\n Matrix is : \n\n";
            if(!lst.empty())
            lst.inverse();
            else cout<<" Empty! ";
            getch();
            break;

            case 3 :
            cout<<"\n Matrix is : \n\n";
            if(!lst.empty())
            lst.straight();
            else cout<<" Empty! ";
            getch();
            break;
        }
    }while(ch!=4);
}
