#include <iostream>
#define ull unsigned long long


using namespace std;


int main(){
	ull t,n,cur,allocated,temp;

	cin >>t;

	while(t--){
		
		cin  >>n;

		cin >>cur;
		allocated=cur;

		if(n>1){
			for(int i=1;i<n;i++){
				cin >>temp;

				if(temp>cur){
					allocated+=(temp-cur);
				}
				cur=temp;
			}	
		}
		cout <<allocated <<endl;
	}

	return 0;
}