#include<iostream>
#define ll long long 

using namespace std;

int main(){
	ll a,b,s;

	cin >>a >>b >>s;

	if(a<0){
		a=a*-1;
	}

	if(b<0){
		b=b*-1;
	}

	ll t=a+b;

	if(t>s){
		cout <<"No" <<endl;
		return 0;
	}

	if((s-t)%2==0){
		cout <<"Yes" <<endl;
	}else{
		cout <<"No" <<endl;
	}
	
	return 0;
}
