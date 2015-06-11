#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int max(int x, int y)
{ return (y > x)? y : x; }

int maxSubArray(const vector<int> &a)
{
   int size=a.size();
   int max_so_far = a[0], i;
   int curr_max = a[0];
 
   for (i = 1; i < size; i++)
   {
        curr_max = max(a[i], curr_max+a[i]);
        max_so_far = max(max_so_far, curr_max);
   }
   return max_so_far;
}

int maxSubArray1(const vector<int> &A) {

	int i=0,j=0,max=INT_MIN,sum=0;
	int n=A.size();
	while(1){
		if(i==n)
			break;

		if(j==n-1 || sum>(sum+A[j])){
			sum-=A[i];
			i++;
		}else{
			sum+=A[j];
			j++;
		}

		if(max<sum)
			max=sum;


	}

	return max;

}

int main(){

  int inp[10]={ -2, 1, -3, 4, -1, 2, 1, -5, 4};// { −2,1,−3,4,−1,2,1,−5,4};
  vector<int> a;

  for(int i=0;i<9;i++)
  	a.push_back(inp[i]);

  cout <<maxSubArray(a) <<endl;

  //cout <<maxSubArraySum(inp,9) <<endl;

	return 0;
}