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

	if(m==p&&n==q)
	{
		cout<<"\n Matrix addition is possible \n";

        cout<<"\n Enter the elements of matrix A : \n\n";
        for(i=0;i<m;i++)
        {
            cout<<" ";
            for(j=0;j<n;j++)
            {
                cin>>a[i][j];
                for(k=1;k<=j+1;k++)
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
                for(k=1;k<=j+1;k++)
                    cout<<"\t";
            }
            cout<<"\n";
        }

        for(i=0;i<m;i++)
            for(j=0;j<n;j++)
                c[i][j]=a[i][j]+b[i][j];

        cout<<"\n Matrix A : \n\n";
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                cout<<" ";
                cout<<a[i][j];
                cout<<"\t";
            }
            cout<<"\n\n";
        }

        cout<<"\n Matrix B : \n\n";
        for(i=0;i<p;i++)
        {
            for(j=0;j<q;j++)
            {
                cout<<" ";
                cout<<b[i][j];
                cout<<"\t";
            }
            cout<<"\n\n";
        }

        cout<<"\n Matrix C : \n\n";
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                cout<<" ";
                cout<<c[i][j];
                cout<<"\t";
            }
            cout<<"\n\n";
        }

	}

	else cout<<"\n Matrix addition not possible \n";
}




