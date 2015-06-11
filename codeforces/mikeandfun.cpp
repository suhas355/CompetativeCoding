#include <iostream>


using namespace std;

int mat[505][505];

int getval(int r,int c,int m,int n){
	if(mat[r][c]==1)
		mat[r][c]=0;
	else
		mat[r][c]=1;

	int max=-1,sum;

	bool prev,cur;
	for(int i=1;i<=m;i++){
		//cout <<"row nu: " <<i <<endl;
		sum=0;
		prev=cur=false;
		int j=1;
		for(;j<=n;j++){
			//cout <<"col" <<j <<" ";
			if(mat[i][j]==1)
				cur=true;
			else
				cur=false;

			if(!prev && cur){
				sum=1;
			}

			if(prev && cur){
				sum++;
			}

			if(prev && !cur){
				if(max==-1 || sum>max){
					max=sum;
				}
			}

			if(!cur){
				prev=false;
			}else{
				prev=true;
			}
			//cout <<sum <<"  ,";
			
		}

		if(prev){
			if(max==-1 || sum>max){
					max=sum;
			}
		}
		//cout <<endl;
		//cout <<"cur max:" <<max <<endl;

	}

	return max;

}


int main(){

	int m,n,q,r,c;
	cin >>m >>n >>q;

	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			cin >>mat[i][j];
		}
	}

	for(int i=0;i<q;i++){
		cin >>r >>c;

		cout <<getval(r,c,m,n) <<endl;
	}

	return 0;
}