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
        else
        {
            cout<<"\n Deletion not possible!";
            getch();
        }
    }
    void operator=(list l)
    {
        node *ptr=first;
        while(ptr!=NULL)
        {
            deleter(ptr);
            ptr=ptr->next;
        }
        ptr=l.first;
        while(ptr!=NULL)
        {
            append(create(ptr->value));
            ptr=ptr->next;
        }
    }
    list operator+(list x)
    {
        list temp;
        node *ptr=first;
        while(ptr!=NULL)
        {
            temp.append(temp.create(ptr->value));
            ptr=ptr->next;
        }
        ptr=x.first;
        while(ptr!=NULL)
        {
            temp.append(temp.create(ptr->value));
            ptr=ptr->next;
        }
        return temp;
    }
    void display()
    {
        node *ptr=first;
        cout<<"\n The list is : ";
        if(first==NULL) cout<<"Empty!";
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
    list l1,l2,l3;
    int value,ch;
    do
    {
        system("cls");
        cout<<"\n 1. List 1  ";
        cout<<"\n 2. List 2  ";
        cout<<"\n 3. Merge   ";
        cout<<"\n 4. Display ";
        cout<<"\n 5. Exit    ";
        cout<<"\n\n Enter>>";
        cin>>ch;
        switch(ch)
        {
            case 1 :
                cout<<"\n Enter a value : ";
                cin>>value;
                l1.append(l1.create(value));
                break;
            case 2 :
                cout<<"\n Enter a value : ";
                cin>>value;
                l2.append(l2.create(value));
                break;
            case 3 :
                l3=l1+l2;
                l3.display();
                getch();
                break;
            case 4 :
                l1.display();
                l2.display();
                l3.display();
                getch();
                break;
        }
    }while(ch!=5);
}
