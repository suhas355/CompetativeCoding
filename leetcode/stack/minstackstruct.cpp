#include <iostream>
#include <cstdlib>


using namespace std;


struct stack{
	int top;
	int capacity;
	int *array;
};

typedef struct stack * Stack;


Stack mystack,minstack;

Stack init(int size){
	Stack temp;
	temp = (Stack)malloc(sizeof(struct stack));
	if(temp!=NULL){
		temp->top=-1;
		temp->capacity=size;
		temp->array = (int *)malloc(sizeof(int)*size);

		if(temp->array!=NULL){

			return temp;
		}
	}
	cout <<"null" <<endl;
	return NULL;
}


void push(int x){


	if(mystack->top == mystack->capacity-1){


		//realloc both arrays
		mystack->capacity*=2;
		minstack->capacity*=2;

		mystack->array = (int *)realloc(mystack->array,mystack->capacity);
		minstack->array = (int *)realloc(minstack->array,minstack->capacity);
		if(mystack->array==NULL || minstack->array==NULL)
			return;
	}
	
	mystack->array[++mystack->top]=x;

	if(minstack->top==-1 || (x<minstack->array[minstack->top])){
		minstack->array[++minstack->top]=x;
		return;
	}

	int y=minstack->array[minstack->top];
	minstack->array[++minstack->top]=y;

}

void pop(){
	if(mystack->top>=0){
		mystack->top--;
		minstack->top--;
	}	

}

int top(){
	return mystack->array[mystack->top];
}

int getMin(){
	return minstack->array[minstack->top];
}


int main(){

	mystack=init(1);
	minstack=init(1);


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