#include<iostream>

using namespace std;

  int getNum(char c){
        switch(c){
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
        }
    }
    int romanToInt(string s) {
        int prev=getNum(s[0]),cur,total=0;
        total = prev;
        for(int i=1;s[i]!=0;i++){
            cur=getNum(s[i]);
            if(cur>prev){
                total+=cur-prev-prev;
            }
            else{
                total+=cur;
            }
            prev=cur;
            
        }
        
        return total;
        
    }

    int main(){
    string s;
    while(1){
    	cin >>s;
    	cout <<romanToInt(s) <<endl;
    }
    return 0;
    }