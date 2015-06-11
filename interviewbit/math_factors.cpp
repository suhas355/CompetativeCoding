#include <iostream>
#include <vector>

using namespace std;

vector<int> allFactors(int A) {
	vector<int> res;
	if(A==0){
		return res;
	}

	for(int i=1;i<=A/2;i++){
		if(A%i==0){
			res.push_back(i);
		}
	}
	res.push_back(A);

	return res;
}

int main(){

	int inp;

	cin >>inp;

	vector<int> out=allFactors(inp);

	for(int i=0;i<out.size();i++){
		cout <<out[i] <<" ";
	}

	cout <<endl;

	return 0;
}