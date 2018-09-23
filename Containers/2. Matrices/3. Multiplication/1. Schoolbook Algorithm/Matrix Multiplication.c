#include<stdio.h>
#include<conio.h>

void main()
{
	int a[3][3],m,n, b[3][3],p,q, c[3][3], i,j,k;

	printf("\n Matrix A : \n");
	printf("\n Rows     : ");
	scanf("%i",&m);
	printf("\n Columns  : ");
	scanf("%i",&n);

	printf("\n Matrix B : \n");
	printf("\n Rows     : ");
	scanf("%i",&p);
	printf("\n Columns  : ");
	scanf("%i",&q);

	if(n==p)
	{
		printf("\n Matrix multiplication is possible \n");

		printf("\n Enter the elements of matrix A : \n\n");
		for(i=0;i<m;i++)
        {
            printf(" ");
            for(j=0;j<n;j++)
            {
                scanf("%i",&a[i][j]);
                for(k=0;k<=j;k++)
                    printf("\t");
            }
            printf("\n");
        }

        printf("\n Enter the elements of matrix B : \n\n");
        for(i=0;i<p;i++)
        {
            printf(" ");
            for(j=0;j<q;j++)
            {
                scanf("%i",&b[i][j]);
                for(k=0;k<=j;k++)
                    printf("\t");
            }
            printf("\n");
        }

        for(i=0;i<m;i++)
            for(j=0;j<q;j++)
            {
                c[i][j]=0;
                for(k=0;k<n;k++)
                    c[i][j]+=a[i][k]*b[k][j];
            }

        printf("\n Matrix A : \n\n");
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
                printf(" %i \t",a[i][j]);
            printf("\n\n");
        }

        printf("\n Matrix B : \n\n");
        for(i=0;i<p;i++)
        {
            for(j=0;j<q;j++)
                printf(" %i \t",b[i][j]);
            printf("\n\n");
        }

        printf("\n Matrix C : \n\n");
        for(i=0;i<m;i++)
        {
            for(j=0;j<q;j++)
                printf(" %i \t",c[i][j]);
            printf("\n\n");
        }
    }
	else printf("\n Matrix multiplication not possible \n");
}
