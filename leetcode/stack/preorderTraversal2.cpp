
#include <iostream>
#include <cstdlib>
#include <vector>
#include <stack>
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

vector<int> preorderTraversal(TreeNode* root) {

	stack<Node> mystack;
 	
 	if(root==NULL){
		return vector<int>();
 	}

 	mystack.push(root);

 	Node temp;
 	while(!mystack.empty()){
 		temp=mystack.top();
 		mystack.pop();

 		result.push_back(temp->val);

 		if(temp->right!=NULL)
 			mystack.push(temp->right);

 		if(temp->left!=NULL)
 			mystack.push(temp->left);
 	}

 	return result;
        
}

int main(){

	Node root,temp,cur;

	root = getNode(1);
	cur=root;

	temp=getNode(2);
	cur->left=temp;

	temp=getNode(3);
	cur->right=temp;

	temp=getNode(6);
	cur->right->left=temp;

	cur=cur->left;

	temp=getNode(4);
	cur->left=temp;

	temp=getNode(5);
	cur->right=temp;

	cur=cur->left;

	temp=getNode(7);
	cur->left=temp;

	temp=getNode(8);
	cur->right=temp;


	preorderTraversal(root);

	vector<int>::iterator it;

	for(it=result.begin();it!=result.end();it++){
		cout <<*it <<" " <<endl;
	}






	return 0;
}