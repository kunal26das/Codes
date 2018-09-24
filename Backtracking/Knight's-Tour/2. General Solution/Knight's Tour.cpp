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

class Knights
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
    int solve(solution board,int row,int col,int k=1)
    {
        board.matrix[row][col]=k;

        if(check(board,row-2,col-1))
        if(!solve(board,row-2,col-1,k+1))
        board.matrix[row-2][col-1]=0;

        if(check(board,row-2,col+1))
        if(!solve(board,row-2,col+1,k+1))
        board.matrix[row-2][col+1]=0;

        if(check(board,row-1,col-2))
        if(!solve(board,row-1,col-2,k+1))
        board.matrix[row-1][col-2]=0;

        if(check(board,row-1,col+2))
        if(!solve(board,row-1,col+2,k+1))
        board.matrix[row-1][col+2]=0;

        if(check(board,row+1,col-2))
        if(!solve(board,row+1,col-2,k+1))
        board.matrix[row+1][col-2]=0;

        if(check(board,row+1,col+2))
        if(!solve(board,row+1,col+2,k+1))
        board.matrix[row+1][col+2]=0;

        if(check(board,row+2,col-1))
        if(!solve(board,row+2,col-1,k+1))
        board.matrix[row+2][col-1]=0;

        if(check(board,row+2,col+1))
        if(!solve(board,row+2,col+1,k+1))
        board.matrix[row+2][col+1]=0;

        if(k==(n*n))
        {
            append(board);
            return 1;
        }
        else return 0;
    }
    int check(solution board,int row,int col)
    {
        if(row>=0&&row<n&&col>=0&&col<n)
        if(!board.matrix[row][col])
        return 1;
        return 0;
    }
    public:
    Knights(int knights)
    {
        n=knights;
        last=NULL;
        first=NULL;
        solution board(n);
        for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        solve(board,i,j);
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
        {cout<<" ----";} cout<<" \n";
        for(i=0;i<n;i++)
        {
            cout<<" |";
            for(j=0;j<n;j++)
            {
                if(ptr->matrix[i][j]>=0)
                if(ptr->matrix[i][j]<=9)
                cout<<"  "; else cout<<" ";
                cout<<ptr->matrix[i][j]<<" |";
            }
            cout<<"\n "; for(k=0;k<n;k++)
            {cout<<" ----";} cout<<endl;
        }
        getch();
    }
};

int main()
{
    Knights tour(5);
    int value=1;
    int c=tour.count();
    while(value)
    {
        system("cls");
        cout<<"\n 0. End Program ";
        cout<<"\n\n Input 1->";
        cout<<c<<" >>";
        cin>>value;
        if(value>0&&value<=c)
        tour.display(value-1);
    }
}
