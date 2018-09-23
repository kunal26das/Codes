#include<iostream>
#include<conio.h>

int main()
{
    using namespace std;

	int a[3][3],m,n, b[3][3],p,q, c[3][3], i,j,k;

	cout<<"\n Matrix A : \n";
	cout<<"\n Rows     : ";
	cin>>m;
	cout<<"\n Columns  : ";
	cin>>n;

	cout<<"\n Matrix B : \n";
	cout<<"\n Rows     : ";
	cin>>p;
	cout<<"\n Columns  : ";
	cin>>q;

	if(n==p)
	{
		cout<<"\n Matrix multiplication is possible \n";

		cout<<"\n Enter the elements of matrix A : \n\n";
		for(i=0;i<m;i++)
        {
            cout<<" ";
            for(j=0;j<n;j++)
            {
                cin>>a[i][j];
                for(k=0;k<=j;k++)
                    cout<<"\t";
            }
            cout<<"\n";
        }

        cout<<"\n Enter the elements of matrix B : \n\n";
        for(i=0;i<p;i++)
        {
            cout<<" ";
            for(j=0;j<q;j++)
            {
                cin>>b[i][j];
                for(k=0;k<=j;k++)
                    cout<<"\t";
            }
            cout<<"\n";
        }

        for(i=0;i<m;i++)
            for(j=0;j<q;j++)
            {
                c[i][j]=0;
                for(k=0;k<n;k++)
                    c[i][j]+=a[i][k]*b[k][j];
            }

        cout<<"\n Matrix A : \n\n";
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
                cout<<" "<<a[i][j]<<"\t";
            cout<<"\n\n";
        }

        cout<<"\n Matrix B : \n\n";
        for(i=0;i<p;i++)
        {
            for(j=0;j<q;j++)
                cout<<" "<<b[i][j]<<"\t";
            cout<<"\n\n";
        }

        cout<<"\n Matrix C : \n\n";
        for(i=0;i<m;i++)
        {
            for(j=0;j<q;j++)
                cout<<" "<<c[i][j]<<"\t";
            cout<<"\n\n";
        }

	}

    else cout<<"\n Matrix multiplication not possible \n";
}
