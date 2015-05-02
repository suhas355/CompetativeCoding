/**
Count the number of prime numbers less than a non-negative number, n
*/


#include <iostream>
#define ll long long


int a[10000000]; 
using namespace std;

int countPrimes(int n) {
        if(n<=2){
        	return 0;
        }

        //long long a[n+1];
        for(int i=0;i<n;i++){
        	a[i]=0;
        }
        a[2]=0;
        long long primeCount=1;
        for(int i=2;i*i<=n;i++){
        	if(a[i]!=0)
        		continue;
        	
        	for(int j=2;j*i<=n;j++){
        		a[j*i]=1;
        	}
        	
        }
       // cout <<endl;
        for(int i=3;i<n;i++){
        	if(a[i]==0){
        		primeCount++;
        	}
        }
       
        return primeCount;
        
    }

int main(){
	ll n;
	cin >>n;
	cout <<countPrimes(n) <<endl;
	return 0;
}