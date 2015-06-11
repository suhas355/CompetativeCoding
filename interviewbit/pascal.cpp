#include <iostream>
#include <vector>

using namespace std;

vector<int> getRow(int A) {
    vector <int> a,b;
    
    bool flag=true;
    
    a.push_back(1);
    if(A==0){
        return a;
    }
    
    int temp;
    
    for(int i=1;i<=A;i++){
        
        if(flag){
            //put result to b
            b.clear();
            
            for(int j=0;j<=i;j++){
               
                if(j>=0){
                    temp=a[j-1]+a[j];
                }else{
                    temp=a[j];
                }
                
                b.push_back(temp);
            }
            
        }else{
            //put result to a
            a.clear();
              for(int j=0;j<=i;j++){
                
                if(j>=0){
                    temp=b[j-1]+b[j];
                   
                }else{
                    temp=b[j];
                }
                
                a.push_back(temp);
            }
            
        }
        
        flag=!flag;
    }
    
    if(A%2!=0)
        return b;
    else
        return a;
}

int main(){
	int k;
	cin >>k;

	vector<int> res= getRow(k);
	vector<int>::iterator it=res.begin();

	for(;it!=res.end();it++){
		cout <<*it <<" ";
	}
	cout <<endl;
	return 0;
}