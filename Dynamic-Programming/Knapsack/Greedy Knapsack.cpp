#include<iostream>
#include<stdlib.h>
#include<conio.h>

using namespace std;

struct object
{
    float ratio;
    float weight;
    float profit;
    object *next;
};

class list
{
    object *first;
    object *last;
    object* findnode(object *x)
    {
        object *ptr=first;
        while(ptr->next!=NULL)
        {
            if(ptr->next->ratio<x->ratio)
            ptr=ptr->next;
            else if(ptr->next->ratio==x->ratio)
            {
                if(ptr->next->weight>x->weight)
                ptr=ptr->next;
                else if(ptr->next->profit<x->profit)
                ptr=ptr->next;
            }
            else break;
        }
        return ptr;
    }
    public:
    list()
    {
        first=NULL;
        last=NULL;
    }
    void add(object *x)
    {
        if(first==NULL)
        {
            first=x;
            last=x;
        }
        else if(x->ratio>first->ratio)
        {
            x->next=first;
            first=x;
        }
        else if(x->ratio<last->ratio)
        {
            last->next=x;
            last=x;
        }
        else
        {
            object *ptr=findnode(x);
            x->next=ptr->next;
            ptr->next=x;
        }
    }
    void display()
    {
        int n=1;
        object *ptr=first;
        while(ptr!=NULL)
        {
            cout<<"\n "<<n++<<"\t";
            cout<<ptr->weight<<"\t";
            cout<<ptr->profit<<"\t";
            cout<<ptr->ratio;
            ptr=ptr->next;
        }
    }
    friend class greedy;
}objects;

object* create(float w,float p)
{
    object *x;
    x=new object;
    x->next=NULL;
    x->ratio=p/w;
    x->weight=w;
    x->profit=p;
    return x;
}

class greedy
{
    float capacity;
    public:
    greedy(float c){capacity=c;}
    void change(int cap){capacity=cap;}
    void solution()
    {
        int n=1;
        float max=0,total=0;
        float space=capacity;
        object *ptr=objects.first;
        while(ptr!=NULL&&space)
        {
            cout<<"\n "<<n++<<"\t";
            cout<<ptr->weight<<"\t";
            cout<<ptr->profit<<"\t";
            cout<<ptr->ratio<<"\t";
            if(space>=ptr->weight)
            {
                cout<<"100%";
                space-=ptr->weight;
                total+=ptr->profit;
            }
            else
            {
                cout<<(int)((space/ptr->weight)*100)<<"%";
                total+=(ptr->ratio)*space;
                space=0;
            }
            max+=ptr->profit;
            ptr=ptr->next;
        }
        cout<<"\n\n space left     : ";
        cout<<space<<"/"<<capacity;
        cout<<"\n\n total profit   : ";
        cout<<total;
    }
};

int main()
{
	int ch,i,capacity;
	float weight,profit;
	greedy knapsack(500);
	do
	{
		system("cls");
		cout<<"\n 1. Object ";
		cout<<"\n 2. Capacity ";
		cout<<"\n 3. Solution ";
		cout<<"\n 4. Display ";
		cout<<"\n 5. Exit ";
		cout<<"\n\n Enter>>";
		cin>>ch;
		switch(ch)
		{
			case 1 :
			cout<<"\n Enter weight : "; cin>>weight;
			cout<<"\n Enter profit : "; cin>>profit;
			objects.add(create(weight,profit));
			break;

			case 2 :
            cout<<"\n Enter new capacity : ";
            cin>>capacity;
            knapsack.change(capacity);
            break;

			case 3 :
            cout<<"\n #\tWeight\tProfit\tRatio\tTake\n ";
            for(i=0;i<35;i++) cout<<"-";
            knapsack.solution();
            getch();
			break;

			case 4 :
            cout<<"\n #\tWeight\tProfit\tRatio\n ";
            for(i=0;i<30;i++) cout<<"-";
            objects.display();
            getch();
			break;
		}
	}while(ch!=5);
}
