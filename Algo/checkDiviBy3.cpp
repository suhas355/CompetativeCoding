/*

Write an Efficient Method to Check if a Number is Multiple of 3

Algorithm: isMutlipleOf3(n)
1) Make n positive if n is negative.
2) If number is 0 then return 1
3) If number is 1 then return 0
4) Initialize: odd_count = 0, even_count = 0
5) Loop while n != 0
    a) If rightmost bit is set then increment odd count.
    b) Right-shift n by 1 bit
    c) If rightmost bit is set then increment even count.
    d) Right-shift n by 1 bit
6) return isMutlipleOf3(odd_count - even_count)

*/
#include <stdlib.h> 
#include <iostream>
#define ll long long

using namespace std;

int isMutlipleOf3(ll n){
	if(n<0){
		n=-n;
	}
	if(n==0)
		return 1;
	if(n==1)
		return 0;
	ll odd_count=0,even_count=0;

	while(n!=0){
		if(n&1)
			odd_count++;
		n=n>>1;
		
		if(n&1){
			even_count++;
		}		
		n=n>>1;
	}
	return isMutlipleOf3(abs(odd_count-even_count));
}

int main(){
	ll n;
	cin >>n;
	if(isMutlipleOf3(n)){
		cout <<"YES" <<endl;
	}
	else{
		cout <<"NO" <<endl;
	}
	return 0;
}