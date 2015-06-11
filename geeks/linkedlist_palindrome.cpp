#include <iostream>
#include <cstdlib>
using namespace std;


struct node {
      int val;
      node *next;
     
};

typedef struct node  * Node;

Node getNode(int value){
	Node temp;
	temp=(Node) malloc(sizeof(struct node));
	if(temp!=NULL){
		temp->val=value;
		temp->next=NULL;
		return temp;
	}
	return NULL;

}


bool isPalinUtil(Node * left,Node right){
	if(right==NULL)
		return true;

	bool isp = isPalinUtil(left,right->next);

	if(!isp)
		return isp;

	bool ispl = (right->val== (*left)->val);

	*left=(*left)->next;

	return ispl;
}


bool isPalin(Node head){
	return isPalinUtil(&head,head);
}


int main(){

	Node head,cur,temp;

	cur=getNode(1);

	head=cur;

	temp=getNode(1);
	cur->next=temp;
	cur=cur->next;

	temp=getNode(3);
	cur->next=temp;
	cur=cur->next;

	temp=getNode(2);
	cur->next=temp;
	cur=cur->next;

	temp=getNode(1);
	cur->next=temp;
	cur=cur->next;


	if(isPalin(head)){
		cout <<"a palindrome" <<endl;

	}else{
		cout <<"not a palindrome" <<endl;
	}


	return 0;
}
