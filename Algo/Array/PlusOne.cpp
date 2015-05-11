#include <iostream>
#include <vector>


using namespace std;

vector<int> plusOne(vector<int> &digits) {

	int temp,carry=0;
	vector<int>::iterator it;

	for(it = digits.end()-1;it!=digits.begin();--it){
		//cout <<"before " <<*it;
		temp=*it;
		if(it==digits.end()-1)
			temp++;
		temp+=carry;
		if(temp>9){
			carry=1;
			temp=0;
		}
		else{
			carry=0;
		}
		*it=temp;
		//cout <<" "<<*it <<endl;
	}
		//cout <<"before " <<*it;
		temp=*it;
		if(it==digits.end()-1)
			temp++;
		temp+=carry;
		if(temp>9){
			carry=1;
			temp=0;

		}
		else{
			carry=0;
		}
		*it=temp;
		//cout <<" "<<*it <<endl;
		if(carry==1){
			digits.insert(it,1);
		}

		return digits;

        
}


int main(){

	int myints[] = {9,9,9};
    vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

    vector<int> digits = plusOne(fifth);
	for(vector<int>::iterator it = digits.begin();it!=digits.end();++it){
		cout <<*it;
	}
	cout <<endl;



	
}