#include <iostream>
#include <cstring>

using namespace std;

string zigzag(string inp,int rowSize){
	string out="";
	int inplen=inp.length();
	int offset,cur;
	for(int i=0;i<rowSize;i++){
		offset=2*(rowSize-1-i);
		cur=i;
		out+=inp[cur];
		while(((cur+offset)<inplen)){
			if(offset==0)
				offset=2*(rowSize-1);
			cur=cur+offset;
			out+=inp[cur];
		}

	}
	return out;
}

int main(){

	string inp;
	int row;
	cin >>inp >>row;

	cout <<zigzag(inp,row) <<endl;
	
	return 0;
}