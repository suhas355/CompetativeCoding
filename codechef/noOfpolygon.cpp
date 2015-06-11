#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#define ull unsigned long long

using namespace std;

struct polygon{
	ull polynum;
	ull area;
	ull rank;

};

typedef struct polygon * Poly;

Poly getnode(int num,int area1){
	Poly temp = (Poly)malloc(sizeof(struct polygon));
	temp->polynum=num;
	temp->area=area1;
	temp->rank=-1;
	return temp;
}
//static int mmm=0;
ull getarea(vector<int> xi,vector<int> yi){
	//cout <<"------------ " <<mmm++ <<"--------" <<endl;
	ull len=xi.size(),i;
	long long res=0;
	for( i=0;i<len-1;i++){
		res+=(xi[i]*yi[i+1]-yi[i]*xi[i+1])/2;
		//cout <<"cur: " <<" xi:" <<xi[i] <<" yi:" <<yi[i] <<" xi+1:" <<xi[i+1] <<" yi+1:" <<yi[i+1] <<" res:" <<res <<endl;
	}
	res+=xi[i]*yi[0]-xi[0]*yi[i]/2;
	//cout <<"cur: " <<" xi:" <<xi[i] <<" yi:" <<yi[i] <<" xi+1:" <<xi[0] <<" yi+1:" <<yi[0] <<" res:" <<res <<endl;
	//res/=2;
	
	//cout <<"area: " <<res <<endl;
	if(res<0){
		res*=-1;
	}

	return res;
}

ull getperimeter(vector<int> xi,vector<int> yi){
	ull len=xi.size(),i;
	float res1=0;
	for( i=0;i<len-1;i++){
		res1+=(xi[i]*yi[i+1]-yi[i]*xi[i+1]);
		res1+=sqrt((xi[i]-xi[i+1])*(xi[i]-xi[i+1]) - (yi[i]-yi[i+1])*(yi[i]-yi[i+1]));
	}
	res1+=sqrt((xi[i]-xi[0])*(xi[i]-xi[0]) - (yi[i]-yi[0])*(yi[i]-yi[0]));
	
	if(res1<0){
		res1*=-1;
	}
	ull res=res1;
	cout <<"area: " <<res <<endl;
	return res;
}

bool area(Poly c1,Poly c2){
	if(c1->area<=c2->area)
		return true;

	return false;
}

bool polnum(Poly c1,Poly c2){
	if(c1->polynum<=c2->polynum)
		return true;

	return false;
}

int main(){

	ull t;
	cin >>t;

	while(t--){

		ull n;
		cin >>n;

		vector<Poly> res;

		for(ull i=0;i<n;i++){
			ull mi;
			cin >>mi;

			vector<int> xi,yi;
			ull x,y,area;
			for(ull j=0;j<mi;j++){
				cin >>x >>y;
				xi.push_back(x);
				yi.push_back(y);
			}
			area=getarea(xi,yi);//getperimeter(xi,yi);//
			Poly temp=getnode(i,area);
			res.push_back(temp);
		}

		sort(res.begin(),res.end(),area);

		vector<Poly>::iterator it;

		ull k=0;
		for(it=res.begin();it!=res.end();it++){
			(*it)->rank=k++;
		}

		sort(res.begin(),res.end(),polnum);

		for(it=res.begin();it!=res.end();it++){
			//cout <<(*it)->polynum <<" " <<(*it)->area <<" " <<(*it)->rank <<" " <<endl;
			cout <<(*it)->rank <<" ";
		}

		cout <<endl;

	}

	return 0;
}