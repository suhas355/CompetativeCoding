#include <iostream>
#include <stack>


using namespace std;


stack<int> mystack,minstack;


int getMin() {

	if(minstack.empty()){
		return -1;
	}
	return minstack.top();
   
}
    
void push(int x) {

	mystack.push(x);

	if(minstack.empty()){
		minstack.push(x);
		return;
	}

	if(x<minstack.top()){
		minstack.push(x);
		return;
	}

	
		int y=minstack.top();
		minstack.push(y);
	
}

void pop() {

	mystack.pop();
	minstack.pop();

}


int top() {

	return mystack.top();

      
}

int main(){


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
