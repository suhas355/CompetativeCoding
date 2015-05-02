/*
Given two strings s and t, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.

For example,
Given "egg", "add", return true.

Given "foo", "bar", return false.

Given "paper", "title", return true.

Note:
You may assume both s and t have the same length.
*/


#include <iostream>
#include <map>


using namespace std;



bool isIsomorphic(string s, string t) {

	map<char,char> isomap;
	map<char,char>::iterator it;

	for(int i=0;i<s.size();i++){
		it = isomap.find(s[i]);
		if(it==isomap.end()){ //s[i] is not there in map
			isomap[s[i]]=t[i];
		}else{ // present hence check it is the same char value
			if(it->second != t[i])
				return false;
		}
	}

	map<char,char> isomap1;
	map<char,char>::iterator it1;

	for(int i=0;i<t.size();i++){
		it1 = isomap1.find(t[i]);
		if(it1==isomap1.end()){ //s[i] is not there in map
			isomap1[t[i]]=s[i];
		}else{ // present hence check it is the same char value
			if(it1->second != s[i])
				return false;
		}
	}



	return true;        
}

int main(){

	string s="agg";
	string t="add";
	if(isIsomorphic(s,t))
		cout <<"yes" <<endl;
	else
		cout <<"no" <<endl;
	return 0;
}