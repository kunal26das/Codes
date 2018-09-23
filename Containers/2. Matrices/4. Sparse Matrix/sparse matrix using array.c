#include<stdio.h>
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

    int row=0,sparse[count][3];
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        {
            if(matrix[i][j]!=0)
            {
                sparse[row][0]=matrix[i][j];
                sparse[row][1]=i;
                sparse[row][2]=j;
                row++;
            }
        }

    row=0;
    printf("\n The sparse matrix is : \n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(sparse[row][1]==i && sparse[row][2]==j)
            {
                printf(" %d ",sparse[row][0]);
                row++;
            }
            else printf("   ");
        }
        printf("\n\n");
    }
}
