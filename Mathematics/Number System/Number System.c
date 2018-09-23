#include<stdio.h>
#include<string.h>
#include<math.h>

int digits();
int in(int);
int out(int);

int binary(); char bin[][4]={"0","1","10","11","100","101","110","111","1000","1001","1010","1011","1100","1101","1110","1111"};
int b2o(); int b2d(); void b2h();

int  octal(); int oct[]={-1,0,1,2,3,4,5,6,7,10,11,12,13,14,15,16,17};
void o2b(); void o2d(); void o2h();

int decimal(); int dec[]={-1,0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
int d2b(); void d2o(); void d2h();

int  hexal(); char hex[]={'-','0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
void h2b(); void h2o(); void h2d();

char input[50],output[50];

int main()
{
    int ch;
    do
    {
        system("cls");
        printf("\n MENU :- \n");
        printf("\n 1.  Binary  to Octal  ");
        printf("\n 2.  Binary  to Decimal");
        printf("\n 3.  Binary  to Hex    ");
        printf("\n 4.  Octal   to Binary ");
        printf("\n 5.  Octal   to Decimal");
        printf("\n 6.  Octal   to Hex    ");
        printf("\n 7.  Decimal to Binary ");
        printf("\n 8.  Decimal to Octal  ");
        printf("\n 9.  Decimal to Hex    ");
        printf("\n 10. Hex     to Binary ");
        printf("\n 11. Hex     to Octal  ");
        printf("\n 12. Hex     to Decimal");
        printf("\n 13. Exit ");
        printf("\n\n Enter your choice : ");
        scanf("%d",&ch);
        if(ch==1)
        {
            printf("\n Enter binary number : ");
            scanf("%s",input);
            if(!binary()) printf("\n Error!");
            else printf("\n Octal equivalent : %d",b2o());
            getch();
        }
        else if(ch==2)
        {
            printf("\n Enter binary number : ");
            scanf("%s",input);
            if(!binary()) printf("\n Error!");
            else printf("\n Decimal equivalent : %d",b2d());
            getch();
        }
        else if(ch==7)
        {
            printf("\n Enter decimal number : ");
            scanf("%s",input);
            if(!decimal()) printf("\n Error!");
            else printf("\n Binary equivalent : %d",d2b());
            getch();
        }
        else return;
    }while(ch!=13);
}

int digits()
{
    int count=0;
    while(input[count]!='\0')
        count++;
    return count;
}

int in(int i)
{
    switch(input[i])
    {
        case '0' : return 0;
        case '1' : return 1;
        case '2' : return 2;
        case '3' : return 3;
        case '4' : return 4;
        case '5' : return 5;
        case '6' : return 6;
        case '7' : return 7;
        case '8' : return 8;
        case '9' : return 9;
    }
}

int out(int i)
{
    switch(output[i])
    {
        case '0' : return 0;
        case '1' : return 1;
        case '2' : return 2;
        case '3' : return 3;
        case '4' : return 4;
        case '5' : return 5;
        case '6' : return 6;
        case '7' : return 7;
        case '8' : return 8;
        case '9' : return 9;
    }
}

int binary()
{
    int i=0;
    while(input[i]!='\0')
    {
        switch(input[i])
        {
            case '0' : break;
            case '1' : break;
            case '.' : break;
            default  : return 0;
        }
        i++;
    }
    return 1;
}

int b2o()
{
    return 0;
}

int b2d()
{
    int i,power,ans=0;
    power=digits();
    for(i=0;i<digits();i++)
        if(input[i]=='1')
            ans=ans+pow(2,--power);
    return ans;
}

void b2h()
{

}

void o2b()
{

}

void o2d()
{

}

void o2h()
{

}

int decimal()
{
    int i=0;
    while(input[i]!='\0')
    {
        switch(input[i])
        {
            case '0' : break;
            case '1' : break;
            case '2' : break;
            case '3' : break;
            case '4' : break;
            case '5' : break;
            case '6' : break;
            case '7' : break;
            case '8' : break;
            case '9' : break;
            case '.' : break;
            default  : return 0;
        }
        i++;
    }
    return 1;
}

int d2b()
{
    int i=0,temp,ans=0;
    while(input[i]!='\0')
    {
        temp=in(i);
        ans=ans*10+temp;
        i++;
    }
    i=0;
    temp=ans;
    while(temp/2!=0)
    {
        if(temp%2==0) output[i]='0';
        if(temp%2==1) output[i]='1';
        temp=temp/2;
        i++;
    }
    if(temp==1)
    {
        output[i]='1';
        i++;
    }
    output[i]='\0';
    strrev(output);
    i=0; ans=0;
    while(output[i]!='\0')
    {
        temp=out(i);
        ans=ans*10+temp;
        i++;
    }
    return ans;
}

void d2o()
{

}

void d2h()
{

}

void h2b()
{

}

void h2o()
{

}

void h2d()
{

}
