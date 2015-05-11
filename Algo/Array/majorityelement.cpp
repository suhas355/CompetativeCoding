#include <iostream>
#include <vector>
using namespace std;


int majorityElement(vector<int> &num) {

	int maxIndex=0;
	int count=0;
	vector<int>::iterator it,it2;
	it2=num.begin();
	for(it=num.begin();it!=num.end();++it){
		if(*it==*it2){
			count++;
		}else{
			count--;
			if(count==0){
				it2=it;
				count=1;
			}
		}
	}

	return *it2;

}


int main(){

	vector<int> a;
	a.push_back(1);
	a.push_back(3);
	a.push_back(1);
	a.push_back(3);
	a.push_back(3);

	cout <<majorityElement(a) <<endl;

	return 0;
}

