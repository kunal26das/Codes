#include<windows.h>
#include<iostream>
#include<stdlib.h>

using namespace std;

void SetColor(int ForgC)
{
    WORD wColor;
    HANDLE hStdOut=GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if(GetConsoleScreenBufferInfo(hStdOut,&csbi))
    {
        wColor=(csbi.wAttributes & 0xF0)+(ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut,wColor);
    }
}

class AVL
{
    class vertex
    {
        public:
        int value;
        bool color;
        vertex *left;
        vertex *right;
        vertex *parent;
        vertex(int _value)
        {
            left=NULL;
            right=NULL;
            color=true;
            parent=NULL;
            value=_value;
        }
    }*root;

    int height(vertex *ptr,int h)
    {
        if(!ptr) return h-1;
        int left=height(ptr->left,h+1);
        int right=height(ptr->right,h+1);
        return left>right?left:right;
    }

    vertex* insert(vertex *ptr,vertex *x)
    {
        if(!ptr) return x;
        else if(ptr->value>x->value)
        {
            ptr->left=insert(ptr->left,x);
            ptr->left->parent=ptr;
        }
        else if(ptr->value<x->value)
        {
            ptr->right=insert(ptr->right,x);
            ptr->right->parent=ptr;
        }
        return ptr;
    }

    vertex* balance(vertex *ptr)
    {
        vertex *save;
        vertex *uncle=NULL;
        vertex *grand=NULL;
        vertex *father=NULL;
        do
        {
            save=ptr;
            if(!ptr->color||(ptr->parent&&!ptr->parent->color))
            {
                ptr=ptr->parent;
                continue;
            }
            father=ptr->parent;
            if(!father) break;
            else
            {   grand=father->parent;
                if(!grand) ptr=ptr->parent;
                else
                {
                    if(grand->left==father)
                        uncle=grand->right;
                    else uncle=grand->left;
                    if(uncle&&uncle->color)
                    {
                        father->color=false;
                        uncle->color=false;
                        grand->color=true;
                        ptr=grand;
                        save=ptr;
                    }
                    else if(grand&&grand->left==father)
                    {
                        if(grand->left->right==ptr)
                        grand->left=leftrotate(grand->left);
                        if(grand->parent&&grand->parent->left==grand)
                        grand->parent->left=rightrotate(grand);
                        else if(grand->parent&&grand->parent->right==grand)
                        grand->parent->right=rightrotate(grand);
                        else return rightrotate(grand);
                        ptr=father;
                    }
                    else if(grand&&grand->right==father)
                    {
                        if(grand->right->left==ptr)
                        grand->right=rightrotate(grand->right);
                        if(grand->parent&&grand->parent->left==grand)
                        grand->parent->left=leftrotate(grand);
                        else if(grand->parent&&grand->parent->right==grand)
                        grand->parent->right=leftrotate(grand);
                        else return leftrotate(grand);
                        ptr=father;
                    }
                }
            }
        }while(ptr);
        root->color=false;
        return save;
    }

    vertex* leftrotate(vertex *ptr)
    {
        vertex *r=ptr->right;
        vertex *rl=r->left;
        r->parent=ptr->parent;
        r->left=ptr;
        ptr->right=rl;
        ptr->parent=r;
        swap(ptr->color,r->color);
        return r;
    }

    vertex* rightrotate(vertex *ptr)
    {
        vertex *l=ptr->left;
        vertex *lr=l->right;
        l->parent=ptr->parent;
        l->right=ptr;
        ptr->left=lr;
        ptr->parent=l;
        swap(ptr->color,l->color);
        return l;
    }

    void levelorder(vertex *ptr,int level)
    {
        if(!ptr) return;
        if(!level)
        {
            if(ptr->color) SetColor(12);
            cout<<ptr->value<<", ";
            SetColor(7);
        }
        else
        {
            levelorder(ptr->left,level-1);
            levelorder(ptr->right,level-1);
        }
    }

    void kill(vertex *ptr,int level)
    {
        if(!ptr) return;
        if(!level) delete ptr;
        else
        {
            kill(ptr->left,level-1);
            ptr->left=NULL;
            kill(ptr->right,level-1);
            ptr->right=NULL;
        }
    }

    public:

    AVL(){root=NULL;}

    int exists()
    {
        if(root)
        return 1;
        return 0;
    }

    void insert(int value)
    {
        vertex *x;
        x=new vertex(value);
        root=insert(root,x);
        root=balance(x);
    }

    int height(){return height(root,0);}

    void levelorder()
    {
        int h=height(root,0);
        for(int i=0;i<=h;i++)
        {
            cout<<"\n Level "<<i<<" : ";
            levelorder(root,i); cout<<" ";
        }
        cout<<endl;
    }

    void kill()
    {
        if(!root) return;
        int h=height(root,0);
        for(int i=h;i>=0;i--)
        kill(root,i);
        root=NULL;
    }
};

int main()
{
    AVL tree;
    int ch,value;
    do
    {
        system("cls");
        if(tree.exists())
        tree.levelorder();
        cout<<"\n 1. Insert ";
        cout<<"\n 2. End Program ";
        cout<<"\n\n Enter>>";
        cin>>ch; switch(ch)
        {
            case 1 :
            cout<<"\n Enter a value : ";
            cin>>value; tree.insert(value);
            break;

            case 0 : tree.kill(); break;
        }
    }while(ch!=2);
}
