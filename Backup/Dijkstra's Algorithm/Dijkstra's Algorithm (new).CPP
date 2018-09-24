#include<iostream>
#include<stdlib.h>
#include<conio.h>

using namespace std;

class vertex
{
    public:
    int sno;
    string name;
    vertex *next;
    vertex()
    {
        sno=0;
        next=NULL;
        name="Null";
    }
    vertex(int _sno,string _name)
    {
        sno=_sno;
        next=NULL;
        name=_name;
    }
};

class LinkedList
{
    vertex *first,*last;
    public:
    LinkedList()
    {
        last=NULL;
        first=NULL;
    }
    vertex* head(){return first;}
    vertex* tail(){return last;}
    void Append(vertex *x)
    {
        if(last)
        last->next=x;
        else first=x;
        last=x;
    }
    vertex* GetVertex(int sno)
    {
        vertex *ptr=first;
        while(ptr&&ptr->sno!=sno)
        ptr=ptr->next;
        return ptr;
    }
};

class JaggedList
{
    class tail
    {
        public:
        float cost;
        tail *next;
        vertex *dst;
        tail(vertex *_dst,float _cost)
        {
            dst=_dst;
            next=NULL;
            cost=_cost;
        }
    };
    class head
    {
        public:
        head *down;
        tail *next;
        vertex *src;
        head(vertex *_src)
        {
            src=_src;
            down=NULL;
            next=NULL;
        }
    }*first,*last;
    public:
    JaggedList()
    {
        last=NULL;
        first=NULL;
    }
    void Append(vertex *x)
    {
        if(last)
        {
            last->down=new head(x);
            last=last->down;
        }
        else
        {
            first=new head(x);
            last=first;
        }
    }
    void InsertEdge(vertex *src,float cost,vertex *dst)
    {
        head *ptr=first;
        while(ptr&&ptr->src!=src)
        ptr=ptr->down;
        if(!ptr) return;
        tail *adj=ptr->next;
        if(adj)
        {
            while(adj->next)
            {
                if(adj->dst==dst) return;
                adj=adj->next;
            }
            adj->next=new tail(dst,cost);
        }
        else ptr->next=new tail(dst,cost);
    }
    vertex* GetVertex(int sno)
    {
        head *ptr=first;
        while(ptr&&ptr->src->sno!=sno)
        ptr=ptr->down;
        if(ptr) return ptr->src;
        else return NULL;
    }
    vertex* GetEdge(int src,int sno)
    {
        head *ptr=first;
        while(ptr&&ptr->src->sno!=src)
        ptr=ptr->down;
        if(!ptr) return NULL;
        tail *adj=ptr->next;
        for(int i=0;i<sno-1;i++)
        if(adj) adj=adj->next;
        if(adj) return adj->dst;
        else return NULL;
    }
    float GetEdgeWeight(int src,int sno)
    {
        head *ptr=first;
        while(ptr&&ptr->src->sno!=src)
        ptr=ptr->down;
        if(!ptr) return 0;
        tail *adj=ptr->next;
        for(int i=0;i<sno-1;i++)
        if(adj) adj=adj->next;
        if(adj) return adj->cost;
        else return 0;
    }
    vertex* GetEdgeBetween(int src,int dst)
    {
        head *ptr=first;
        while(ptr&&ptr->src->sno!=src)
        ptr=ptr->down;
        if(!ptr) return NULL;
        tail *adj=ptr->next;
        if(adj)
        {
            while(adj&&adj->dst->sno!=dst)
            adj=adj->next;
            if(!adj) return NULL;
            else return adj->dst;
        }
        else return NULL;
    }
};

class Graph
{
    int vertices;
    LinkedList vertexes;
    JaggedList edges;
    public:
    Graph(){vertices=0;}

    void InsertVertex(string name)
    {
        vertices++;
        vertex *x=new vertex(vertices,name);
        vertexes.Append(x);
        edges.Append(x);
    }

    void InsertEdge(vertex *src,float cost,vertex *dst)
    {edges.InsertEdge(src,cost,dst);}

    vertex* GetVertex(int src)
    {return vertexes.GetVertex(src);}

    vertex* GetEdge(int src,int sno)
    {return edges.GetEdge(src,sno);}

    float GetEdgeWeight(int src,int sno)
    {return edges.GetEdgeWeight(src,sno);}

    vertex* GetEdgeBetween(int src,int dst)
    {return edges.GetEdgeBetween(src,dst);}
};

JaggedList Prims(Graph G,int start)
{
    int src=0;
    vertex *temp;

    JaggedList MST;
    while(G.GetVertex(++src))
    MST.Append(G.GetVertex(src));

    int matrix[src][4]; src=0;
    while(G.GetVertex(++src))
    {
        matrix[src][0]=src;
        matrix[src][1]=0;
        matrix[src][2]=INT_MAX;
    }

    return MST;
}

void DisplayVertexesof(Graph G)
{
    int src=0; vertex *temp;
    cout<<"\n Set of vertexes : {";
    while(G.GetVertex(++src))
    {
        temp=G.GetVertex(src);
        cout<<src<<"."<<temp->name<<",";
    }
    cout<<"Null}\n ";
}

void DisplayEdgesof(Graph G)
{
    float cost;
    int i,src=0;
    vertex *temp;
    cout<<"\n Adjacency list :\n ";
    while(G.GetVertex(++src))
    {
        i=0; temp=G.GetVertex(src);
        cout<<temp->name<<" : {";
        while(G.GetEdge(src,++i))
        {
            temp=G.GetEdge(src,i);
            cost=G.GetEdgeWeight(src,i);
            cout<<i<<"."<<temp->name;
            cout<<"("<<cost<<"),";
        }
        cout<<"NULL}\n ";
    }
}

void DisplayAdjacencyList(JaggedList lst)
{
    float cost;
    int i,src=0;
    vertex *temp;
    cout<<"\n Adjacency list :\n ";
    while(lst.GetVertex(++src))
    {
        i=0; temp=lst.GetVertex(src);
        cout<<temp->name<<" : {";
        while(lst.GetEdge(src,++i))
        {
            temp=lst.GetEdge(src,i);
            cost=lst.GetEdgeWeight(src,i);
            cout<<i<<"."<<temp->name;
            cout<<"("<<cost<<"),";
        }
        cout<<"NULL}\n ";
    }
}

int main()
{
    Graph G;
    float cost;
    string name;
    vertex *temp;
    int ch,src,dst;
    JaggedList lst;
    do
    {
        system("cls");
        cout<<"\n 1. Insert vertex ";
        cout<<"\n 2. Insert edge ";
        cout<<"\n .. Minimum-spanning tree ";
        cout<<"\n 3. Prim's algorithm ";
        cout<<"\n 4. Kruskal's algorithm ";
        cout<<"\n .. Single-source shortest path ";
        cout<<"\n 5. Dijkstra's algorithm ";
        cout<<"\n 6. Bellman-Ford algorithm ";
        cout<<"\n .. All-pair shortest path ";
        cout<<"\n 7. Floyd-Warshall algorithm ";
        cout<<"\n 8. List of vertexes ";
        cout<<"\n 9. Adjacency list ";
        cout<<"\n 0. End program ";
        cout<<"\n\n Enter>>";
        cin>>ch; switch(ch)
        {
            case 1 :
            cout<<"\n Enter vertex string : ";
            cin>>name; G.InsertVertex(name);
            break;

            case 2 :
            DisplayVertexesof(G);
            cout<<"\n Enter source vertex no.: "; cin>>src;
            cout<<"\n Enter destination vertex no.: "; cin>>dst;
            cout<<"\n Enter weight : "; cin>>cost;
            if(G.GetVertex(src)&&G.GetVertex(dst))
            G.InsertEdge(G.GetVertex(src),cost,G.GetVertex(dst));
            DisplayEdgesof(G);
            system("pause");
            break;

            case 3 :
            cout<<"\n Enter starting vertex no.: "; cin>>src;
            if(G.GetVertex(src))
            {
                lst=Prims(G,src);
                DisplayEdgesof(G);
                DsiplayAdjacencyList(lst);
            }
            else cout<<"\n Vertex not found.\n ";
            system("pause");
            break;

            case 4 :
            break;

            case 5 :
            break;

            case 6 :
            break;

            case 7 :
            break;

            case 8 :
            DisplayVertexesof(G);
            system("pause");
            break;

            case 9 :
            DisplayEdgesof(G);
            system("pause");
            break;
        }
    }while(ch!=0);
}
