/*
 The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R

And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);

convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR". 

*/

#include <iostream>
#include <cstring>

using namespace std;

string convert(string s, int numRows) {
	string t="";
	int index1,index2,j,k;
	if(numRows==1)
		return s;
	int max=2*(numRows)-2;
	for(int i=0;i<numRows;i++){
		index1=2*(numRows-i)-2;
		index2=max-index1;
		j=i;
		//cout <<"i:" <<i <<" index1:" <<index1 <<" index2:" <<index2 <<endl;
		while(j<s.size()){
			
			if(index1!=0){
				t=t+s[j];
				j=j+index1;
				if(j>=s.size())
				break;
				
			}
			if(index2!=0){
				t=t+s[j];
				j=j+index2;
				if(j>=s.size())
				break;
			}
			
		}
	}
	return t;        
}

int main(){

	string s;
	int n;

	cin >>s >>n;

	cout <<convert(s,n) <<endl;

	return 0;
}