#include <iostream>
#include <cmath>


using namespace std;

int max(int a,int b){
	return (a>b)?a:b;
}


int main(){
	int e,m,f,s,e1,m1,f1,s1,ee,mm,ff,ss,maxRatio;

	while(1){
		cin >>e >>f >>s >>m >>e1 >>f1 >>s1 >>m1;

		if(e==-1  && f==-1 && s==-1 && m==-1){
			return 0;
		}

		if(e1==0 && f1==0 && s1==0 && m1==0){
			cout <<"0 0 0 0" <<endl;
			continue;
		}

		if(e1!=0)
			ee = (int)ceil((float)e/(float)e1);
		else
			ee=0;
		if(f1!=0)
			ff = (int)ceil((float)f/(float)f1);
		else
			ff=0;
		if(s1!=0)
			ss = (int)ceil((float)s/(float)s1);
		else
			ss=0;
		if(m1!=0)
			mm = (int)ceil((float)m/(float)m1);
		else
			mm=0;

		maxRatio=max(ee,max(ff,max(ss,mm)));

		ee = e1*maxRatio - e;
		ff=f1*maxRatio-f;
		ss=s1*maxRatio-s;
		mm=m1*maxRatio-m;

		cout <<ee <<" " <<ff <<" " <<ss <<" " <<mm <<endl;

	}
	
	return 0;
}