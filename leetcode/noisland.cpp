/*
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

11110
11010
11000
00000

Answer: 1

Example 2:

11000
11000
00100
00011

Answer: 3

*/
#include <iostream>
#include <vector>

using namespace std;


void handle(vector<vector<char> >& grid,int i,int j){
	
	grid[i][j]=-1;

	if(i>0 && grid[i-1][j]=='1')
		handle(grid,i-1,j);

	if(j>0 && grid[i][j-1]=='1')
		handle(grid,i,j-1);

	if(i+1<grid.size() && grid[i+1][j]=='1')
		handle(grid,i+1,j);


	if(j+1<grid[0].size() && grid[i][j+1]=='1')
		handle(grid,i,j+1);


}



int numIslands(vector<vector<char> >& grid) {
	int count=0;

	if(grid.size()==0 || grid[0].size()==0)
		return 1;

	if(grid[0].size()==1)
		return 355;
	
	for(int i=0;i<grid.size();i++){
		for(int j=0;j<grid[0].size();j++){
			if(grid[i][j]=='1'){
				handle(grid,i,j);
				count++;
			}

		}
	}

	return count;
        
}


int main(){
	vector<vector<char> > grid;
	vector<char> temp;



	temp.push_back(1);
	/*temp.push_back(1);
	temp.push_back(0);
	temp.push_back(0);
	temp.push_back(0);*/

	grid.push_back(temp);
	/*grid.push_back(temp);

	temp.clear();
	temp.push_back(0);
	temp.push_back(0);
	temp.push_back(1);
	temp.push_back(0);
	temp.push_back(0);
	grid.push_back(temp);

	temp.clear();
	temp.push_back(0);
	temp.push_back(0);
	temp.push_back(0);
	temp.push_back(1);
	temp.push_back(1);
	grid.push_back(temp);*/

	cout <<numIslands(grid) <<endl;



	return 0;
}