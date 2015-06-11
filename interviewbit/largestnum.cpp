/*


Given a list of non negative integers, arrange them such that they form the largest number.

For example:

Given [3, 30, 34, 5, 9], the largest formed number is 9534330.

Note: The result may be very large, so you need to return a string instead of an integer.

*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


using namespace std;

string getnum(int num){
	string res="",final;
	int temp;
	if(num==0)
		return "0";
	while(num>0){
		temp=num%10;
		//cout <<temp <<" --->"<<(char)(temp+'0') <<endl;;
		res+=(char)(temp+'0');
		num/=10;
	}

	final="";
	for(int i=res.size()-1;i>=0;i--){
		final+=res[i];
	}

	return final;
}


bool cmp(string  c1,string c2){
	string p1,p2;
	p1=c1+c2;
	p2=c2+c1;

	for(int i=0;p1[i]!=0;i++){
		if(p1[i]<p2[i])
			return false;
		else if(p1[i]>p2[i])
			return true;
	}

	return false;
	

}
string largestNumber(const vector<int> &A) {
	vector<string> inp;
	string temp="";
	int len=A.size();
	for(int i=0;i<len;i++){
		inp.push_back(getnum(A[i]));
	}

	
	sort(inp.begin(),inp.end(),cmp);

	//cout <<"sorted: " <<endl;
	vector<string>::iterator it;
	
	for(it=inp.begin();it!=inp.end();it++){
		//cout <<*it <<" ";
		temp+=*it;

	}

	//cout <<endl;
	for(int i=0;temp[i]!=0;i++){
		if(temp[i]!='0')
			return temp;
	}

	return "0";

}

int main(){

	int a[100]={ 9, 99, 999, 9999, 9998};//{3, 30, 34, 5, 9};
	vector<int> inp;

	for(int i=0;i<5;i++){
		inp.push_back(a[i]);
	}

	cout <<largestNumber(inp) <<endl;


	return 0;
}