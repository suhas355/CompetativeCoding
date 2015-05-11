#include <iostream>
#include <cstring>

using namespace std;

class Result{
	public:
	 int weight;
	 int value;

	Result(int a,int b){
		weight=a;
		value=b;
	}
};


Result max(Result a,Result b){
	return (a.value>b.value)?a:b;
}

Result knapsack(int W,int wt[],int val[],int n){
	if(W==0 || n==0){
		Result empty = Result(0,0);
		return empty;
	}

	if(wt[n-1]>W){
		return knapsack(W,wt,val,n-1);
	}else{
		
		Result with = knapsack(W-wt[n-1],wt,val,n-1);
		with.value+=val[n-1];
		with.weight+=wt[n-1];

		Result without = knapsack(W,wt,val,n-1);

		return max(with,without);


	}
}



int main(){
	int budget,numParty;
	int fee[150],fun[150];

	while(1){
		cin >>budget >>numParty;
		if(budget==0 && numParty==0)
			break;

		for(int i=0;i<numParty;i++){
			cin >>fee[i] >>fun[i];
		}

		Result maxVl =knapsack(budget,fee,fun,numParty);
		cout <<maxVl.weight <<" " <<maxVl.value <<endl;


	}
		
    
	return 0;
}