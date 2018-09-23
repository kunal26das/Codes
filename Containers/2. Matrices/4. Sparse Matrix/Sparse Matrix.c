#include<stdio.h>
typedef struct
{
    int value,i,j;
    struct node *next;
}node;
node *first=NULL,*last=NULL;
void add(int,int,int);
void main()
{
    int n,count=0;
    printf("\n Enter the size of matrix : ");
    scanf("%d",&n);

    int i,j,k,matrix[n][n];
    printf("\n Enter the details of matrix : \n");
    for(i=0;i<n;i++)
    {
        printf(" ");
        for(j=0;j<n;j++)
        {
            scanf("%d",&matrix[i][j]);
            if(matrix[i][j]!=0) count++;
            for(k=0;k<=j;k++)
                printf("\t");
        }
        printf("\n");
    }

    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if(matrix[i][j]!=0)
                add(matrix[i][j],i,j);

    node *ptr=first;
    printf("\n The sparse matrix is : \n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(ptr->i==i && ptr->j==j)
            {
                printf(" %d ",ptr->value);
                ptr=ptr->next;
            }
            else printf("   ");
        }
        printf("\n\n");
    }
}
void add(int val,int m,int n)
{
    node *x;
    x=(node*)malloc(sizeof(node));
    x->value=val;
    x->i=m;
    x->j=n;
    x->next=NULL;
    if(first==NULL)
    {
        first=x;
        last=x;
    }
    else
    {
        last->next=x;
        last=x;
    }
}
