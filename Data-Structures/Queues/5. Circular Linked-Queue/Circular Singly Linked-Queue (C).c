#include<stdlib.h>
#include<stdio.h>

struct node
{
    int value;
    struct node *next;
};typedef struct node node;

struct queue{node *front;};
typedef struct queue queue;

void initqueue(queue *que)
{(*que).front=NULL;}

int empty(queue que)
{
    if(!que.front)
    return 1;
    return 0;
}

void destroy(node *ptr)
{
    if(ptr->next==front)
    {
        delete ptr;
        return;
    }
    destroy(ptr->next);
    delete ptr;
}

void enqueue(int value)
{
    node *x=new node(value);
    if(front)
    {
        node *ptr=front;
        while(ptr->next!=front)
        ptr=ptr->next;
        ptr->next=x;
    }
    else front=x;
    x->next=front;
}

int dequeue()
{
    node *temp=front;
    int value=front->value;
    if(front->next!=front)
    {
        node *ptr=front;
        while(ptr->next!=front)
        ptr=ptr->next;
        ptr->next=front->next;
        front=front->next;
    }
    else front=NULL;
    delete temp;
    return value;
}

void display()
{
    node *ptr=front;
    do
    {
        printf(ptr->value<<", ";
        ptr=ptr->next;
    }while(ptr!=front);
}

int main()
{
    queue que;
    int value,ch;
    do
    {
        system("cls");
        printf("\n 1. Peek ");
        printf("\n 2. Enqueue ");
        printf("\n 3. Dequeue ");
        printf("\n 4. Display ");
        printf("\n 5. End Program ");
        printf("\n\n Enter>>");
        scanf("%d",&ch); switch(ch)
        {
            case 1 :
            if(!empty(que)) printf("\n Front is : %d",peek(que));
            else printf("\n Queue is empty!");
            printf("\n "); system("pause");

            case 1 :
            printf("\n Enter a value : ");
            scanf("%d",&value);
            que.enqueue(value);
            break;

            case 2 :
            if(!que.empty())
            printf("\n Dequeued value is : %d",que.dequeue());
            else printf("\n Queue is empty!");
            printf("\n "); system("pause");
            break;

            case 3 :
            printf("\n Queue is : ");
            if(!que.empty()) que.display();
            else printf("empty!");
            printf("\n "); system("pause");
            break;

            case 0 :
            if(!empty(que));
            {
                destroy(que.front);
                que.front=NULL;
            }
            break;
        }
    }while(ch!=4);
}
