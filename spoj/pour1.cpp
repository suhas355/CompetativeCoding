#include <iostream>

using namespace std;

int gcd(int a,int b){
	int c;
	
	while(a>1 && b>1){
		c=a%b;
		a=b;
		b=c;
	}
	if(b==1 || a==1){
		return false;
	}

	return true;
}



int getSteps(int a,int b,int c){
	int steps=0,p;
	int va=0,vb=0;
	while(va!=c && vb!=c){
			//step1. fill A
			/*va=a;
			steps++;
			//check
			if(va==c || vb==c)
				return steps;*/
			va=a;

			//step 2: pour A -> B
			va = va - (b-vb);
			vb = b;
			steps+=2;
			//check
			if(va==c || vb==c)
				return steps;

			//step 3: empty B
			vb=0;
			
			//step4. pour A -> B
			if(va>=b){
				va = va - b;
				vb = b;
			}else{
				vb = va;
				va = 0;

			}
			steps+=2;
			//check
		/*	if(va==c || vb==c)
				return steps;*/


	}

	return steps;
}




int main(){
	int t,a,b,c,x;
	cin >>t;
	while(t--){
		cin >>a >>b >>c;
		if((a+b)<c){
			cout <<"-1" <<endl;
			continue;
		}

		if(a==c || b==c){
			cout <<"1" <<endl;
			continue;
		}

		if(b>a){
			x=a;
			a=b;
			b=x;
		}

		if(!gcd(a-b,c)){
			cout <<"-1" <<endl;
			continue;
		}

		cout <<getSteps(a,b,c) <<endl;

	}
}