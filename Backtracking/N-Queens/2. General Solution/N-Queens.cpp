#include<iostream>
#include<stdlib.h>
#include<conio.h>

using namespace std;

class solution
{
    public:
    int matrix[25][25];
    solution *next;
    solution(int n)
    {
        int i,j;
        for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        matrix[i][j]=0;
        next=NULL;
    }
};

class N
{
    int n;
    solution *first;
    solution *last;
    void append(solution board)
    {
        solution *x=new solution(8);
        for(int i=0;i<n;i++) for(int j=0;j<n;j++)
        x->matrix[i][j]=board.matrix[i][j];
        if(first!=NULL) last->next=x;
        else first=x; last=x;
    }
    int solve(solution board,int row,int col,int q=1)
    {
        board.matrix[row][col]=q;
        for(int i=0;i<n;i++)
        if(check(board,row+1,i))
        if(!solve(board,row+1,i,q+1))
        board.matrix[row+1][i]=0;
        if(q==n)
        {
            append(board);
            return 1;
        }
        else return 0;
    }
    int check(solution board,int row,int col)
    {
        int i,j;
        for(i=0;i<row;i++)
        if(board.matrix[i][col]) return 0;
        for(i=row,j=col;i>=0&&j>=0;i--,j--)
        if(board.matrix[i][j])   return 0;
        for(i=row,j=col;i>=0&&j<n;i--,j++)
        if(board.matrix[i][j])   return 0;
        return 1;
    }
    public:
    N(int queens)
    {
        n=queens;
        last=NULL;
        first=NULL;
        solution board(n);
        for(int j=0;j<n;j++)
        solve(board,0,j);
    }
    int count()
    {
        int c=0;
        solution *ptr=first;
        while(ptr!=NULL)
        {
            c++;
            ptr=ptr->next;
        }
        return c;
    }
    void display(int c)
    {
        int i,j,k;
        solution *ptr=first;
        for(k=0;k<c;k++) ptr=ptr->next;
        cout<<"\n "; for(k=0;k<n;k++)
        {cout<<" ---";} cout<<" \n";
        for(i=0;i<n;i++)
        {
            cout<<" |";
            for(j=0;j<n;j++)
            {
                if(ptr->matrix[i][j])
                cout<<" Q |";
                else cout<<"   |";
            }
            cout<<"\n "; for(k=0;k<n;k++)
            {cout<<" ---";} cout<<" \n";
        }
        getch();
    }
};

int main()
{
    N queens(9);
    int value=1;
    int c=queens.count();
    while(value)
    {
        system("cls");
        cout<<"\n 0. End Program ";
        cout<<"\n\n Input 1->";
        cout<<c<<" >>";
        cin>>value;
        if(value>0&&value<=c)
        queens.display(value-1);
    }
}
