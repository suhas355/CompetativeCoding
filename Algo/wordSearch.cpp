#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

bool check(vector<vector<char> > &board,int i,int j,int row,int col, string word){
	if(word.size()==0){
		return true;
	}

	//cout <<i <<" " <<j <<endl;

	if(i!=0){
		if(board[i-1][j]==word.at(0)){
			board[i-1][j]='#';
			//cout <<"1:" <<word.at(0) <<" " <<i <<" "<<j <<endl;
			if(check(board,i-1,j,row,col,word.substr(1))){
				return true;
			}else{
				board[i-1][j]=word.at(0);
			}
		
		}
	}
	if(j!=0){
		if(board[i][j-1]==word.at(0)){
			board[i][j-1]='#';
			//cout <<"2:" <<word.at(0) <<" " <<i <<" "<<j <<endl;
			if(check(board,i,j-1,row,col,word.substr(1))){
				return true;
			}else{
				board[i][j-1]=word.at(0);
			}
		
		}

	}
	if(i!=row-1){
		if(board[i+1][j]==word.at(0)){
			board[i+1][j]='#';
			//cout <<"3:" <<word.at(0) <<" " <<i <<" "<<j <<endl;
			if(check(board,i+1,j,row,col,word.substr(1))){
				return true;
			}else{
					board[i+1][j]=word.at(0);
			}
		
		}
	}

	if(j!=col-1){
		if(board[i][j+1]==word.at(0)){
			board[i][j+1]='#';
			//cout <<"4:" <<word.at(0) <<" " <<i <<" "<<j <<endl;
			if(check(board,i,j+1,row,col,word.substr(1))){
				return true;
			}else{
				board[i][j+1]=word.at(0);
			}
		
		}

	}

	return false;
}


 bool exist(vector<vector<char> > &board, string word) {
       int row=board.size();
       int col;

       for(int i=0;i<row;i++){
       		col=board[i].size();
       		for(int j=0;j<col;j++){
       			if(board[i][j]==word.at(0)){
       				board[i][j]='#';
       				//cout <<"first at: " <<word.at(0) <<i <<" "<<j <<endl;
       				if(check(board,i,j,row,col,word.substr(1))){
       					return true;
       				}else{
       					board[i][j]=word.at(0);
       				}
       			}
       		}
       }
        return false;
    }

int main(){
	char mat[][4] = {
{"CAA"},
{"AAA"},
{"BCD"}
};
vector<vector<char> > matrix;
for(int i=0;i<3;i++){
	vector<char> row(mat[i],mat[i]+3);
	matrix.push_back(row);
}
bool found = exist(matrix,"CAB");
if(found)
	cout <<"found" <<endl;
else
	cout <<"not found " <<endl;


	return 0;
}