#include <iostream>

using namespace std;

int mat[105][105];

int main(){

	int n,count=0;

	cin >>n;

	bool car[n+1];

	for(int i=0;i<n;i++){
		car[i]=false;
	}

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			cin >>mat[i][j];
	}

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(mat[i][j]==3){
				car[i]=true;
				car[j]=true;
			}else if(mat[i][j]==1){
				car[i]=true;
			}else if(mat[i][j]==2){
				car[j]=true;
			}
		}
	}

	for(int i=0;i<n;i++){
		if(car[i]==true)
			count++;
	}

	count=n-count;
	cout <<count <<endl;
	if(count!=0){
		for(int i=0;i<n;i++){
			if(car[i]==false){
				cout <<(i+1) <<" "; 
			}
		}
		cout <<endl;
	}


	return 0;
}