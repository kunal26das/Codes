#include<iostream>
#include<stdlib.h>
#include<conio.h>

using namespace std;

class quadratic{
    int s,*table;
    int hash(int v){
        return v%s;
    }
    void insert(int v,int i,int c){
        if(c>=s*s) return;
        if(!table[i]){
            table[i]=v;
            return;
        }
        insert(v,hash(i+c*c),c+1);
    }
    public:
    quadratic(int _s){
        s=_s;
        table=new int[s];
        for(int i=0;i<s;i++)
        table[i]=0;
    }
    void insert(int v){
        insert(v,hash(v),1);
    }
    void display(){
        for(int i=0;i<s;i++){
            cout<<"\n "<<i<<"_ ";
            if(table[i])
            cout<<table[i];
            cout<<endl;
        }
    }
};

int main(){
    int ch,value;
    quadratic probe(10);
    do{
        system("cls");
        cout<<"\n 1. Insert ";
        cout<<"\n 2. Display ";
        cout<<"\n 3. End Program ";
        cout<<"\n\n Enter>>";
        cin>>ch; switch(ch){
            case 1 :
            cout<<"\n Enter a value : ";
            cin>>value; probe.insert(value);
            break;

            case 2 :
            cout<<"\n Enter a value : ";
            cin>>value; if(probe.found(value));
            cout<<"\n Value found ";
            else cout<<"\n Value not found!";
            getch(); break;

            case 3 :
            cout<<"\n Enter a value : ";
            cin>>value; if(probe.remove(value));
            cout<<"\n Value deleted ";
            else cout<<"\n Value not found!";
            getch(); break;

            case 4 :
            cout<<"\n Hash table is : \n";
            probe.display(); getch();
            break;
        }
    }while(ch!=5);
}
