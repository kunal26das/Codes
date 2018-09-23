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
    void insert(node *ptr)
    {
        if(ptr!=NULL)
        {
            int value;
            cout<<"\n Enter a value : ";
            cin>>value;
            node *x=create(value);
            if(ptr==last) append(x);
            else
            {
                x->next=ptr->next;
                ptr->next=x;
            }
        }
        else cout<<"\n Insertion not possible!";
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
        getch();
    }
};
node* create(int value)
{
    node *x=new node;
    x->value=value;
    x->next=NULL;
    return x;
}
int main()
{
    list lst;
    node *x;
    int value,ch;
    do
    {
        system("cls");
        cout<<"\n 1. Add     ";
        cout<<"\n 2. Insert  ";
        cout<<"\n 3. Display ";
        cout<<"\n 4. Exit    ";
        cout<<"\n\n Enter>>";
        cin>>ch;
        switch(ch)
        {
            case 1:
            cout<<"\n Enter a value : ";
            cin>>value;s
            lst.append(create(value));
            break;

            case 2:
            cout<<"\n Enter a value : ";
            cin>>value;
            lst.insert(lst.search(value));
            lst.display();
            getch();
            break;

            case 3:
            lst.display();
            getch();
            break;
        }
    }while(ch!=4);
}
