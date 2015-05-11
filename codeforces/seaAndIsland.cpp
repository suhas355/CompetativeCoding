/*
B. Sea and Islands
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
A map of some object is a rectangular field consisting of n rows and n columns. Each cell is initially occupied by the sea but you can cover some some cells of the map with sand so that exactly k islands appear on the map. We will call a set of sand cells to be island if it is possible to get from each of them to each of them by moving only through sand cells and by moving from a cell only to a side-adjacent cell. The cells are called to be side-adjacent if they share a vertical or horizontal side. It is easy to see that islands do not share cells (otherwise they together form a bigger island).

Find a way to cover some cells with sand so that exactly k islands appear on the n × n map, or determine that no such way exists.

Input
The single line contains two positive integers n, k (1 ≤ n ≤ 100, 0 ≤ k ≤ n2) — the size of the map and the number of islands you should form.

Output
If the answer doesn't exist, print "NO" (without the quotes) in a single line.

Otherwise, print "YES" in the first line. In the next n lines print the description of the map. Each of the lines of the description must consist only of characters 'S' and 'L', where 'S' is a cell that is occupied by the sea and 'L' is the cell covered with sand. The length of each line of the description must equal n.

If there are multiple answers, you may print any of them.

You should not maximize the sizes of islands.

Sample test(s)
input
5 2
output
YES
SSSSS
LLLLL
SSSSS
LLLLL
SSSSS
input
5 25
output
NO
*/
#include <iostream>

using namespace std;


int mat[102][102];

// -1 ==not_possible 2 == island 0==sea

void printMat(int n,int k){
	int count=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(mat[i][j]==2 && count<k){
				cout <<"L";
				count++;
			}
			else 
				cout <<"S";
		}
		cout <<endl;
	}
}

int xaxis[8] = {1,1,0,-1,-1,-1,0,1};
int yaxis[8] = {0,1,1,1,0,-1,-1,-1};

bool calculate(int n,int k){
	int island=0;

	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(mat[i][j]==-1){
				continue;
			}else{
				bool possible=true;
				for(int k=0;k<8;k++){
					if(mat[i+xaxis[k]][j+yaxis[k]]==2){
							possible=false;
							break;
					}
				}

				if(possible){
					mat[i][j]=2;
					island++;
				}

			}
		}
	}
	if(island<k)
		return false;
	else
		return true;

} 

int main(){

	int n,k;

	cin >>n >>k;

	if(k>=n*n){
		cout <<"NO" <<endl;
		return 0;
	}

	if(calculate(n,k)){
		cout <<"YES" <<endl;
		printMat(n,k);
	}else{
		cout <<"NO" <<endl;
	}

	return 0;
}