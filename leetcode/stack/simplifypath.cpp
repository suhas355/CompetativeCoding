/*

Given an absolute path for a file (Unix-style), simplify it.

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"

click to show corner cases.
Corner Cases:

    Did you consider the case where path = "/../"?
    In this case, you should return "/".
    Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
    In this case, you should ignore redundant slashes and return "/home/foo".

*/    

#include <iostream>
#include <string>
#include <stack>

using namespace std;

stack<string> mystack,aux;

string simplifyPath(string path) {

	//cout <<"here" <<endl;

	string result = "/";

	string temp="";
	string current =".";
	string parent="..";

	int i=0;

	while(path[i]!=0){
		//cout <<path[i]<<endl;
		if(path[i]=='/'){
			if(current.compare(temp)==0){
				temp="";
				i++;
				continue;
			}

			if(parent.compare(temp)==0){
				if(!mystack.empty())
					mystack.pop();
				temp="";
				i++;
				continue;
			}

			if(temp.size()>0){
				
				mystack.push(temp);
			}
			temp="";
			i++;
			continue;

		}
		temp+=path[i++];
	}

	if(temp.size()>0){
		if(parent.compare(temp)==0){
			if(!mystack.empty())
					mystack.pop();
		}else if(!(current.compare(temp)==0)){
				mystack.push(temp);
		}		
	}

	while(!mystack.empty()){
		aux.push(mystack.top());

		mystack.pop();
	}

	while(!aux.empty()){
		//cout <<"res: " <<result <<endl;
		result+=aux.top()+"/";
		//cout <<"res: " <<result <<endl;

		aux.pop();
	}

	result[result.size()-1]=0;
	string empty="";
	if(empty.compare(result)==0 )
		return "/";

	if(result[1]==0 || (result[1]=='.' && result.size()<=3)){
		//cout <<"hehe";
		return "/";
	}
	string final="";
	int j=0;

	while(result[j]!=0){
		final+=result[j];
		j++;
		//cout <<"das " <<j <<endl;
	}

	final[j]=0;

	return final;


        
}


int main(){

	string inp;

	cin >>inp;

	cout <<simplifyPath(inp) <<endl;


	return 0;
}