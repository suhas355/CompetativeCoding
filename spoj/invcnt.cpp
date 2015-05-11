/*
INVCNT - Inversion Count
no tags 

Let A[0...n - 1] be an array of n distinct positive integers. If i < j and A[i] > A[j] then the pair (i, j) is called an inversion of A. Given n and an array A your task is to find the number of inversions of A.
Input

The first line contains t, the number of testcases followed by a blank space. Each of the t tests start with a number n (n <= 200000). Then n + 1 lines follow. In the ith line a number A[i - 1] is given (A[i - 1] <= 10^7). The (n + 1)th line is a blank space.
Output

For every test output one line giving the number of inversions of A.
Example

Input:

2

3
3
1
2

5
2
3
8
6
1


Output:

2
5
*/

#include <iostream>
#define ll long long

using namespace std;
ll count;

void merge(ll *a,ll low,ll mid,ll high){
	ll c[high-low+1];
	int i=low,j=mid+1,k=0;

	while (i <= mid && j <= high){
		if(a[i]<a[j]){
			c[k]=a[i];
			k++;
			i++;
		}else{
			c[k]=a[j];
			count+=mid-i+1;
			k++;
			j++;
		}
	}

	while(i<=mid){
		c[k]=a[i];
		k++;
		i++;
	}
	while(j<=high){
		c[k]=a[j];
		k++;
		j++;
	}
	
	for(i=low,k=0;i<=high;i++){
		a[i]=c[k++];
		//cout <<c[i] <<" ";
		
	}
	//cout <<endl;
	
}


void mergesort(ll *a, ll low,ll high){
	ll mid;
	if(low<high){
		mid=(high+low)/2;
		mergesort(a,low,mid);
		mergesort(a,mid+1,high);
		merge(a,low,mid,high);
		

	}

}


int main(){
	ll t,n;
	char space;
	cin >>t;
	//cin >>space;
	while(t--){
		count=0;
		cin >>n;
		ll a[n+1];
		for(int i=0;i<n;i++){
			cin >>a[i];

		}
		//cin >>space;
		mergesort(a,0,n-1);
		
		cout <<count <<endl;
	}
	return 0;
}