/*
 Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Some examples:

  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6

*/

#include <iostream>
#include <vector>
#include <cstring>
#include <stack> 
#include <string>
using namespace std;

stack<string> mystack;

string operators[4]={"+","-","*","/"};


bool isoperator(string val){

	for(int i=0;i<4;i++){
		if(operators[i].compare(val)==0)
			return true;
	}

	return false;

}

int getnum(string val){
	int result=0;
	bool flag=false;
	
	for(int i=0;i<val.size();i++){

		if(i==0){
			if(val[0]=='-'){
				flag=true;
				continue;
			}else if(val[0]=='+'){
				continue;
			}


		}
		
		result=result*10+(val[i]-'0');
	}

	if(flag)
		result*=-1;


	return result;
}

string getstring(int num){
	string str="",final="";
	int temp;
	bool flag=false;

	if(num<0){
		flag=true;
		num*=-1;
	}
		
	while(num>0){
		temp=num%10;
		num=num/10;
		str+=(char)(temp+'0');
	}

	if(flag){
		final+="-";
	}
	
	for (std::string::reverse_iterator rit=str.rbegin(); rit!=str.rend(); ++rit)
		final+=*rit;

	return final;
}

int eval(int l,string o,int r){

		if(operators[0].compare(o)==0)
			 return (l+r);

		if(operators[1].compare(o)==0)
			 return (l-r);

		if(operators[2].compare(o)==0)
			 return (l*r);
			
		if(operators[3].compare(o)==0){
			//cout <<"---------" <<endl;
			//cout <<l <<" / " <<r <<endl;
			 return (l/r);	 	
		}	 
	

}

int evalRPN(vector<string>& tokens) {

	vector<string>::iterator it;
	int left,right,result;

	for(it=tokens.begin();it!=tokens.end();it++){
		//cout <<*it;
		if(isoperator(*it)){
			right=getnum(mystack.top());
			//cout <<" R:" <<right;
			
			mystack.pop();
			left=getnum(mystack.top());
			//cout <<" L:" <<left;
			
			mystack.pop();

			result=eval(left,*it,right);
			//cout <<" Result:" <<result;
			mystack.push(getstring(result));


		}else{
			
			mystack.push(*it);
		}
		//cout <<endl;
		
	}

	       
        return getnum(mystack.top());
}

int main(){

	string inp[13] = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
	vector<string> v(inp,inp+13);

	cout <<evalRPN(v) <<endl;

	return 0;
}