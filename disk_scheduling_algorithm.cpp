#include<iostream>
#include <limits.h>  
#include<algorithm>
#include<bits/stdc++.h>

using namespace std;

void FCFS(int a[], int n, int x);
void SSTF(int a[], int n, int x);
void Scan(int a[], int n, int x, string input, int start, int end);
void C_Scan(int a[], int n, int x, string input, int start, int end);
void Look(int a[], int n, int x, string input);

int main(){
    int a[8] = {98, 183, 37, 122, 14, 124, 65, 67};
    int n = sizeof(a)/sizeof(a[0]);
    int start = 0;
    int end = 199;    
    int x = 53;
    string input = "right";
    
    // SSTF(a, n, x);
    // Scan(a, n, x, input, start, end);
}


//FCFS
void FCFS(int a[], int n, int x){
    int temp = abs(x - a[0]);
    for(int i = 0; i< n-1 ; i++){
        temp += abs(a[i] - a[i+1]);
    }
    cout<<temp<<endl;
}
//---------------------------------
bool check(int b[], int n, int j){
    int check = 0;
    for(int i = 0; i <n ; i++){
        if(b[i] == j){
            check = 1;
        }
    }
    if(check == 1){
        return true;
    }
    else{
        return false;
    }
}
//---------------------------------

//SSTF
void SSTF(int a[], int n, int x){
    int b[n];
    int index = 0;
    int min = abs(x-a[0]);
    for(int i = 0; i < n; i++){
        if(min >= abs(x - a[i])){
            min = abs(x - a[i]);
            index = i;
        }
    }
    for(int i =0; i < n ;i++){
        b[i] = index;
        min = INT_MAX;
        for(int j =0; j< n; j++){
            if(check(b,n,j)){
                continue;
            }
            else{
                if(min >= abs(a[b[i]] - a[j])){
                    min =  abs(a[b[i]] - a[j]);
                    index = j;
                }
            }
        }
    }
    int temp = abs(x - a[b[0]]);
    for(int i = 0; i< n-1 ; i++){
        temp += abs(a[b[i]] - a[b[i+1]]);
    }
    cout<<temp<<endl;

}


//Scan
void Scan(int a[], int n , int x, string input, int start, int end){
    int temp = 0;
    int index = 0;
    n = n + 1;
    a[n-1] = x;
    sort(a, a + n);
    for(int i = 0; i < n; i++){
        if(a[i] == x){
            index = i;
        }
    }
    if(input == "left"){
        temp = abs(a[0] - start);
        for(int i = index ; i > 0; i--){
            temp += abs(a[i]-a[i-1]);
        }
        temp += abs(start - a[index + 1]);
        for(int i  = index + 1; i < n -1 ; i++){
            temp += abs(a[i] - a[i+1]);
        }
    }
    else if(input == "right"){
        temp += abs(a[n-1]-end);
        for(int i  = index; i < n -1 ; i++){
            temp += abs(a[i] - a[i+1]);
        }
        temp += abs(end - a[index - 1]);
         for(int i = index -1 ; i > 0; i--){
            temp += abs(a[i]-a[i-1]);
        }
    }
    cout<<temp;

}



void C_Scan(int a[], int n, int x, string input, int start, int end){
    int temp = 0;
    int index = 0;
    n = n + 1;
    a[n-1] = x;
    sort(a, a + n);
    for(int i = 0; i < n; i++){
        if(a[i] == x){
            index = i;
        }
    }
    if(input == "left"){
       temp += abs(a[0] - start);
       for(int i =0; i < index ; i++){
        temp += abs(a[i] - a[i+1]);
       } 
       temp += abs(end - start);
       temp += abs(a[n-1] - end);
       for(int i = n-1; i > index+1 ; i--){
        temp += abs(a[i]-a[i-1]);
       }
    }
    else if(input == "right"){
       temp += abs(a[n-1] - end);
       for(int i = index; i < n-1 ; i++){
        temp += abs(a[i]-a[i+1]);
       }
       temp += abs(end - start);
       temp += abs(a[0] - start);
       for(int i = 0; i < index - 1; i++){
        temp += abs(a[i] - a[i+1]);
       }
    }
    cout<<temp;
}


void Look(int a[], int n, int x, string input){
    int temp = 0;
    int index = 0;
    n = n + 1;
    a[n-1] = x;
    sort(a, a + n);
    for(int i = 0; i < n; i++){
        if(a[i] == x){
            index = i;
        }
    }
    if(input == "left"){
       for(int i =0; i < index; i++){
        temp += abs(a[i] - a[i+1]);
       }
       temp += abs(a[0] - a[n-1]);
       for(int i = n-1; i > index +1; i--){
        temp += abs(a[i] - a[i-1]);
       }
    }
    else if(input == "right"){
       for(int i = index; i<n-1; i++){
        temp += abs(a[i] - a[i +1]);
       }
       temp += abs(a[n-1] - a[0]);
       for(int i = 0; i < index -1 ;i++){
        temp += abs(a[i] - a[i+1]);
       }
    }
    cout<<temp;
}
