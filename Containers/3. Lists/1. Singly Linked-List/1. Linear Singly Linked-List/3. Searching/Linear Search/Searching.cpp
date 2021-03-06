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
    node* add(int value)
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
    node *x;
    int value,ch;
    do
    {
        system("cls");
        cout<<"\n 1. Add     ";
        cout<<"\n 2. Search  ";
        cout<<"\n 3. Display ";
        cout<<"\n 4. Exit    ";
        cout<<"\n\n Enter>>";
        cin>>ch;
        switch(ch)
        {
            case 1 :
                cout<<"\n Enter a value : ";
                cin>>value;
                l.add(value);
                break;
            case 2 :
                cout<<"\n Enter a value : ";
                cin>>value;
                x=l.search(value);
                getch();
                break;
            case 3 :
                l.display();
                getch();
                break;
        }
    }while(ch!=4);
}
