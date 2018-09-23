#include<stdlib.h>
#include<stdio.h>

struct list
{
    int *array;
    int index;
    int size;
};
typedef struct list list;

void initlist(list *lst,int s)
{
    (*lst).array=(int*)malloc(sizeof(int)*s);
    (*lst).index=-1; (*lst).size=s;
}

int empty(list lst)
{
    if(lst.index==-1)
    return 1;
    return 0;
}

int full(list lst)
{
    if(lst.index==lst.size-1)
    return 1; return 0;
}

void append(list *lst,int value)
{(*lst).array[++(*lst).index]=value;}

void bubblesort(list lst)
{
    int i,j;
    void swap(int *p,int *q)
    {
        int temp=*p;
        *p=*q; *q=temp;
    }
    for(i=0;i<=lst.index-1;i++)
    for(j=0;j<=lst.index-1-i;j++)
    if(lst.array[j]>lst.array[j+1])
    swap(&lst.array[j],&lst.array[j+1]);
}

void display(list lst)
{
    int i;
    for(i=0;i<=lst.index;i++)
    printf("%d, ",lst.array[i]);
}

void destroy(list *lst)
{
    (*lst).index=-1;
    free((*lst).array);
    (*lst).array=(int*)malloc(sizeof((*lst).size));
}

int main()
{
    list lst;
    int ch,value;
    initlist(&lst,5);
    do
    {
        system("cls");
        printf("\n 1. Append ");
        printf("\n 2. Bubble Sort ");
        printf("\n 3. Display ");
        printf("\n 4. End Program ");
        printf("\n\n Enter>>");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1 :
            if(!full(lst))
            {
                printf("\n Enter a value : ");
                scanf("%d",&value);
                append(&lst,value);
            }
            else
            {
                printf("\n Array is full!\n ");
                system("pause");
            }
            break;

            case 2 :
            printf("\n Array is : ");
            if(!empty(lst))
            {
                bubblesort(lst);
                display(lst);
            }
            else printf("empty!");
            printf("\n "); system("pause");
            break;

            case 3 :
            printf("\n Array is : ");
            if(!empty(lst)) display(lst);
            else printf("empty!");
            printf("\n "); system("pause");
            break;

            case 0 :
            destroy(&lst);
            break;
        }
    }while(ch!=4);
}
