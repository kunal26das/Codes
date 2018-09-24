#include<iostream.h>
#include<conio.h>
#include<stdlib.h>

class Stack
{
	private:
	int *t;
	int length, top;

	public:
	Stack(int len)
	{
		length=len;
		t=new int[len];
		top=-1;
	}

	~Stack()
	{delete []t;}

	void push(int d)
	{if(top<length-1)
	{
		top++;
		t[top]=d;
	}}

	int pop()
	{if(top>-1)
	{
		top--;
		return t[top+1];
	}}

	void printstack()
	{
		int cur=top;
		while(cur>-1)
		{
			cout<<t[cur]<<endl;
			cur--;
		}
	}
};

void MoveTowerofHanoi(int disk, Stack *source, Stack *destination, Stack *temp)
{
    if (disk==1)
    destination->push(source->pop());

    else
    {
        MoveTowerofHanoi(disk-1,source,temp,destination);
        destination->push(source->pop());
        MoveTowerofHanoi(disk-1,temp,destination,source);
    }

	cout<<"Printing Destination!"<<endl;
	destination->printstack();
}

void main()
{
	clrscr();
	int disks;
	cout<<"Enter the number of disks!"<<endl;
	cin>>disks;
	Stack *source=new Stack(disks);
	for(int i=0; i<disks; i++)
	source->push(disks-i);
	cout<<"Printing Source!"<<endl;
	source->printstack();
	Stack *temp=new Stack(disks);
	Stack *destination=new Stack(disks);
	MoveTowerofHanoi(disks,source,temp,destination);
	getch();
}