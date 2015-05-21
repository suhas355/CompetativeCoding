#include <iostream>
#include <cstdlib>
#include <climits>

using namespace std;


int ** getMatrix(int v){
	int **a=(int **)malloc(sizeof(int *)*v);

	for (int i = 0; i < v; i++){
			a[i]=(int *)malloc(sizeof(int)*v);
			for(int j=0;j<v;j++){
				a[i][j]=-1;
			}
			//a[i][i]=0;
	}

	return a;
	
}

void printAdjMat(int **a,int v){
	for(int i=1;i<=v;i++){
		for(int j=1;j<=v;j++){
			cout <<a[i][j] <<" ";
		}
		cout <<endl;
	}
}

int getMinVertex(int *dist,bool *visited,int v){
	int min=INT_MAX,minIndex=-1;
	//cout <<"getmin: ";
	for(int i=1;i<=v;i++){
		//cout <<dist[i] <<"    " ;
		if(visited[i]==false && dist[i]!=-1 && dist[i]<min){
			
			min=dist[i];
			minIndex=i;
		}
	}
	//cout <<endl;

	return minIndex;
}

void findShortestPath(int v,int e){
	//1. get adj matrix
	int **adj=getMatrix(v+1);

	//2. to get input and fill adj matrix
	int v1,v2,e1,src,dest;
	for(int i=0;i<e;i++){
		cin >>v1 >>v2 >>e1;
		adj[v1][v2]=e1;
	}
	cin >>src >>dest;
	//printAdjMat(adj,v);
	//cout <<endl;
	//cout <<"src:" <<src <<" dest:" <<dest <<endl;

	//3. set dist of src to 0 and rest to infinity
	int *dist = (int *)malloc(sizeof(int)*(v+1));
	bool visited[v+1];

	//cout <<"dist:";
	for(int i=1;i<=v;i++){
		dist[i]=adj[src][i];
		visited[i]=false;
		//cout <<dist[i] <<" ";
	}
	//cout <<endl;
	dist[src]=0;
	adj[src][src]=0;
	visited[src]=true;

	int curmin;
	for(int count=1;count<=v;count++){
		curmin=getMinVertex(dist,visited,v);
		//cout <<"curmin: " <<curmin <<endl;
		if(curmin==-1){
			break;
		}

		visited[curmin]=true;

		//cout <<"update dist: "<<endl;

		for(int j=1;j<=v;j++){
			/*cout <<"vertex: " <<j <<endl;
			cout <<"adj[min][vertex]: " <<adj[curmin][j] <<endl;
			cout <<"dist[curmin]: " <<dist[curmin] <<endl;
			cout <<"dist[curmin]+adj[curmin][j] < dist[j]" <<dist[curmin]+adj[curmin][j] <<"  <  " <<dist[j] <<endl;*/
			if (!visited[j] && adj[curmin][j]!=-1 && dist[curmin]!= -1  && ((dist[curmin]+adj[curmin][j] < dist[j]) || (dist[j]==-1))){
           			 dist[j] = dist[curmin] + adj[curmin][j];
           	}
		}
		//cout <<endl;


	}

	if(dist[dest]!=-1){
		cout <<dist[dest] <<endl;
	}else{
		cout <<"NO"<<endl;
	}


	free(adj);
	free(dist);



}



int main(){
	std::ios::sync_with_stdio(false); 

	int t,v,e;

	cin >>t;

	while(t--){
		//cout <<"-----------------------------" <<endl;
		cin >>v >>e;

		findShortestPath(v,e);		
	}

	return 0;
}