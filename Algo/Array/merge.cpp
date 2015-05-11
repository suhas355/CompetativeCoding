#include <iostream>

using namespace std;


void merge(int A[], int m, int B[], int n) {
        
        int i=0,j=0,k=0;
        int C[m+n];
        
        while(i<m && j<n){
            if(A[i]<B[j]){
                C[k++]=A[i++];   
            }else{
                C[k++]=B[j++];
            }
        }
        
        while(i<m){
            C[k++]=A[i++]; 
        }
        //cout <<C[0] <<endl;
        
        while(j<n){
            C[k++]=B[j++];
        }
        
        i=0;
        while(i<(m+n)){
            A[i]=C[i];
            i++;
        }

        for(int i=0;i<(m+n);i++)
            cout <<A[i] <<" ";
            cout <<endl;
    }


    int main(){
    int A[]={1};
    int B[]={};
    merge(A,1,B,0);

    }