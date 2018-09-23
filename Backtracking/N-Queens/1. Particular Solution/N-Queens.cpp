#include<iostream>
#include<stdlib.h>
#include<conio.h>

using namespace std;

class N
{
    int n,board[25][25];
    int solve(int row,int col,int q)
    {
        board[row][col]=q;
        for(int i=0;i<n;i++)
        if(check(row+1,i))
        {
            if(!solve(row+1,i,q+1))
            board[row+1][i]=0;
            else return 1;
        }
        if(q==n) return 1;
        else     return 0;
    }
    int check(int row,int col)
    {
        int i,j;
        for(i=0;i<row;i++)
        if(board[i][col]) return 0;
        for(i=row,j=col;i>=0&&j>=0;i--,j--)
        if(board[i][j]) return 0;
        for(i=row,j=col;i>=0&&j<n;i--,j++)
        if(board[i][j]) return 0;
        return 1;
    }
    void display()
    {
        int i,j,k;
        cout<<"\n "; for(k=0;k<n;k++)
        {cout<<" ---";} cout<<" \n";
        for(i=0;i<n;i++)
        {
            cout<<" |";
            for(j=0;j<n;j++)
            {
                if(board[i][j])
                cout<<" Q |";
                else cout<<"   |";
            }
            cout<<"\n "; for(k=0;k<n;k++)
            {cout<<" ---";} cout<<" \n";
        }
    }
    public:
    N(int queens)
    {
        int i,j;
        n=queens;
        for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        board[i][j]=0;
        for(i=0;i<n;i++)
        {
            if(!solve(0,i,1))
            board[0][i]=0;
            else
            {
                display();
                break;
            }
        }
    }
};

int main(){N queens(8);}
