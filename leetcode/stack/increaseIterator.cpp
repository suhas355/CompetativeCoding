#include <iostream>
#include <stack>
#include <cstdlib>
#include <vector>
#include <limits.h>

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


Node cur;
stack<Node> mystack;
vector<int> result;
vector<int>::iterator it;


void  BSTIterator(TreeNode *root) {
 	if(root==NULL){
		return;
 	}

 	bool done = false;

 	Node temp=root;
 	while(!done){

 		if(temp!=NULL){
 			//cout <<"push: " <<temp->val <<endl;;
 			mystack.push(temp);
 			temp=temp->left;
 		}else{
 			if(!mystack.empty()){
 				temp=mystack.top();
 				mystack.pop();
 				//cout <<"pop: " <<temp->val <<endl;;
 				result.push_back(temp->val);
 				temp=temp->right;
 			}else{
 				done=true;
 			}
 		}
		
 	}

 	it=result.begin();

 	        
}


 /** @return whether we have a next smallest number */
    bool hasNext() {
    	if(it!=result.end()){
    		return true;
    	}

    	return false;
        
    }

    /** @return the next smallest number */
    int next() {

    	int val=INT_MAX;

    	if(it!=result.end()){
    		val=*it;
    		it++;

    	}

    	return val;
        
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


	BSTIterator(root);

	while (hasNext()) 
		cout << next();

	return 0;
}

