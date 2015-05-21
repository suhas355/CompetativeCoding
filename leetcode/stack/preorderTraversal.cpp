
#include <iostream>
#include <cstdlib>
#include <vector>
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

vector<int> result;

void preorder(TreeNode* root){
	if(root==NULL)
		return;

	if(root->left==NULL && root->right==NULL){
 		result.push_back(root->val);
 		return;
 	}

 	result.push_back(root->val);

 	preorder(root->left);
 	preorder(root->right);

}

 vector<int> preorderTraversal(TreeNode* root) {

 	preorder(root);

 	if(root==NULL){
		return vector<int>();
 	}

 	return result;
        
}

int main(){


	return 0;
}