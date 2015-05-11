	#include <iostream>

	using namespace std;

	char getFirstLetter(char c){
		if(c>='a' && c<='z'){
			return (c-32);
		}else{
			return c;
		}
		
	}


	char getProperLetter(char c){
		if(c>='A' && c<='Z'){
			return (c+32);
		}
		else{
			return c;
		}

	}

	int main(){

		char inp[106];

		cin >>inp;

		cout <<getFirstLetter(inp[0]);

		for(int i=1;inp[i]!=0;i++){
			cout <<getProperLetter(inp[i]);
		}
		cout <<endl;
		
		return 0;
	}