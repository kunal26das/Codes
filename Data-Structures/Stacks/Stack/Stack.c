#include<stdio.h>
#include<conio.h>

int stack[10],top=0,size=5;

void push();
void pop();
void display();

void main()
{
    int choice;
    do
    {
        system("cls");
        printf("\n    MENU :- \n");
        printf("\n 1. Push \n");
        printf("\n 2. Pop \n");
        printf("\n 3. Display \n");
        printf("\n 4. Exit \n");
        printf("\n    Enter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1 : push();    break;
            case 2 : pop();        break;
            case 3 : display();    break;
        }
    }while(choice!=4);
}

void push()
{
    if(top<size)
    {
        top=top+1;
        printf("\n    Push value : ");
        scanf("%d",&stack[top]);
    }
    else
    {
        printf("\n    Stack is overflowing!");
        getch();
    }
}

void pop()
{
    if(top>0)
    {
        printf("\n    Popped value : %d",stack[top]);
        top=top-1;
    }
    else printf("\n    Stack is underflowing!");
    getch();
}

void display()
{
    int i;
    if(top>0)
    {
        printf("\n    The stack is : ");
        for(i=top;i>0;i--)
            printf("\n\n    %d",stack[i]);
    }
    else printf("\n    Stack is underflowing!");
    getch();
}
