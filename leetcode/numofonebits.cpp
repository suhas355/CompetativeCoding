/*
*	Write a function that takes an unsigned integer and returns the number of ’1' bits it has (also known as the Hamming weight).

For example, the 32-bit integer ’11' has binary representation 00000000000000000000000000001011, so the function should return 3.
*/

#include <iostream>
#include <stdint.h>

using namespace std;


int hammingWeight(uint32_t n) {
	int count=0;
	for(int i=0;i<32;i++){
		if( n  &  (1<<i)){
			count++;
		}
	}
	return count;
        
}

int main(){

	uint32_t  num;
	cin >>num;

	cout <<hammingWeight(num) <<endl;

	return 0;
}