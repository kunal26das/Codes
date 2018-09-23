#include<stdio.h>
void main()
{
    int m,n, p,q, i,j,k;

    printf("\n Matrix A : \n");
    printf("\n Rows = ");
    scanf("%d",&m);
    printf("\n Cols = ");
    scanf("%d",&n);

    printf("\n Matrix B : \n");
    printf("\n Rows = ");
    scanf("%d",&p);
    printf("\n Cols = ");
    scanf("%d",&q);

    if(n!=p)
    {
        printf("\n Matrix Multiplication is not possible \n");
        printf("\n Press any key to exit... \n");
        getch();
        return;
    }

    int A[m][n];
    printf("\n Enter the elements of matrix A : \n");
    for(i=0;i<m;i++)
    {
        printf(" ");
        for(j=0;j<n;j++)
        {
            scanf("%d",&A[i][j]);
            for(k=0;k<=j;k++)
                printf("\t");
        }
        printf("\n");
    }

    int B[p][q];
    printf("\n Enter the elements of matrix B : \n");
    for(i=0;i<p;i++)
    {
        printf(" ");
        for(j=0;j<q;j++)
        {
            scanf("%d",&B[i][j]);
            for(k=0;k<=j;k++)
                printf("\t");
        }
        printf("\n");
    }

    int C[m][q];
    int *x=&A[0][0],*y=&B[0][0],*z=&C[0][0];
    for(i=0;i<m;i++)
        for(j=0;j<q;j++)
        {
            *(z+i*m+j)=0;
            for(k=0;k<n;k++)
                *(z+i*m+j)+=*(x+i*n+k)**(y+k*q+j);
        }

    printf("\n Matrix C : \n");
    for(i=0;i<m;i++)
    {
        printf(" ");
        for(j=0;j<q;j++)
        {
            printf("%d",*(z+i*m+j));
            printf("\t");
        }
        printf("\n");
    }
}
