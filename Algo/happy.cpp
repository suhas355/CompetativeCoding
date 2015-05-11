#include <iostream>

using namespace std;

int b[105],g[105],bcount,gcount,bhappy,ghappy,total;

int main(){

	cin >>bcount >>gcount;

	int t,n,t1;
	bool flag=false;

	//cout <<"b g" <<endl;

	cin >>t;

	//cout <<"boysin" <<endl;

	for(int i=0;i<t;i++){
		cin >>n;
		b[n]=1;
		bhappy++;
	}

	//cout <<"boys" <<endl;

	cin >>t1;
	//cout <<"gin" <<endl;

	for(int i=0;i<t1;i++){
		cin >>n;
		g[n]=1;
		ghappy++;
	}

	//cout <<"done" <<endl;

	int p=0,max=bcount*gcount;

	while(p<max){
		if(bhappy==bcount && ghappy==gcount){
			flag=true;
			break;
		}
		if(b[p%bcount]==1 && g[p%gcount]==0){
			g[p%gcount]=1;
			ghappy++;
		}
		if(b[p%bcount]==0 && g[p%gcount]==1){
			b[p%bcount]=1;
			bhappy++;
		}

		p++;
	}

	if(flag==true){
		cout <<"Yes" <<endl;
	}else{
		cout <<"No" <<endl;
	}


	
	return 0;
}