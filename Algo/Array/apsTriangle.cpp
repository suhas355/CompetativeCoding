#include <iostream>
#include <vector>
#include <climits>

using namespace std;


int mat[500][500];
int getMinCount1(int i,int j){
	if(j==0){
		return mat[i-1][j];

	}

	if(i==j){
		return mat[i-1][j-1];
	}

	if(mat[i-1][j-1]<mat[i-1][j])
		return mat[i-1][j-1];
	else
		mat[i-1][j];
}
int getMinCount(int i,int j){
	int min=INT_MAX;

	//int cas=0;
	
	if(j!=0){
		min=mat[i-1][j-1];
		//cas=1;
		//cout <<"::::1 " <<min <<endl;
	}

	if(i!=j){
		if(min>mat[i-1][j]){
			min=mat[i-1][j];
			//cas=2;
			//cout <<"::::2 " <<min <<endl;
		}

	}

	if(j!=i && j+1!=i){
		if(min>mat[i-1][j+1]){
			min=mat[i-1][j+1];
			//cas=3;
			//cout <<"::::3 " <<min <<endl;
		}
	}
	//cout <<"case:" <<cas <<endl;
	return min;
}

int minimumTotal(vector<vector<int> > &triangle) {
        int rowCount=triangle.size();
        //cout <<"---------------" <<endl;

         mat[0][0]=triangle[0][0];
        // cout <<"0" <<" " <<"0" <<" " <<mat[0][0] <<endl;

        for(int i=1;i<rowCount;i++){
        	for(int j=0;j<=i;j++){

        		mat[i][j]=triangle[i][j]+getMinCount1(i,j);
        		//cout <<i <<" " <<j <<" " <<mat[i][j] <<" " <<triangle[i][j] <<endl;
        	}
        }

        int min=mat[rowCount-1][0];

        cout <<mat[rowCount-1][0] <<" ";

        for(int i=1;i<rowCount;i++){

        	if(min>mat[rowCount-1][i])
        		min=mat[rowCount-1][i];

        	cout <<mat[rowCount-1][i] <<" ";
        }
        cout <<endl;
        //cout <<min <<endl;
        return min;
        
        
    }




int main(){
	vector<int> a1,a2,a3,a4;
	vector<vector<int> > tri;
	a1.push_back(-1);
	
	tri.push_back(a1);
	

	a2.push_back(3);
	a2.push_back(2);


	tri.push_back(a2);
	

	a3.push_back(-3);
	a3.push_back(1);
	a3.push_back(-1);
	tri.push_back(a3);


	/*a4.push_back(4);
	a4.push_back(1);
	a4.push_back(8);
	a4.push_back(3);
	tri.push_back(a4);*/

	/*for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			cout <<tri[i][j] <<" ";
		}
		cout <<endl;
	}*/

	cout <<minimumTotal(tri) <<endl;

    return 0;
    }
