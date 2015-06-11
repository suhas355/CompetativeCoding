#include <iostream>
#include <string>

using namespace std;

bool isPalin(string s){
	int i=0,j=s.size()-1;

	while(i<j){
		if(s[i]!=s[j])
			return false;

		i++;
		j--;
	}

	return true;
}

int main(){

	int k,len,sublen;
	string inp,sub;

	cin >>inp >>k;

	len = inp.size();

	if(len%k!=0){
		cout <<"NO" <<endl;
		return 0;
	}

	sublen=len/k;

	int j=0;
	for(int i=0;i<len;i++){

		sub+=inp[i];
		j++;
		if(j==sublen){
			j=0;
			if(!isPalin(sub)){
				cout <<"NO" <<endl;
				return 0;
			}
			sub="";
		}

	}

	cout <<"YES" <<endl;


	return 0;
}