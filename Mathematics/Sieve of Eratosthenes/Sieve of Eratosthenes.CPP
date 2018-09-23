#include<iostream>
#include<conio.h>
#include<math.h>

using namespace std;

int main()
{
	int n,root,i,j;

	cout<<"\n Find prime numbers from 2 to : ";
	cin>>n;
    root=sqrt(n);

    int prime[n+1];
	for(i=0;i<=n;i++) prime[i]=i;

	for(i=2;i<=root;i++)
        if(prime[i]!=0)
            for(j=i*i;j<=n;j+=i)
				prime[j]=0;

	cout<<"\n Prime numbers from 2 to "<<n<<" are : ";
	for(i=2;i<=n;i++)
		if(prime[i]!=0)
			cout<<prime[i]<<", ";

	getch();
}
