#include<iostream>
#include<stdlib.h>
#include<conio.h>

using namespace std;

class Knights
{
    int n;
    int board[25][25];
    int solve(int row,int col,int k)
    {
        board[row][col]=k;
        for(int i=2,j=1;i>=1&&j<=2;i--,j++)
        {
            if(check(row-i,col-j))
            {
                if(!solve(row-i,col-j,k+1))
                board[row-i][col-j]=0;
                else return 1;
            }
            if(check(row+i,col-j))
            {
                if(!solve(row+i,col-j,k+1))
                board[row+i][col-j]=0;
                else return 1;
            }
            if(check(row-i,col+j))
            {
                if(!solve(row-i,col+j,k+1))
                board[row-i][col+j]=0;
                else return 1;
            }
            if(check(row+i,col+j))
            {
                if(!solve(row+i,col+j,k+1))
                board[row+i][col+j]=0;
                else return 1;
            }
        }
        if(k==(n*n)) return 1;
        else return 0;
    }
    int check(int row,int col)
    {
        if(row>=0&&row<n&&col>=0&&col<n)
        if(!board[row][col])
        return 1;
        return 0;
    }
    void display()
    {
        int i,j,k;
        system("cls");
        cout<<"\n "; for(k=0;k<n;k++)
        {cout<<" ----";} cout<<" \n";
        for(i=0;i<n;i++)
        {
            cout<<" |";
            for(j=0;j<n;j++)
            {
                if(board[i][j]>=0&&board[i][j]<=9)
                cout<<"  "; else cout<<" ";
                cout<<board[i][j]<<" |";
            }
            cout<<"\n "; for(k=0;k<n;k++)
            {cout<<" ----";} cout<<endl;
        }
        getch();
    }
    public:
    Knights(int knights)
    {
        n=knights;
        int i,j,flag=0;
        for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        board[i][j]=0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(!solve(i,j,1))
                board[i][j]=0;
                else
                {
                    display();
                    flag=1;
                    break;
                }
            }
            if(flag) break;
        }
    }
};

int main()
{
    Knights tour(8);
}
