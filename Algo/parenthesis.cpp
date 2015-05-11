#include <iostream>
#include <stack>
#include <string>

using namespace std;
bool iscorrect(string s){
			
		stack<char> st;
        
        for(int i=0;s[i]!=0;i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='[')
                st.push(s[i]);
            else if(s[i]==')'){
                if(st.size()==0 || st.top()!='(')
                    return false;
                else
                    st.pop();
            }   
           else if(s[i]=='}'){
                if(st.size()==0 || st.top()!='{')
                    return false;
                else
                    st.pop();
            }    
            else if(s[i]==']'){
                if(st.size()==0 || st.top()!='[')
                    return false;
                else
                    st.pop();
            }    
        }
        
        if(st.size()==0)
            return true;
        else
            return false;
}

int main(){
	string s;
	cin >>s;
	if(iscorrect(s))
		cout <<"proper" <<endl;
	else
		cout <<"wrong" <<endl;

}