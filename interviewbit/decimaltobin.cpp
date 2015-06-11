#include <iostream>
#include <string>

using namespace std;

string dectobin(int n){
	string res="",final="";
	int temp;

	if(n==0)
		res+="0";

	while(n>0){
		temp=n%2;
		res+=(char)(temp+'0');
		n/=2;
	}


	for(int i=res.size()-1;i>=0;i--){
		final+=res[i];
	}

	return final;


}

int main(){

	int n;

	cin >>n;

	cout <<dectobin(n) <<endl;
	
	return 0;
}