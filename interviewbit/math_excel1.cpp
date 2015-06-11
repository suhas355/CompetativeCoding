#include <iostream>
#include <string>

using namespace std;

int getvalue(char x){
	int val=x-'A';
	val++;
	//cout <<x <<" " <<val <<endl;
	return val;
}

int titleToNumber(string A){
	int val=0,base=1;

	for(int i=A.size()-1;i>=0;i--){
		val+=getvalue(A[i])*base;
		//cout <<val <<endl;
		base*=26;
	}

	return val;
}

int main(){
	string inp;

	cin >>inp;

	cout <<titleToNumber(inp) <<endl;

	return 0;
}
