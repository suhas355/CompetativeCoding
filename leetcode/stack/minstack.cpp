#include <iostream>
#define MAX 100000

using namespace std;

int stack[MAX],aux[MAX];
int top1=-1,mintop=-1;

int getMin();

void push(int x) {
	//cout <<"insert:" <<x <<endl;
	
		stack[++top1]=x;
		if(mintop==-1 ){
			
			aux[++mintop]=x;
		}else if(aux[mintop]>x){
			//cout <<"comp:" <<aux[mintop] <<" " <<x <<endl; 
			aux[++mintop]=x;
		}else if(aux[mintop]<=x){
			//cout <<"asas" <<endl;
			aux[mintop+1]=aux[mintop];
			mintop++;
		}
	
        
}

void pop() {

	if(top1!=-1){
		mintop--;
		top1--;
	}
        
}

int top() {

	if(top1!=-1)
		return stack[top1];

	else
		return -1;
        
}

int getMin() {

	if(mintop!=-1)
		return aux[mintop];
    
    return -1;    
}


void status(){
	int  t=mintop;
	cout <<"min stack" <<endl;

	while(t>=0){
		cout <<aux[t--] <<" ";
	}
	cout <<endl;

	t=top1;

	cout <<"stack" <<endl;
	while(t>=0){
		cout <<stack[t--] <<" ";
	}
	cout <<endl;
}


int main()
{

	int inp[10]= { 3, 6,8,9,7,1,2};

	push(-2);

	//status();
	push(0);
	//status();
	push(-1);
	//status();
	

	cout <<getMin() <<endl;
	//status();
	cout <<top() <<endl;
	//status();
	pop();
	//status();
	cout <<getMin() <<endl;

	
	
    	
  	return 0;
	
}