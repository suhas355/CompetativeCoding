#include <iostream>
#include <cstring>
#include <map>
#include <ctype.h>
#define ll long long

using namespace std;

int main(){

	ll t;
	cin >>t;

	while(t--){

	ll room,len;
	string s;

	cin >>room >>len >>s;

	map<char,ll> bag;
	map<char,ll>::iterator it=bag.begin();
	ll count =0;

	for(ll i=0;s[i]!=0;i++){
		if(i%2==0){
			//keys
			it=bag.find(s[i]);
			if(it==bag.end()){
				bag[s[i]]=1;
			}else{
				it->second++;
			}
		}else{
			//doors
			it=bag.find(tolower(s[i]));
			if(it==bag.end()){
				count++;
			}else{
				it->second--;
				if(it->second==0){
					bag.erase(it);
				}

			}
		}
	}

	cout <<count <<endl;
}



	return 0;
}