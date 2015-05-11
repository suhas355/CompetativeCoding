#include<iostream>
#define ll  unsigned long long
using namespace std;

ll fact(int n){
	switch (n){
		case 0: return 1;
		case 1: return 1;
		case 2: return 2;
		case 3: return 6;
		case 4: return 24;
		case 5: return 120;
		case 6: return 720;
		case 7: return 5040;
		case 8: return 40320;
		case 9: return 362880;
	}
}

ll facto(ll n){
	if(n<=1){
		return 1;
	}
	cout <<n <<endl;
	return n*facto(n-1);
}

ll result(char *inp,int len){
	ll total=1,temp;
	
	for(int i=0;i<len;i++){
		
		temp=fact(inp[i]-'0');
		
		total*=temp;
	}
	

	ll fin=1;

	while(total!=0){
		cout <<total%10 <<endl;
		fin*=fact(total%10);
		total=total/10;
	}
	

	return fin;
}


int main(){

	char inp[20],inp1[20],c;

	cin >>c;

	cin >>inp;

	int i=0,j=0;
	while(inp[i]=='0'){
		i++;
	}

	for(;inp[i]!=0;i++){
		//cout <<inp[i] <<" ";
		inp1[j++]=inp[i];
	}
	//cout <<endl;

	inp1[j]=0;

	cout <<result(inp1,j) <<endl;

	
	return 0;
}