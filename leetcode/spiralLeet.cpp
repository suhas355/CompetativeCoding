/**

Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

For example,
Given the following matrix:

[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]

You should return [1,2,3,6,9,8,7,4,5]. 

**/
#include <iostream>
#include <vector>

using namespace std;


vector<int> spiral(vector<vector<int> >& mat){
	
	vector<int> result;

	int xmax = mat.size();
	//cout <<"xmax " <<xmax <<endl;
	if(xmax==0)
		return result;

	int ymax = mat[0].size();
	//cout <<"ymax " <<ymax <<endl;
	if(ymax==0)
		return result;
	int maxCount = xmax*ymax;
	
	int xmin=-1;
	int ymin=-1;
	int count =0;
	
	bool right,left,up,down;
	right=true;
	left=up=down=false;
	int i,j;
	i=j=0;
	
	while(count<maxCount){
		/*if(left)
			cout <<"left ";
		if(right)
			cout <<"right ";
		if(up)
			cout <<"up ";
		if(down)
			cout <<"down ";
		
		cout <<"count: " <<count  <<"  xmin: " <<xmin <<"  ymin: " <<ymin <<"  xmax: " <<xmax <<" ymax: " <<ymax <<endl;*/
		if(right){
			//cout <<mat[i][j] <<" ";
			result.push_back(mat[i][j]);
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
			//cout <<mat[i][j] <<" ";
			result.push_back(mat[i][j]);
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
			//cout <<mat[i][j] <<" ";
			result.push_back(mat[i][j]);
			j--;
			count++;
			if(count==maxCount)
				break;
			if(j==ymin){
				j++;
				
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
			//cout <<mat[i][j] <<" ";
			result.push_back(mat[i][j]);
			i--;
			count++;
			if(count==maxCount)
				break;
			if(i==xmin){
				i++;
				
				j++;
				ymin++;
				up=false;
				right=true;
				if(count==maxCount){
					cout <<"break";
					break;
				}
				continue;
			}
		}

	}

	return result;

}

int main(){

	
	vector<vector<int> > vect;

	vector<int> temp;
	temp.push_back(1);
	temp.push_back(2);
	temp.push_back(3);
	temp.push_back(4);
	vect.push_back(temp);

	temp.clear();
	temp.push_back(12);
	temp.push_back(13);
	temp.push_back(14);
	temp.push_back(5);
	vect.push_back(temp);

	
	temp.clear();
	temp.push_back(11);
	temp.push_back(16);
	temp.push_back(15);
	temp.push_back(6);
	vect.push_back(temp);

/*	temp.clear();
	temp.push_back(10);
	temp.push_back(9);
	temp.push_back(8);
	temp.push_back(7);
	vect.push_back(temp);*/

    temp.clear();
    temp=spiral(vect);

	for(int i=0;i<temp.size();i++)
		cout <<temp[i] <<" ";
	cout <<endl; 	



	return 0;
}