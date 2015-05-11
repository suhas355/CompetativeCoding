#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <map>

using namespace std;

vector<vector<int> > subsets(vector<int>& nums) {
        int len = nums.size();
        sort(nums.begin(),nums.end());
        int max = pow(2,len);
        cout <<max <<endl;
        vector<vector<int> > out;
         map < vector<int> , int> hmp0;
         map < vector<int> , int>::iterator it3;

        for(int i=0;i<max;i++){
        	vector<int> temp;
        	for(int j=0;j<len;j++){
        		if(i & (1<<j)){
        			//cout <<nums[j] <<" ";
        			temp.push_back(nums[j]);
        		}
        	}
                it3 = hmp0.find(temp);
                if( it3 == hmp0.end()){
        	       out.push_back(temp);
                       hmp0[temp]=0;
                }
        	//cout <<endl;
        }

        return out;

}


void printIt(vector<vector<int> > temp){
	vector<vector<int> >::iterator it;
	vector<int>::iterator it2;

	for(it=temp.begin();it!=temp.end();++it){
		vector<int> v = *it;
		for(it2=v.begin();it2!=v.end();++it2){
			cout <<*it2 <<" ";
		}
		cout <<endl;
	}

}

int main(){

	vector<int> inp;

	inp.push_back(1);
	inp.push_back(2);
	inp.push_back(2);
	vector<vector<int> > out = subsets(inp);
	printIt(out);


	return 0;
}