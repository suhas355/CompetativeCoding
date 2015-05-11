#include <iostream>
#include <ctype.h>
#define ll long long;

using  namespace std;

int cap[27],small[27];
int rcap[27],rsmall[27];

char s[200005],t[200005];

int yay=0,woop=0;

void check(){
	for(int i=0;s[i]!=0;i++){
		if(isupper(s[i]))
			cap[s[i]-'A']++;
		else
			small[s[i]-'a']++;
	}


	for(int i=0;t[i]!=0;i++){
		if(isupper(t[i]))
			rcap[t[i]-'A']++;
		else
			rsmall[t[i]-'a']++;
	}

	for(int i=0;i<26;i++){
		if((small[i]-rsmall[i])>0){
			woop+=(small[i]-rsmall[i]);
			yay+=rsmall[i];
		}else{
			yay+=small[i];
		}

		if((cap[i]-rcap[i])>0){
			woop+=(cap[i]-rcap[i]);
			yay+=rcap[i];
		}else{
			yay+=cap[i];
		}


	}

	cout <<yay <<" " <<woop <<endl;
}

int main(){

	cin >>s >>t;

	check();
}