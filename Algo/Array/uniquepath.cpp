#include <iostream>

using namespace std;

    int uniquePathsWithObstacles(vector<vector<int> > &a) {
        
        int m=a.size();
        int n=a[0].size();
        
        int path[m][n];
        
        if(a[0][0]==1 || a[m-1][n-1]==1)
             return 0;
             
    bool flag=true;         
     
     for(int i=0;i<m;i++){
        if(flag){
            if(a[i][0]==1){
                flag=false;
                path[i][0]=0;
            }else{
                path[i][0]=1;
            }
        }else{
            path[i][0]=0;
        }
     }
     flag=true;
     for(int i=0;i<n;i++){
        if(flag){
            if(a[0][i]==1){
                flag=false;
                path[0][i]=0;
            }else{
                path[0][i]=1;
            }
        }else{
            path[0][i]=0;
        }
     }
     
      
     for(int i=1;i<m;i++){
         for(int j=1;j<n;j++){
             if(a[i][j]==0)
             path[i][j]=path[i-1][j]+path[i][j-1];
             else
             path[i][j]=0;
         }
     }
     
     return path[m-1][n-1];
        
    }
};
int main(){

	int m,n;

	cin >>m >>n;

	cout <<path(m,n);

	return 0;
}