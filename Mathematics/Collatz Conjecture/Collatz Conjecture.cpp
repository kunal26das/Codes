#include<iostream>
#include<stdlib.h>

using namespace std;

int main()
{
    int c,j,i=1;
    while(i)
    {
        c=0;
        j=i;
        cout<<"\n ";
        cout<<i<<" -> ";
        while(j>1)
        {
            c++;
            cout<<j<<", ";
            if(j%2) j=(j*3)+1;
            else j/=2;
        }
        cout<<1<<" ("<<c<<") ";
        //system("pause");
        i++;
    }
}
