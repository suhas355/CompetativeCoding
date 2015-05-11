/*
*
 Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

For example,
Given input array A = [1,1,2],

Your function should return length = 2, and A is now [1,2]. 

*/
#include<iostream>

using namespace std;

   int removeDuplicates(int A[], int n) {
        if(n<=1)
            return n;
        
        int base=0;
        int cur=0,next=0;
        while(next<n){
            if(A[cur]==A[next]){
                next++;
            }else{
                A[base++]=A[cur];
                cur=next;
            }
        }
        if(A[base]!=A[cur]){
            A[base++]=A[cur];
            return base;
        }
        return (base+1);
        
    }

    int main(){
    	int A[]={};
    	cout <<removeDuplicates(A,0) <<endl;
    }