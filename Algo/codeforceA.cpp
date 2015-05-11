#include <iostream>
#define ll long long

using namespace std;

int mat[1002][1002];

int a,b,c,d,e,f,g,h;

bool check(ll x,ll y,ll n,ll m){
	mat[x][y]=1;
	a=b=c=d=e=f=g=h=0;

	if(y+1<m && mat[x][y+1]){
		//cout <<"a" <<endl;
		a=1;
	}
	if(x-1>=0 && y+1<m && mat[x-1][y+1]){
		//cout <<"b" <<endl;
		b=1;
	}
	if(x-1>=0 && mat[x-1][y]){
		//cout <<"c" <<endl;
		c=1;
	}
	if(x-1>=0 && y-1>=0 && mat[x-1][y-1]){
		//cout <<"d" <<endl;
		d=1;
	}
	if(y-1>=0 && mat[x][y-1]){
		//cout <<"e" <<endl;
		e=1;
	}
	if(x+1<n && y-1>=0 && mat[x+1][y-1]){
		//cout <<"f" <<endl;
		f=1;
	}
	if(x+1<n && mat[x+1][y]){
		//cout <<"g" <<endl;
		g=1;
	}
	if(x+1<n && y+1<m &&  mat[x+1][y+1]){
		//cout <<"h" <<endl;
		h=1;
	}

	if((a && b && c) || (c && d && e) || (e && f && g) || (g && h && a))
		return true;

	return false;
	
}

int main(){

	ll n,m,k;

	cin >>n >>m >>k;
	
	ll x,y;
	ll i;
	ll flag=0;
	for(i=0;i<k;i++){
		cin >>x >>y;
		x--;
		y--;
		if(check(x,y,n,m) && flag==0){
			flag=i+1;
			//cout <<flag <<endl;
		}
	}

	if(flag!=0){
		cout <<flag <<endl;
		return 0;
	}

	if(i==k){
		cout <<"0" <<endl;
	}

	return 0;
}