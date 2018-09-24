#include<iostream>
#include<stdlib.h>
#include<conio.h>

using namespace std;

struct pos
{
    public:
    int i,j; pos(){}
    pos(int p,int q){i=p;j=q;}
    int check(int p,int q)
    {
        if(i==p&&j==q)
        return 1;
        return 0;
    }
    pos operator-(pos &x)
    {
        pos temp;
        temp.i=i-x.i;
        temp.j=j-x.j;
        return temp;
    }
};

int row=8,col=7;
int matrix[8][7]={
    {0,0,0,1,0,0,0},
    {0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0},
    {0,1,0,0,1,0,0},
    {0,0,0,0,0,0,1},
    {0,0,0,1,0,0,0},
    {0,0,0,0,0,0,0},
    {1,0,0,0,0,0,0}
};pos food(7,3);

class put
{
    public:
    put(pos rat)
    {
        if(!check(p,q))
        cout<<"\n Error! \n";
        else if(food.check(p,q))
        {
            matrix[p][q]=2; display();
            matrix[p][q]=3; display();
            cout<<"\n Goal Reached! \n";
        }
        else
        {
            matrix[food.i][food.j]=2;
            matrix[p][q]=3;display();
            if(solve(p,q)) cout<<"\n Goal Reached! \n";
            else cout<<"\n Unreachable Goal! \n";
        }
    }
    int solve(int p,int q)
    {
        pos dis=food-rat;
        return 0;
    }
    int check(pos temp)
    {
        if(temp.i<0||temp.j<0) return 0;
        if(temp.i>row||temp.j>col) return 0;
        if(matrix[temp.i][temp.j]==1) return 0;
        return 1;
    }
    void display()
    {
        int i,j,k;
        cout<<"\n "; for(k=0;k<col;k++)
        {cout<<" ---";} cout<<" \n";
        for(i=0;i<row;i++)
        {
            cout<<" |";
            for(j=0;j<col;j++)
            {
                switch(matrix[i][j])
                {
                    case 0 : cout<<"   |"; break;
                    case 1 : cout<<" X |"; break;
                    case 2 : cout<<" F |"; break;
                    case 3 : cout<<" R |"; break;
                }
            }
            cout<<"\n "; for(k=0;k<col;k++)
            {cout<<" ---";} cout<<" \n";
        }
    }
};

int main()
{
    pos rat(1,1);
    put maze(rat);
}
