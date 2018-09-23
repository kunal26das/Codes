#include<iostream>
#include<stdlib.h>
#include<conio.h>

using namespace std;

struct node
{
    int value;
    node *next;
};
class list
{
    node *first;
    node *last;
    public:
    list()
    {
        first=NULL;
        last=NULL;
    }
    node* create(int value)
    {
        node *x=new node;
        x->value=value;
        x->next=NULL;
        return x;
    }
    void append(node *x)
    {
        if(first==NULL) first=x;
        else last->next=x;
        last=x;
    }
    node* search(int value)
    {
        int pos=0;
        node *ptr=first;
        while(ptr!=NULL)
        {
            pos++;
            if(ptr->value==value)
            {
                cout<<"\n Found at position "<<pos<<endl;
                break;
            }
            ptr=ptr->next;
        }
        if(ptr==NULL) cout<<"\n Not found! \n";
        return ptr;
    }
    void deleter(node* ptr)
    {
        if(ptr!=NULL)
        {
            node *temp,*mark;
            if(ptr==first)
            {
                temp=first;
                first=first->next;
                free(temp);
            }
            else
            {
                mark=ptr;
                temp=first;
                ptr=temp->next;
                while(ptr!=mark)
                {
                    temp=temp->next;
                    ptr=temp->next;
                }
                temp->next=ptr->next;
                free(ptr);
            }
            ptr=first;
            while(ptr!=NULL && ptr->next!=NULL)
                ptr=ptr->next;
            last=ptr;
        }
        else cout<<"\n Deletion not possible! \n";
    }
    void display()
    {
        node *ptr=first;
        cout<<"\n The list is : ";
        if(ptr==NULL) cout<<"Empty!";
        else while(ptr!=NULL)
        {
            cout<<ptr->value<<", ";
            ptr=ptr->next;
        }
        cout<<endl;
    }
};

int main()
{
    list l;
    int value,ch;
    do
    {
        system("cls");
        cout<<"\n 1. Add     ";
        cout<<"\n 2. Delete  ";
        cout<<"\n 3. Display ";
        cout<<"\n 4. Exit    ";
        cout<<"\n\n Enter>>";
        cin>>ch;
        switch(ch)
        {
            case 1 :
                cout<<"\n Enter a value : ";
                cin>>value;
                l.append(l.create(value));
                break;
            case 2 :
                cout<<"\n Enter a value : ";
                cin>>value;
                l.deleter(l.search(value));
                l.display();
                getch();
                break;
            case 3 :
                l.display();
                getch();
                break;
        }
    }while(ch!=4);
}
