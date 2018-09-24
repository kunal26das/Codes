#include<iostream>
#include<stdlib.h>
#include<conio.h>

using namespace std;

struct vertex
{
    string name;
    vertex *next;
};

struct edge
{
    float cost;
    vertex *src;
    vertex *dst;
    edge *next;
};

class directed
{
    vertex *v;
    edge *e;
    public:
    directed()
    {
        v=NULL;
        e=NULL;
    }
    void addvertex(vertex *x)
    {
        if(v==NULL) v=x;
        else
        {
            vertex *ptr=v;
            while(ptr->next!=NULL)
            ptr=ptr->next;
            ptr->next=x;
        }
    }
    void addedge(edge *x)
    {
        if(e==NULL) e=x;
        else
        {
            edge *ptr=e;
            while(ptr->next!=NULL)
            ptr=ptr->next;
            ptr->next=x;
        }
    }
    vertex* findvertex()
    {

    }
    void display()
    {
        vertex *ptr=v;
        while(ptr!=NULL)
        {
            cout<<"\n ";
            cout<<ptr->name;
            ptr=ptr->next;
        }
    }
};

vertex* newvertex(string name)
{
    vertex *x=new vertex;
    x->name=name;
    x->next=NULL;
    return x;
}

edge* newedge(vertex *x,vertex *y,float c)
{
    edge *x=new edge;
    edge->cost=c;
    edge->source=x;
    edge->destin=y;
    edge->next=NULL;
    return x;
}

int main()
{
    int ch;
    string name;
    directed graph;
    do
    {
        system("cls");
        cout<<"\n 1. Vertex ";
        cout<<"\n 2. Edge ";
        cout<<"\n 3. Display ";
        cout<<"\n 4. Exit ";
        cout<<"\n\n Enter>>";
        cin>>ch;
        switch(ch)
        {
            case 1 :
            cout<<"\n Enter vertex name : ";
            cin>>name;
            graph.add(newvertex(name));
            break;

            case  :
            cout<<"\n
            break;

            case 3 :
            cout<<"\n List of places : ";
            graph.display();
            getch();
            break;
        }
    }while(ch!=4);
}
