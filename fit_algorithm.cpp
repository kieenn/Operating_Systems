#include<iostream>
#include<bits/stdc++.h>
#include<iomanip>
using namespace std;


void Best_fit(int block_size[], int process_size[], int n, int m);
void First_fit(int block_size[], int process_size[], int n, int m);
void Worst_fit(int block_size[], int process_size[], int n, int m);
void Next_fit(int block_size[], int process_size[], int n, int m);
void Last_fit(int block_size[], int process_size[], int n, int m);

int main(){
    int block_size[] = {580, 500, 200, 300};
    int process_size[] = {212, 417, 112, 426};

    int m = sizeof(block_size)/sizeof(block_size[0]);
    int n = sizeof(process_size) / sizeof(process_size[0]);

    // First_fit(block_size,process_size,n,m);
    cout<<endl<<endl<<endl;
    Worst_fit(block_size,process_size,n,m);
    
    return 0;

   
}

void First_fit(int block_size[], int process_size[],  int n, int m){
        int allocation[n];

        memset(allocation,-1,sizeof(allocation));


        for(int i = 0; i<n; i++){
            for(int j =0; j<m ; j++){
                if(block_size[j] >= process_size[i]){
                    allocation[i] = j;
                    block_size[j] -= process_size[i];
                    break;
                }
            }
        }

        cout<<"process no."<<setw(20)<<"process_size"<<setw(20)<<"block_size no."<<endl;

        for(int i =0 ;i<n ; i++){
            cout<<" "<<i+1<<setw(20)<<process_size[i]<<setw(20);
            if(allocation[i] != -1){
                cout<<allocation[i]+1;
            }
            else{
                cout<<"\t   Not Allocated";
            }
            cout<<endl;
        }

}

void Best_fit(int block_size[], int process_size[], int n, int m){

     int allocation[n];

        memset(allocation,-1,sizeof(allocation));


        for(int i = 0; i<n; i++){
            int best_block = -1;
            for(int j =0; j<m ; j++){
                if(block_size[j] >= process_size[i]){

                    if(best_block == -1){
                        best_block = j;

                    }
                    else if(block_size[best_block]>block_size[j]){
                            best_block = j;
                        }
                    }
                }
            if(best_block != -1){
                allocation[i] = best_block;
                block_size[best_block] -= process_size[i];
            }
        }
        cout<<"process no."<<setw(20)<<"process_size"<<setw(20)<<"block_size no."<<endl;

        for(int i =0 ;i<n ; i++){
            cout<<" "<<i+1<<setw(20)<<process_size[i]<<setw(20);
            if(allocation[i] != -1){
                cout<<allocation[i]+1;
            }
            else{
                cout<<"\t   Not Allocated";
            }
            cout<<endl;
        }
}

void Worst_fit(int block_size[], int process_size[],  int n, int m){
    int allocation[n];

        memset(allocation,-1,sizeof(allocation));


        for(int i = 0; i<n; i++){
            int big_block = -1;
            for(int j =0; j<m ; j++){
                if(block_size[j] >= process_size[i]){

                    if(big_block == -1){
                        big_block = j;

                    }
                    else if(block_size[big_block]<block_size[j]){
                            big_block = j;
                        }
                    }
                }
            if(big_block != -1){
                allocation[i] = big_block;
                block_size[big_block] -= process_size[i];
            }
        }
        cout<<"process no."<<setw(20)<<"process_size"<<setw(20)<<"block_size no."<<endl;

        for(int i =0 ;i<n ; i++){
            cout<<" "<<i+1<<setw(20)<<process_size[i]<<setw(20);
            if(allocation[i] != -1){
                cout<<allocation[i]+1;
            }
            else{
                cout<<"\t   Not Allocated";
            }
            cout<<endl;
        }

}

void Next_fit(int block_size[], int process_size[],  int n, int m){
    int allocation[n];

        memset(allocation,-1,sizeof(allocation));

        int index = 0;
        for(int i = 0; i<n; i++){
            for(int j = index; j<m ; j++){
                if(block_size[j] >= process_size[i]){
                    allocation[i] = j;
                    index = j+1;
                    break;
                }
            }
        }

        cout<<"process no."<<setw(20)<<"process_size"<<setw(20)<<"block_size no."<<endl;

        for(int i =0 ;i<n ; i++){
            cout<<" "<<i+1<<setw(20)<<process_size[i]<<setw(20);
            if(allocation[i] != -1){
                cout<<allocation[i]+1;
            }
            else{
                cout<<"\t   Not Allocated";
            }
            cout<<endl;
        } 

}
//like Best fit...
void Last_fit(int block_size[], int process_size[],  int n, int m){
    int allocation[n];

        memset(allocation,-1,sizeof(allocation));


        for(int i = 0; i<n; i++){
            int best_block = -1;
            for(int j = m-1; j>=0 ; j--){
                if(block_size[j] >= process_size[i]){

                    if(best_block == -1){
                        best_block = j;

                    }
                    else if(block_size[best_block]>block_size[j]){
                            best_block = j;
                        }
                    }
                }
            if(best_block != -1){
                allocation[i] = best_block;
                block_size[best_block] -= process_size[i];
            }
        }
        cout<<"process no."<<setw(20)<<"process_size"<<setw(20)<<"block_size no."<<endl;

        for(int i =0 ;i<n ; i++){
            cout<<" "<<i+1<<setw(20)<<process_size[i]<<setw(20);
            if(allocation[i] != -1){
                cout<<allocation[i]+1;
            }
            else{
                cout<<"\t   Not Allocated";
            }
            cout<<endl;
        }
}

