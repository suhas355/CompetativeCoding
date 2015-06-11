#include <iostream>
#define ll long long

using namespace std;

int main(){

	ll avg,x,t,n,res;

	cin >>t;

	while(t--){
		cin >>x >>avg;

		n=avg-x;

		avg++;
		res= n*avg - n*(n-1)/2;

		cout <<res <<endl;

	}


	return 0;
}