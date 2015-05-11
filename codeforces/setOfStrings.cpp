/*
A. Set of Strings
time limit per test
1 second
memory limit per test
256 megabytes
input
standard input
output
standard output

You are given a string q. A sequence of k strings s1, s2, ..., sk is called beautiful, if the concatenation of these strings is string q (formally, s1 + s2 + ... + sk = q) and the first characters of these strings are distinct.

Find any beautiful sequence of strings or determine that the beautiful sequence doesn't exist.
Input

The first line contains a positive integer k (1 ≤ k ≤ 26) — the number of strings that should be in a beautiful sequence.

The second line contains string q, consisting of lowercase Latin letters. The length of the string is within range from 1 to 100, inclusive.
Output

If such sequence doesn't exist, then print in a single line "NO" (without the quotes). Otherwise, print in the first line "YES" (without the quotes) and in the next k lines print the beautiful sequence of strings s1, s2, ..., sk.

If there are multiple possible answers, print any of them.
Sample test(s)
Input

1
abca

Output

YES
abca

Input

2
aaacas

Output

YES
aaa
cas

Input

4
abc

Output

NO

*/
#include <iostream>
#include <string.h>


using namespace std;

bool alpha[26];
int count=0,point[30];
void checkBeautiful(char *inp,int k){
	
	for(int i=0;i<26;i++){
		alpha[i]=false;

	}
	for(int i=0;i<30;i++)
		point[i]=-1;

	alpha[inp[0]-'a']=true;
	count++;
	point[0]=0;

	int i=1,j=1;
	while(inp[i]!=0){
		if(alpha[inp[i]-'a']==false){
			alpha[inp[i]-'a']=true;
			point[j++]=i;
			//cout <<inp[i] <<" " <<i <<endl;
			count++;
		}
		i++;
	}
	if(count<k){
		cout <<"NO" <<endl;
		return;
	}else{
		cout <<"YES" <<endl;
		int j=1;
		for(int i=0;inp[i]!=0;){
			cout <<inp[i++];
			if(point[j]==i && j<k){
				j++;
				cout <<endl;
			}
			
		}
	}
	cout <<endl;



}

int main(){
	int k;
	char inp[150];
	cin >>k >>inp;

	checkBeautiful(inp,k);

	return 0;
}

