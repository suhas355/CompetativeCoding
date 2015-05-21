#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
	string s,t;
	vector<int> index;
	char res[100005];
	int count=0;

	cin >>s >>t;

	for(int i=0;s[i]!=0;i++){
		if(s[i]==t[i]){
			res[i]=s[i];
		}else{
			index.push_back(i);
			count++;
		}
	}

	if(count%2==0){
		vector<int>::iterator it=index.begin();
		int cur=0,half=count/2;
		while(cur<half){
			res[*it]=s[*it];
			it++;
			cur++;
		}

		while(it!=index.end()){
			res[*it]=t[*it];
			it++;
			cur++;
		}

		res[s.size()]=0;
		cout <<res <<endl;

	}else{
		cout <<"impossible" <<endl;
	}

	return 0;
}