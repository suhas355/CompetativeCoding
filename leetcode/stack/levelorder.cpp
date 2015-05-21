/*
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree {3,9,20,#,#,15,7},

    3
   / \
  9  20
    /  \
   15   7

return its zigzag level order traversal as:

[
  [3],
  [20,9],
  [15,7]
]

confused what "{1,#,2,3}"

**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 *
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
    }
};

*/

#include <iostream>
#include <queue>
#include <vector>
#include <cstdlib>


using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

typedef struct TreeNode  * Node;

Node getNode(int value){
	Node temp;
	temp=(Node) malloc(sizeof(struct TreeNode));
	if(temp!=NULL){
		temp->val=value;
		temp->left=NULL;
		temp->right=NULL;
		return temp;
	}
	return NULL;

}

vector<int> reverseVector(vector<int> inp){
	vector<int> result;
	vector<int>::iterator it;
	if(inp.size()==0)
		return vector<int>();

	for(it=inp.end()-1;it!=inp.begin();it--){
		result.push_back(*it);
	}
	
		result.push_back(*it);

		return result;
}

vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
	vector<vector<int> > result;
	vector<int> tempvec;
	bool isleft=true;
	if(root==NULL)
		return vector<vector<int> >();
	if(root->left==NULL && root->right==NULL){
		tempvec.push_back(root->val);
		result.push_back(tempvec);
		return result;
	}

	queue<Node> myqueue;
	Node aux,hash;
	hash=getNode(-99999);

	myqueue.push(root);
	myqueue.push(hash);

	while(!myqueue.empty()){
		aux=myqueue.front();
		myqueue.pop();
		if(aux->val==hash->val){
			if(!isleft){
				tempvec=reverseVector(tempvec);
				isleft=true;
			}else{
				isleft=false;
			}
			
			result.push_back(tempvec);
			tempvec.clear();
			if(!myqueue.empty())
				myqueue.push(hash);
		}else{
			tempvec.push_back(aux->val);
			if(aux->left!=NULL)
				myqueue.push(aux->left);
			if(aux->right!=NULL)
				myqueue.push(aux->right);
		}

	}

	return result;
        
}


int main(){
	Node root,temp;
	root=getNode(1);
	root->left=getNode(9);
	root->right=getNode(20);
	root->right->left=getNode(15);
	root->right->right=getNode(7);

	vector<vector<int> > result = zigzagLevelOrder(root);

	vector<vector<int> >::iterator level;
	vector<int>::iterator it;

	for(level=result.begin();level!=result.end();level++){
		for(it=(*level).begin();it!=(*level).end();it++){
			cout <<*it <<" ";
		}
		cout <<endl;

	}


	return 0;
}

