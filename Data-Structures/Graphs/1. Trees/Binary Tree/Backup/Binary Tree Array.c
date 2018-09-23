#include<stdio.h>

int btree[100],count=0;

void add();
int  height(int);
void search();
void insert();
void deleter();
void preorder(int);
void inorder(int);
void postorder(int);

void display();
int  pow(int);
int  sop(int);

void main()
{
    int i,ch;
    for(i=0;i<100;i++) btree[i]=0;
    do
    {
        system("cls");
        printf("\n MENU :- \n");
        printf("\n 1. Add ");
        printf("\n 2. Height ");
        printf("\n 3. Search ");
        printf("\n 4. Insert ");
        printf("\n 5. Delete ");
        printf("\n 6. Preorder ");
        printf("\n 7. Inorder ");
        printf("\n 8. Postorder ");
        printf("\n 9. Display ");
        printf("\n 0. Exit ");
        printf("\n\n Enter your choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1 : add();  break;
            case 2 :
                printf("\n The height tree is : %d",height(0));
                getch();
                break;
            case 3 : search(); break;
            case 4 : insert(); break;
            case 5 : deleter(); break;
            case 6 :
                printf("\n The binary tree is :");
                preorder(0);
                getch();
                break;
            case 7 :
                printf("\n The binary tree is :");
                inorder(0);
                getch();
                break;
            case 8 :
                printf("\n The binary tree is :");
                postorder(0);
                getch();
                break;
            case 9 : display(); break;
        }
    }while(ch!=0);
}

void add()
{
    printf("\n Enter an element : ");
    scanf("%d",&btree[count++]);
}

int height(int x)
{
    if(btree[x]!=0)
    {
        int lheight=height(2*x+1);
        int rheight=height(2*x+2);
        if(lheight>=rheight)
            return lheight+1;
        else if(lheight<=rheight)
            return rheight+1;
    }
    else return -1;
}

void search()
{
    int i,num;
    printf("\n Enter the element to be searched : ");
    scanf("%d",&num);
    for(i=0;i<count;i++)
        if(btree[i]==num)
        {
            printf("\n Element found!");
            break;
        }
    if(i==count)
        printf("\n Element not found!");
    getch();
}

void insert()
{
    int i,pos,num;
    printf("\n Enter the value after which new value is to be inserted : ");
    scanf("%d",&num);
    for(i=0;i<count;i++)
        if(btree[i]==num)
        {
            pos=i;
            break;
        }
    if(i==count)
    {
        printf("\n Value not found!");
        getch();
    }
    else
    {
        for(i=count;i>pos;i--)
            btree[i]=btree[i-1];
        printf("\n Enter the value to insert : ");
        scanf("%d",&btree[pos+1]);
        count++;
    }
}

void deleter()
{
    int i,pos,num;
    printf("\n Enter the element to be deleted : ");
    scanf("%d",&num);
    for(i=0;i<count;i++)
        if(btree[i]==num)
        {
            pos=i;
            break;
        }
    if(i==count) printf("\n Element not found!");
    else
    {
        for(i=pos;i<count;i++)
            btree[i]=btree[i+1];
        btree[i]=0;
        count--;
        printf("\n Element deleted");
    }
    getch();
}

void preorder(int pos)
{
    int i,j;
    if(btree[pos]!=0) printf(" %d",btree[pos]);
    i=2*pos+1; if(btree[i]!=0) preorder(i);
    j=2*pos+2; if(btree[j]!=0) preorder(j);
}

void inorder(int pos)
{
    int i,j;
    i=2*pos+1; if(btree[i]!=0) inorder(i);
    if(btree[pos]!=0) printf(" %d",btree[pos]);
    j=2*pos+2; if(btree[j]!=0) inorder(j);
}

void postorder(int pos)
{
    int i,j;
    i=2*pos+1; if(btree[i]!=0) postorder(i);
    j=2*pos+2; if(btree[j]!=0) postorder(j);
    if(btree[pos]!=0) printf(" %d",btree[pos]);
}

void display()
{
    int i,j,k,h,n,pos=0;
    h=height(0)+1;
    n=h;
    printf("\n The binary tree is : \n\n");
    for(i=1;i<=n;i++)
    {
        printf(" ");
        for(j=0;j<sop(h);j++) printf(" ");
        for(j=0;j<pow(i);j++)
        {
            if(btree[pos]!=0) printf("%d",btree[pos]);
            else printf(" ");
            if(j<pow(i)-1)
                for(k=0;k<sop(h+1);k++)
                    printf(" ");
            pos++;
        }
        for(j=0;j<sop(h);j++) printf(" ");
        printf("\n\n");
        h--;
    }
    getch();
}
int pow(int x)
{
    int i,p=1;
    for(i=0;i<x-1;i++)
        p=p*2;
    return p;
}
int sop(int x)
{
    int i,sum=0;
    for(i=1;i<x;i++)
        sum=sum+pow(i);
    return sum;
}
