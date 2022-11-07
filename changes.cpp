#include<iostream>
#include<fstream>
using namespace std;

#define Max 100
struct Table{
    int page;
    int frame;
};

void read(Table table[], int &n);

int logictophysical(Table table[], int x, int n);
int physicaltologic(Table table[], int x, int n);

int main(){
    Table table[Max];
    int n = 0;
    read(table, n);
    int x;
    cout<<"enter x: ";
    cin>>x;
    cout<<logictophysical(table, x, n)<<endl;
    cout<<"enter x: ";
    cin>>x;
    cout<<physicaltologic(table, x, n);

}
int logictophysical(Table table[], int x, int n){
    int k = (int)x/1024;
    int index = 0;
    int check =0;
    for(int i =0; i<n; i++){
        if(k == table[i].page){
            index = i;
            check =1;
            break;
        }
    }

    if(check ==1){
        int p = table[index].frame*1024+(x%1024);
        return p;
    }else{
        return 100000000;
    }


}
int physicaltologic(Table table[], int x, int n){
    int check = 0;
    int value = 0;
    for(int i =0; i<n ; i++){
        int k = x - table[i].frame*1024 + 1024*table[i].page;
        if(x == logictophysical(table, k, n)){
            check =1;
            value = k;
        } 
    }
    if(check == 1){
        return value;
    }
    else{
        return 100000000;
    }

}


void read(Table table[], int &n){
    ifstream input("input.text");
    int i=0;
    while(!input.eof()){
        input>>table[i].page;
        input>>table[i].frame;
        i++;
    }
    n = i + 1;
}