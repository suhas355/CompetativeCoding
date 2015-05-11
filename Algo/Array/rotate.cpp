#include <iostream>

using namespace std;
void rotate(int nums[], int n, int k) {
        int a[n+1];
        int j=0;
        k=k%n;
        for(int i=n-k;i<n;i++){
            a[j++]=nums[i];
        }
        
        for(int i=0;i<(n-k);i++){
            a[j++]=nums[i];
        }
        
        for(int i=0;i<n;i++){
            nums[i]=a[i];
            cout <<nums[i] <<" ";
        }
        cout <<endl;

    }


    int main()
    {
        int a[]={1,2,3,4,5,6,7};
        rotate(a,7,3);
        return 0;
    }