#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

void markmultiple(bool *arr,int n,int a){
	int i=2,num;

	while((num=i*a)<=n){
		arr[num]=1;
		//cout <<num <<endl;
		i++;
	}

	//cout <<"hahah" <<endl;

}

vector<int> SieveOfEratosthenes(int n){
	vector<int> res;

	if(n>=2){
		bool isnotprime[n+1];
		memset(isnotprime,0,sizeof(isnotprime));

		for(int i=2;i<=n;i++){
			//cout <<"now:" <<i <<endl;
			if(isnotprime[i]==0){
				res.push_back(i);

				markmultiple(isnotprime,n,i);
				//cout <<"after:" <<i <<endl;
			}			
		}
	}
	return res;
}

int main(){

	int n;

	cout <<"enter max limit of prime: " <<endl;
	cin >>n;

	vector<int> res=SieveOfEratosthenes(n);

	int len=res.size();
	for(int i=0;i<len;i++){
		cout <<res[i] <<" ";
	}
	cout <<endl;

	return 0;
}