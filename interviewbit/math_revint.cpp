#include <iostream>
#include <string>
#include <limits.h>
using namespace std;

int reverse(int n){
	bool isnegative=false;

	
	if(n>-10 && n<10){
		return n;
	}

	if(n<0){
		isnegative=true;
		n*=-1;
	}

	long long int num=0,base=10,temp;

	while(n>0){
		//cout <<num <<endl;
		temp=n%10;
		num=(base*num)+temp;
		n/=10;
		
	}

	if(num>INT_MAX || num<INT_MIN)
		return 0;


	
	if(isnegative){
		return num*-1;
	}

	return num;

}

int main(){

	int n;

	cin >>n;

	cout <<reverse(n) <<endl;


	return 0;
}
