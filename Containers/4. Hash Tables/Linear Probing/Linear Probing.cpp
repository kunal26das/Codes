#include<iostream>
#include<stdlib.h>
#include<conio.h>

using namespace std;

class linear{
    int s,*table;
    int hash(int v){
        return v%s;
    }
    int insert(int v,int i,int c){
        if(c>=s) return 0;
        if(!table[i]){
            table[i]=v;
            return 1;
        }
        insert(v,hash(i+c),c+1);
    }
    int remove(int v,int i,int c){
        if(c>=s) return 0;
        if(table[i]==v){
            table[i]=0;
            return 1;
        }
        else remove(v,hash(i+c),c+1);
    }
    public:
    linear(int _s){
        s=_s;
        table=new int[s];
        for(int i=0;i<s;i++)
        table[i]=0;
    }
    int insert(int v){
        return insert(v,hash(v),1);
    }
    int remove(int v){
        return remove(v,hash(v),1);
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
    int ch,v;
    linear probing(10);
    do{
        system("cls");
        cout<<"\n 1. Insert ";
        cout<<"\n 2. Delete ";
        cout<<"\n 3. Display ";
        cout<<"\n 4. End Program ";
        cout<<"\n\n Enter>>";
        cin>>ch; switch(ch){
            case 1 :
            cout<<"\n Enter a value : ";
            cin>>v; if(!probing.insert(v))
            {
                cout<<"\n collisions maxed out. ";
                system("pause");
            }
            break;

            case 2 :
            cout<<"\n Enter a value : ";
            cin>>v; cout<<"\n "<<v<<" ";
            if(probing.remove(v))
            cout<<"deleted from table. ";
            else cout<<"was not found. ";
            system("pause");
            break;

            case 3 :
            cout<<"\n Hash table is : \n";
            probing.display();
            system("pause");
            break;
        }
    }while(ch!=4);
}
