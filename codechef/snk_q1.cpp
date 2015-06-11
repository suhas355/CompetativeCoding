/*
1 ≤ T ≤ 1000
2 ≤ n ≤ 20
1 ≤ sx, sy , ex, ey, bx, by ≤ n

2
2 1 1 2 2 1 2
3 1 1 1 3 1 2

*/

#include <iostream>

using namespace std;

int res=-1;
int n,sx,sy,ex,ey,bx,by;

int mat[25][25];

bool done,visited[25][25];

void cal_min(){

	int count=0;

	int i=sx
	while(1){



	}
}

void calculate_min(int i,int j,int count){

	if(visited[i][j])
		return;

	//cout <<i <<" " <<j <<endl;
	if(i==bx && j==by){
		visited[i][j]=true;
		return;
	}

	if(i==ex && j==ey){
		mat[i][j]=count;
		visited[i][j]=true;
		done=true;
		return;
	}

	mat[i][j]=count;
	visited[i][j]=true;
	count++;

	if((i+1)<=n ){
		//cout <<"a" <<endl;
		calculate_min(i+1,j,count);
	}

	if((i-1)>=1 && !done ){
		//cout <<"b" <<endl;
		calculate_min(i-1,j,count);
	}

	if((j+1)<=n && !done){
		//cout <<"c" <<endl;
		calculate_min(i,j+1,count);
	}

	if((j-1)>=1 && !done){
		//cout <<"d" <<endl;
		calculate_min(i,j-1,count);
	}

}


int main(){
	int t;
	cin >>t;

	while(t--){
		
		res=-1;

		cin >>n >>sx >>sy >>ex >>ey >>bx >>by;

		for(int i=0;i<25;i++){
			for(int j=0;j<25;j++){
				mat[i][j]=0;
				visited[i][j]=false;
			}
		}
		done =false;
		calculate_min(sx,sy,0);

		for(int i=0;i<4;i++){
			for(int j=0;j<4;j++){
				cout <<mat[i][j] <<" ";
			}
			cout <<endl;
		}


		cout <<mat[ex][ey] <<endl;
		


	}

	return 0;
}