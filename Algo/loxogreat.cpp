#include <iostream>

using namespace std;

bool flag=true,isproper=false;
char a[105],b[105],c[105];

void check(){
	int i;
	for(i=0;a[i]!=0;i++){
		if(a[i]==b[i])
			c[i]=a[i];
		else if(a[i]+1 == b[i]){
			c[i]=b[i];
		}else if(a[i]>b[i]){
			c[i]=b[i];
		}
		else{
			c[i]=b[i]-1;
			isproper=true;

		}

	}
	c[i]=0;
	if(!isproper){
		flag=false;
	}
}


int main(){

	cin >>a >>b;

	check();

	if(flag){
		cout <<c <<endl;
	}else{
		cout <<"No such string" <<endl;
	}

}