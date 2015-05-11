#include <iostream>

using namespace std;


void spiral(int mat[100][100],int xmax,int ymax){
	int xmin=0;
	int ymin=0;
	int count =0;
	int maxCount = xmax*ymax;
	bool right,left,up,down;
	right=true;
	left=up=down=false;
	int i,j;
	i=j=0;
	while(count<maxCount){
		if(right){
			cout <<mat[i][j] <<" ";
			j++;
			count++;
			if(count==maxCount)
				break;
			if(j==ymax){
				j--;
				i++;
				right=false;
				down=true;
				xmin++;
				continue;
			}
		}
		if(down){
			cout <<mat[i][j] <<" ";
			i++;
			count++;
			if(count==maxCount)
				break;
			if(i==xmax){
				i--;
				j--;
				down=false;
				left=true;
				ymax--;
				continue;
			}
		}
		if(left){
			cout <<mat[i][j] <<" ";
			j--;
			count++;
			if(count==maxCount)
				break;
			if(j==ymin){
				cout <<mat[i][j] <<" ";
				count++;
				if(count==maxCount)
				break;
				i--;
				xmax--;
				left=false;
				up=true;
				continue;
			}
		}
		if(up){
			cout <<mat[i][j] <<" ";
			i--;
			count++;
			if(count==maxCount)
				break;
			if(i==xmin){
				cout <<mat[i][j] <<" ";
				count++;
				if(count==maxCount)
				break;
				j++;
				ymin++;
				up=false;
				right=true;
				continue;
			}
		}
	}

}

int main(){

	int mat[100][100];
	for(int i=0;i<4;i++){
		mat[0][i]=i+1;
		mat[3][i]=10-i;

	}
	mat[1][0]=12;
	mat[1][1]=13;
	mat[1][2]=14;
	mat[1][3]=5;

	mat[2][0]=11;
	mat[2][1]=16;
	mat[2][2]=15;
	mat[2][3]=6;

	spiral(mat,4,4);
	cout <<endl; 	



	return 0;
}