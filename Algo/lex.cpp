#include <iostream>

using namespace std;

int main(){

	char s[110],t[110],nStr[110];
	cin>>s>>t;
	bool isProper = false;
	int i=0;
	for(i=0;s[i]!=0;i++){
		if(s[i] == t[i] ){
			nStr[i] = s[i];
		}else if(s[i] == t[i]-1){
			nStr[i] = t[i];
		}else if(s[i] > t[i]){
			nStr[i] = t[i];
		}else {
			if(isProper){
				nStr[i] = s[i];
			}else{
				nStr[i] = s[i] + 1;
			}
			isProper  = true;
		}
	}
	nStr[i] = 0;
	if(isProper){
		cout<<nStr<<endl;
	}else{
		cout<<"No such string"<<endl;
	}
	return 0;
}