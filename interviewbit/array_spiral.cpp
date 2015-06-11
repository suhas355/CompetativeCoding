#include <iostream>
#include <vector>

using namespace std;

vector<int> spiralOrder(const vector<vector<int> > &A) {
	vector<int> res ;

	int row=A.size();
	if(row==0){
		return res;
	}

	int col= A[0].size();
	
	int xmin=0,ymin=0,xmax=row-1,ymax=col-1;

	bool right,left,up,down;
	right=true;
	left=false;
	up=false;
	down=false;

	int max=row*col,count=1;
	int i=0,j=0;

	while(count<=max){
		if(right){
			res.push_back(A[i][j]);
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
			res.push_back(A[i][j]);
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
			res.push_back(A[i][j]);
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
			res.push_back(A[i][j]);
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

 	vector<vector<int> > res;

 	vector<int> inp;

 	inp.push_back(1);
 	inp.push_back(2);
 	inp.push_back(3);
 	res.push_back(inp);
 	inp.clear();


 	inp.push_back(4);
 	inp.push_back(5);
 	inp.push_back(6);
 	res.push_back(inp);
 	inp.clear();


 	inp.push_back(7);
 	inp.push_back(8);
 	inp.push_back(9);
 	res.push_back(inp);
 	inp.clear();



 	vector<int>  temp=spiralOrder(res); 
 	
 	vector<int>::iterator it2;
 	
 	cout <<"[ ";

 	for(it2=temp.begin();it2!=temp.end();it2++){
 			cout <<*it2 <<", ";
 		}
 		cout <<" ] " ;
 	 	cout  <<endl;



 	return 0;
 }