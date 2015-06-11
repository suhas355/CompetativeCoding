#include <iostream>
#include <vector>

using namespace std;

 vector<int> getRow(int numRows) {

 	vector<vector<int> > a;

 	vector<int> temp;
 	numRows++;
 	temp.push_back(1);
 	a.push_back(temp);
 	int num;
 	for(int i=1;i<numRows;i++){

 		vector<int> temp1;

 			for(int j=0;j<i+1;j++){
 				num=0;
 				if(j-1>=0){
 					num=a[i-1][j-1];
 				}
 				if(j<i)
 				num+=a[i-1][j];
 				temp1.push_back(num);
 			}

 			a.push_back(temp1);
 	}

   // cout <<"coming fine" <<endl;
 	return a[numRows-1];

 }


 vector<vector<int> > generate(int numRows) {

 	vector<vector<int> > a;

 	vector<int> temp;
 	if(numRows==0)
 		return a;

 	temp.push_back(1);
 	a.push_back(temp);
 	int num;
 	for(int i=1;i<numRows;i++){

 		vector<int> temp1;

 			for(int j=0;j<i+1;j++){
 				num=0;
 				if(j-1>=0){
 					num=a[i-1][j-1];
 				}
 				if(j<i)
 				num+=a[i-1][j];
 				temp1.push_back(num);
 			}

 			a.push_back(temp1);
 	}

 	return a;

 }

 int main(){

 	int n;
 	cin >>n;

 	vector<vector<int> > result=generate(n); 
 	vector<vector<int> >::iterator it1;
 	vector<int>::iterator it2;
 	vector<int> temp;
 	for(it1=result.begin();it1!=result.end();++it1){
 		temp=*it1;
 		cout <<"[ ";
 		for(it2=temp.begin();it2!=temp.end();it2++){
 			cout <<*it2 <<" ";
 		}
 		cout <<"]" <<endl;
 	}

 	cout <<"--------------------" <<endl;
 	temp=getRow(n);

 	for(it2=temp.begin();it2!=temp.end();it2++){
 			cout <<*it2 <<" ";
 		}
 		cout <<"]" <<endl;


 	return 0;
 }