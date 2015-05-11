/*
Given an array and a value, remove all instances of that value in place and return the new length.

The order of elements can be changed. It doesn't matter what you leave beyond the new length. 

*/


#include <iostream>

using namespace std;

    int removeElement(int A[], int n, int elem) {
        
        int st=0;
        int lt=n-1,temp;
        while(A[lt]==elem)
            lt--;
            
        while(st<lt){
            if(A[st]==elem){
                temp=A[st];
                A[st]=A[lt];
                A[lt]=elem;
                lt--;
            }
            if(A[lt]==elem)
              lt--;
            st++;  
        }  

       if(lt<0)
            return 0;   
        
       if(A[lt]!=elem)
           return (lt+1);
    else
        return (st+1);
        
    }

    int main(){
        int a[]={1};
        cout <<removeElement(a,1,0) <<endl;
    }

