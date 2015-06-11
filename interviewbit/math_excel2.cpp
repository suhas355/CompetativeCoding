#include <iostream>
#include <string>

using namespace std;

string convertToTitle(int n){
	int temp;
	string res1="",res2="";

	while(n>0){
		temp=n%26;
		n/=26;
		if(temp==0){
			temp=26;
			n--;
		}

		temp--;
		
		res1+=(char)('A'+temp);
	}

	for(int i=res1.size()-1;i>=0;i--){
		res2+=res1[i];
	}

	return res2;

}

int main(){
	int inp;

	cin >>inp;

	cout <<convertToTitle(inp) <<endl;

	return 0;
}
