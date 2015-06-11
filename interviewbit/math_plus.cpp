#include <iostream>
#include <vector>

using namespace std;

vector<int> plusOne(vector<int> &A) {

	vector<int> res1,res2;

	int len=A.size(),carry=0,num;

	if(len==0){
		res1.push_back(1);
		return res1;
	}

	int j=0;

	for(;j<A.size();j++){
		if(A[j]!=0)
			break;
	}

	if(A[len-1]==9){
		res1.push_back(0);
		carry=1;

	}else{
		res1.push_back(A[len-1]+1);
		carry=0;
	}

	for(int i=len-2;i>=j;i--){
		//cout <<"A[i]+carry: " <<A[i] <<" " <<carry <<endl;
		if(i==0){
			if(carry==0 && A[0]==0)
				continue;
		}
		if((A[i]+carry)>9){
			carry=1;
			res1.push_back(0);
		}else{
			
			res1.push_back(A[i]+carry);
			carry=0;
		}
	}


	if(carry==1){
		res1.push_back(1);
	}

	for(int i=res1.size()-1;i>=0;i--){
		res2.push_back(res1[i]);
	}

	return res2;


}


int main(){
	vector<int> inp;

	int a[20]={0, 0, 3, 7, 6, 4, 0, 5, 5, 5};
	int n=10;

	//cin >>n;

	for(int i=0;i<n;i++){
		//cin >>a[i];
		inp.push_back(a[i]);
	}

	vector<int> out = plusOne(inp);

	for(int i=0;i<out.size();i++){
		cout <<out[i] <<" ";
	}

	cout <<endl;



}