/*
 Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed. 

*/

#include <iostream>
#include <cstdlib>

using namespace std;


struct ListNode {
      int val;
      ListNode *next;
 ListNode(int x) : val(x), next(NULL) {}
};

typedef struct ListNode * Node;

Node getNode(int val){
	Node temp=(Node)malloc(sizeof(struct ListNode));
	temp->val=val;
	return temp;
}

ListNode* swapPairs(ListNode* head) {

	if(head==NULL)
		return NULL;

	if(head->next==NULL)
		return head;

	//cout <<"before: " <<head->val <<" " <<head->next->val <<endl;
	Node temp=head;

	head=head->next;
	temp->next=head->next;
	head->next=temp;

	//cout <<"after: " <<head->val <<" " <<head->next->val <<endl;

	if(temp->next==NULL)
		return head;

	Node prev,cur1,cur2;

	prev=head->next;

	cur1=prev->next;

	if(cur1->next==NULL)
		return head;
	cur2=cur1->next;

	while(cur1!=NULL && cur2!=NULL && cur2->next!=NULL && cur1->next!=NULL){
		//cout <<"before: " <<cur1->val <<" " <<cur2->val <<endl;
		prev->next=cur2;
		cur1->next=cur2->next;
		cur2->next=cur1;
		//cout <<"after: " <<cur1->val <<" " <<cur2->val <<endl;
		prev=cur1;
		cur1=prev->next;
		//cout <<"123" <<endl;
		cur2=cur1->next;
		//cout <<"234" <<endl;

	}

	if(cur2!=NULL){
		prev->next=cur2;
		cur1->next=cur2->next;
		cur2->next=cur1;

	}

	return head;
        
    
}
int main(){

	Node head1,cur1,temp;

	head1=getNode(1);
	cur1=getNode(2);
	head1->next=cur1;
	
	temp=getNode(3);
	cur1->next=temp;
	cur1=cur1->next;


	temp=getNode(4);
	cur1->next=temp;
	cur1=cur1->next;

	/*temp=getNode(5);
	cur1->next=temp;
	cur1=cur1->next;*/


	Node here=head1;
	

	while(here!=NULL){
		cout <<here->val <<" ";
		here=here->next;
	}
	cout <<endl;

	here=swapPairs(head1);


	while(here!=NULL){
		cout <<here->val <<" ";
		here=here->next;
	}
	cout <<endl;



	
	return 0;
}