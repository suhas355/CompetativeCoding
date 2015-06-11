#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
#define MAX 1005
#define ll long long

struct road
{
	int v1,v2;
	int cost;
	
};

vector<set<int> > subsets;
vector<set<int> >::iterator set_it;

set<int> temp_set,aux_set;
set<int>::iterator subset_it;

ll noOfsubsets=0;

void check_club_subsets(int v1,int v2){
	//cout <<noOfsubsets <<" noOfsubsets" <<endl;
	//cout <<"club_sets: " <<v1 <<" " <<v2 <<endl;
	vector<set<int> >::iterator it1,it2;
	bool is_v1_found=false,is_v2_found=false;
	int iter=0,c1=-1,c2=-1;
	for(set_it=subsets.begin();set_it!=subsets.end();set_it++){
		temp_set=*set_it;
		//cout <<"iter:" <<iter <<" c1:"<<c1 <<" c2:" <<c2 <<endl;

		if(!is_v1_found){
			subset_it=temp_set.find(v1);
			if(subset_it!=temp_set.end()){
				it1=set_it;
				is_v1_found=true;
				c1=iter;
				//cout <<"c1 changed: " <<c1 <<endl;
 			}

		}
		if(!is_v2_found){
			subset_it=temp_set.find(v2);
			if(subset_it!=temp_set.end()){
				it2=set_it;
				is_v2_found=true;
				c2=iter;
				//cout <<"c2 changed: " <<c2 <<endl;
			}

		}

		iter++;

		if(is_v1_found && is_v2_found)
			break;
	}

	if(c1==c2){
		//cout <<"cycle may form" <<endl;
		return;
	}	

	for(subset_it=(*it2).begin();subset_it!=(*it2).end();subset_it++){
		(*it1).insert(*subset_it);
	}
	subsets.erase(it2);
	noOfsubsets--;

}


void handle_new_vertices(int old_vertex,int new_vertex){
	//cout <<"handle new ver: " <<old_vertex <<" " <<new_vertex <<endl;

	if(subsets.size()==0){
		//	cout <<"these are new vertices to make new subsets" <<endl;
			aux_set.clear();
			aux_set.insert(old_vertex);
			aux_set.insert(new_vertex);
			subsets.push_back(aux_set);
			noOfsubsets++;
			return;
	}

	for(set_it=subsets.begin();set_it!=subsets.end();set_it++){
		
		temp_set=*set_it;
		subset_it=temp_set.find(old_vertex);

		if(subset_it!=temp_set.end()){
			(*set_it).insert(new_vertex);
			return;

		}

		subset_it=temp_set.find(new_vertex);

		if(subset_it!=temp_set.end()){
			(*set_it).insert(old_vertex);
			return;

		}
	}


			//cout <<"these are new vertices to make new subsets" <<endl;
			aux_set.clear();
			aux_set.insert(old_vertex);
			aux_set.insert(new_vertex);
			subsets.push_back(aux_set);
			noOfsubsets++;
			//cout <<"noOfsubsets:"<<noOfsubsets <<endl;
	

}




typedef struct road * Road;

Road * getEdges(){
	Road * arr = (Road *)malloc(sizeof(Road)*300005);
	for(int i=0;i<300005;i++){
		arr[i] = (Road)malloc(sizeof(road));
		arr[i]->v1=-1;
		arr[i]->v2=-1;
		arr[i]->cost=-1;
	}
	return arr;
}


bool comparator(const void *p,const void *q){
	int l = ((Road )p)->cost;
    int r = ((Road )q)->cost; 
   return (((Road )p)->cost<((Road )q)->cost);
}



void cstreet(Road * arr,bool *visited,int p,int n,int m){
	int a,b,c;
	for(int i=0;i<m;i++){
		cin >>a >>b >>c;
		arr[i]->v1=a;
		arr[i]->v2=b;
		arr[i]->cost=p*c;
	}

	
//to sort
	int size = sizeof(arr) / sizeof(arr[0]);
	sort(arr,arr+m,comparator);
//add and count
ll count=0,total=0,i=0,prev,cur;	
	while(1){
		//cout <<"00000000000000000000000  noOfsubsets:" <<noOfsubsets <<"  total:" <<total<<endl ;
		//cout <<"i: " <<i <<endl;
		if(count>=n && noOfsubsets==1)
			break;

		if(arr[i]->v1==-1 || arr[i]->v2==-1)
			break;

		//cout <<arr[i]->v1 <<":"<<visited[arr[i]->v1] <<"  "<<arr[i]->v2 <<":"<<visited[arr[i]->v2] <<endl ;
		
		if(visited[arr[i]->v1] && visited[arr[i]->v2]){
			prev=noOfsubsets;
			check_club_subsets(arr[i]->v1,arr[i]->v2);
			cur=noOfsubsets;
			if(prev!=cur){
				total+=arr[i]->cost;
			}
			i++;
			continue;
		}

	
		if(!visited[arr[i]->v1] && !visited[arr[i]->v2]){
			visited[arr[i]->v1]=true;
			visited[arr[i]->v2]=true;
			//cout <<":::1" <<endl;
			handle_new_vertices(arr[i]->v1,arr[i]->v2);
			count+=2;
			total+=arr[i]->cost;
			i++;
			continue;

		}

		if(!visited[arr[i]->v1]){
			visited[arr[i]->v1]=true;
			count++;
			//cout <<":::2" <<endl;
			handle_new_vertices(arr[i]->v2,arr[i]->v1);
			total+=arr[i]->cost;
			i++;
			continue;
		}

		if(!visited[arr[i]->v2]){
			visited[arr[i]->v2]=true;
			count++;
			//cout <<":::3" <<endl;
			handle_new_vertices(arr[i]->v1,arr[i]->v2);
			total+=arr[i]->cost;
			i++;
			continue;
		}

	}

	/*if(noOfsubsets!=1){
		cout <<"error: " <<endl;
	}
*/
	cout <<total <<endl;

}


void flush(Road * arr,bool *visited,int n,int m){

	for(int i=0;i<n+1;i++){
		visited[i]=false;
	}

	//cout <<subsets.size() <<"  subset size" <<endl;
	subsets.clear();
	//cout <<subsets.size() <<"  subset size" <<endl;
	aux_set.clear();
	temp_set.clear();
	noOfsubsets=0;

}

int main(){
	int t,p,n,m;
	cin >>t;
	Road * arr = getEdges();
	bool *visited = (bool *)malloc(sizeof(bool)*1005);

	while(t--){
		cin >>p;
		cin >>n;
		cin >>m;
		//cout <<"--------------------------------------" <<endl;
		flush(arr,visited,n,m);
		
		cstreet(arr,visited,p,n,m);
	}
	
	return 0;
}