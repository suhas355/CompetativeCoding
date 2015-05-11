#include <iostream>
#define ll long long
using namespace std;

bool possible=false;
ll a,b,max1;

void check(ll x,ll y,ll s){
	if(possible==true)
		return;

	if(s==max1 && x==a && y==b){
		possible=true;
		return;
	}

	if(s>=max1){
		return;
	}

	check(x+1,y,s+1);
	check(x-1,y,s+1);
	check(x,y+1,s+1);
	check(x,y-1,s+1);
}

int main(){
	

	cin >>a >>b >>max1;

	check(0,0,0);

	if(possible==true){
		cout <<"Yes"<<endl;
	}else{
		cout <<"No" <<endl;
	}

	
	return 0;
}

