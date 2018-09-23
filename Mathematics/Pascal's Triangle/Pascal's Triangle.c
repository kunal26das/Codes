#include<stdio.h>

void main()
{
    int i,j,n=10;
    for(i=1;i<=n;i++)
    {
        printf("\n\t");
        for(j=1;j<=(n-i);j++)
            printf(" ");
        for(j=1;j<=i/2;j++)
            printf("%d ",j);
        if(i%2) j=i/2;
        else    j=i/2-1;
        for(j;j>=1;j--)
            printf("%d ",j);
    }
    printf("\n");
}
