#include <iostream>
#include <string>
using namespace std;


bool isPalindrome(int A){

	if(A<0)
		return false;
	if(A<=9){
		return true;
	}

	string bin="";

	int temp;
	while(A>0){
		temp=A%10;
		A/=10;
		bin+=(char)(temp+'0');

	}

	int len=bin.size();

	//cout <<bin <<endl;

	for(int i=0,j=len-1;i<j;i++,j--){
		//cout <<"i:" <<bin[i] <<"  j:" <<bin[j] <<endl;
		if(bin[i]!=bin[j])
			return 0;

	}

	return 1;
}


bool isPalin(int A){
	string bin="",bin2;
	int len =0;
	if(A==0  || A==1){
		return true;
	}else{
		int temp;

		while(A>0){
			temp=A%2;
			A/=2;
			bin+=(char)(temp+'0');
			len++;
		}

	}

	for(int i=len-1,j=0;i>=0;i--,j++){
		bin2[j]=bin[i];
	}

	cout <<bin <<endl;
	for(int i=0;i<len;i++){
		cout <<"i: " <<bin[i] <<"   j:" <<bin2[i] <<endl;
		if(bin[i]!=bin2[i])
			return false;
	}

	return true;


}

int main(){

	int n;

	cin >>n;

	if(isPalindrome(n)){
		cout <<"yes" <<endl;
	}else{
		cout <<"no" <<endl;
	}


	return 0;
}