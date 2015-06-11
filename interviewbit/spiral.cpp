#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > generateMatrix(int A) {
	vector<vector<int> > res ;

	vector<int> temp(A);
	fill(temp.begin(),temp.end(),0);

	for(int i=0;i<A;i++){
		res.push_back(temp);
	}

	int xmin=0,ymin=0,xmax=A-1,ymax=A-1;

	bool right,left,up,down;
	right=true;
	left=false;
	up=false;
	down=false;

	int max=A*A,count=1;
	int i=0,j=0;

	while(count<=max){
		if(right){
			res[i][j]=count;
			if(j==ymax){
				count++;
				right=false;
				down=true;
				xmin++;
				i++;
				continue;
			}
			count++;
			j++;
			

		}else if(down){
			res[i][j]=count;
			if(i==xmax){
				count++;
				down=false;
				left=true;
				ymax--;
				j--;
				continue;
			}
			count++;
			i++;

		}else if(left){
			res[i][j]=count;
			if(j==ymin){
				count++;
				left=false;
				up=true;
				xmax--;
				i--;
				continue;
			}
			count++;
			j--;

		}else if(up){
			res[i][j]=count;
			if(i==xmin){
				count++;
				up=false;
				right=true;
				ymin++;
				j++;
				continue;
			}
			count++;
			i--;

		}
	}


	
	return res;
}

int main(){

 	int n;
 	cin >>n;

 	vector<vector<int> > result=generateMatrix(n); 
 	vector<vector<int> >::iterator it1;
 	vector<int>::iterator it2;
 	vector<int> temp;

 	cout <<"[ ";
 	for(it1=result.begin();it1!=result.end();++it1){
 		temp=*it1;
 		cout <<"[ ";
 		for(it2=temp.begin();it2!=temp.end();it2++){
 			cout <<*it2 <<", ";
 		}
 		cout <<" ] " ;
 	}

 	cout <<"]" <<endl;



 	return 0;
 }