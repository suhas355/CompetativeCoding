#include <iostream>
#include <cstring>
#include <ctype.h>


using namespace std;
int room,len,t;
string c;
char reqKey;

int main(){

cin >>t;
while(t--){
	//cout <<"tt" <<endl;

	cin  >>len;
	char key[len+5],door[len+5];

	for(int i=0;i<len-1;i++)
	  cin >>key[i] >>door[i];

	int hash[26];
	for(int i=0;i<26;i++)
		hash[i]=0;
	int count =0;

	

	for(int i=0;i<len-1;i++){
		
		reqKey = tolower(door[i]);
		if(key[i] != reqKey){
			//keys
			hash[key[i]-'a']++;
			//cout <<c[i] <<hash[c[i]-'a'] <<endl;
			
		
			//doors
			if(hash[tolower(door[i])-'a']==0){
				count++;
			}else{
				hash[tolower(door[i])-'a']--;
				//cout <<c[i] <<hash[tolower(c[i])-'a'] <<endl;
			}
		}	
			
		
	}

	cout <<count <<endl;

}

	return 0;
}