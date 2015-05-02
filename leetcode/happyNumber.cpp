/*
Write an algorithm to determine if a number is "happy".

A happy number is a number defined by the following process: 
Starting with any positive integer, 
replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), 
or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

Example: 19 is a happy number

    1^2 + 9^2 = 82
    8^2 + 2^2 = 68
    6^2 + 8^2 = 100
    1^2 + 0^2 + 0^2 = 1
*/

#include <iostream>
#include <map>

using namespace std;

bool isHappy(int n){

	int temp;
	map<int,int> happymap;
	map<int,int>::iterator it;
	while(n!=1){
		temp = 0;
		it=happymap.find(n);
		if(it==happymap.end()){
			happymap[n]=1;
		}else{
			return false;
		}
		while(n!=0){
			temp=temp + (n%10) * (n%10);
			n=n/10;
		}
		n=temp;

	}

	return true;
}

int main(){
	int n;
	cin >>n;
	cout <<isHappy(n) <<endl;

	return 0;
}    



