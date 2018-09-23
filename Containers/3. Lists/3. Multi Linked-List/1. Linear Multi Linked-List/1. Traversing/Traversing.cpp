#include<iostream>
#include<stdlib.h>
#include<conio.h>

using namespace std;

struct node
{
    string name;
    int age;
    node *nextname;
    node *nextage;
};

class list
{
    node *alpha,*beta;
    node *young,*old;
    node* findname(string name)
    {
        node *ptr=alpha;
        while(ptr!=NULL)
        {
            if(ptr->nextname->name<name)
            ptr=ptr->nextname;
            else break;
        }
        return ptr;
    }
    node* findage(int age)
    {
        node *ptr=young;
        while(ptr!=NULL)
        {
            if(ptr->nextage->age<age)
            ptr=ptr->nextage;
            else break;
        }
        return ptr;
    }
    public:
    list()
    {
        alpha=NULL;
        young=NULL;
        beta=NULL;
        old=NULL;
    }
    int empty()
    {
        if(alpha==NULL) return 1;
        if(young==NULL) return 1;
        return 0;
    }
    void insert(node *x)
    {
        node *ptr;
        if(alpha==NULL)
        {
            alpha=x;
            beta=x;
        }
        else
        {
            if(x->name<alpha->name)
            {
                x->nextname=alpha;
                alpha=x;
            }
            else if(x->name>beta->name)
            {
                beta->nextname=x;
                beta=x;
            }
            else
            {
                ptr=findname(x->name);
                x->nextname=ptr->nextname;
                ptr->nextname=x;
            }
        }
        if(young==NULL)
        {
            young=x;
            old=x;
        }
        else
        {
            if(x->age<young->age)
            {
                x->nextage=young;
                young=x;
            }
            else if(x->age>old->age)
            {
                old->nextage=x;
                old=x;
            }
            else
            {
                ptr=findage(x->age);
                x->nextage=ptr->nextage;
                ptr->nextage=x;
            }
        }
    }
    void showbyname()
    {
        node *ptr=alpha;
        while(ptr!=NULL)
        {
            cout<<ptr->name<<", ";
            ptr=ptr->nextname;
        }
    }
    void showbyage()
    {
        node *ptr=young;
        while(ptr!=NULL)
        {
            cout<<ptr->age<<", ";
            ptr=ptr->nextage;
        }
    }
};

node* create(string name,int age)
{
    node *x=new node;
    x->name=name;
    x->age=age;
    x->nextname=NULL;
    x->nextage=NULL;
    return x;
}

int main()
{
    list lst;
    int ch,age;
    string name;
    do
    {
        system("cls");
        cout<<"\n 1. Add  ";
        cout<<"\n 2. Name ";
        cout<<"\n 3. Age  ";
        cout<<"\n 4. Exit ";
        cout<<"\n\n Enter>>";
        cin>>ch;
        switch(ch)
        {
            case 1:
            cout<<"\n Enter name : "; cin>>name;
            cout<<"\n Enter age  : "; cin>>age;
            lst.insert(create(name,age));
            break;

            case 2:
            cout<<"\n The list is : ";
            if(!lst.empty())
            lst.showbyname();
            else cout<<"empty!";
            getch();
            break;

            case 3:
            cout<<"\n The list is : ";
            if(!lst.empty())
            lst.showbyage();
            else cout<<"empty!";
            getch();
            break;
        }
    }while(ch!=4);
}
