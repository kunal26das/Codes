#include<iostream>
#include<stdlib.h>
#include<conio.h>

using namespace std;

class queue
{
    int *array;
    int size;
    int front;
    int rear;
    public:
    queue(int s)
    {
        array=new int[s];
        front=-1;
        rear=-1;
        size=s;
    }
    int empty()
    {
        if(front==-1)
        return 1;
        return 0;
    }
    int full()
    {
        if(rear==size-1)
        return 1;
        return 0;
    }
    void enqueue(int value)
    {
        if(front==-1) front++;
        array[++rear]=value;
    }
    int dequeue()
    {
        int temp=array[front];
        if(front==rear)
        {
            front=-1;
            rear=-1;
        }
        else front++;
        return temp;
    }
    void display()
    {
        for(int i=front;i<=rear;i++)
        cout<<array[i]<<", ";
    }
};

int main()
{
    queue que(5);
	int ch,value;
	do
	{
		system("cls");
		cout<<"\n 1. Enqueue ";
		cout<<"\n 2. Dequeue ";
		cout<<"\n 3. Display ";
		cout<<"\n 4. Exit    ";
		cout<<"\n\n Enter>>";
		cin>>ch;
		switch(ch)
		{
			case 1:
			if(!que.full())
            {
                cout<<"\n Enter a value : ";
                cin>>value;
                que.enqueue(value);
            }
            else
            {
                cout<<"\n Queue is full! ";
                getch();
            }
			break;

			case 2:
			if(!que.empty())
            cout<<"\n Dequeued value : "<<que.dequeue();
            else cout<<"\n Queue is empty! ";
            getch();
			break;

			case 3:
			cout<<"\n Queue is : ";
            if(!que.empty())
            que.display();
            else cout<<"empty! ";
            getch();
			break;
		}
	}while(ch!=4);
}
