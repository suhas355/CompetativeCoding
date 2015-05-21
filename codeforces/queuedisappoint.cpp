#include <iostream>
#include <algorithm>
#define ll long long

using namespace std;

ll a[100005];

int main(){

	ll n;
	cin >>n;

	for(ll i=0;i<n;i++){
		cin >>a[i];
	}

	sort(a,a+n);

	ll time1=0,count=0;

	for(int i=0;i<n;i++){
		if(time1>a[i]){
			count++;
		}
		time1+=a[i];
	}

	cout <<(n-count) <<endl;




	return 0;
}