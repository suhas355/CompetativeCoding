#include <iostream>
#include <stdlib.h>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
  };

  typedef ListNode * Node;

  Node getNode(int val){
  	Node temp;
  	temp=(Node)malloc(sizeof(ListNode));
  	temp->val=val;
  	return temp;
  }

ListNode* removeElements(ListNode* head, int val) {

  	if(head==NULL){
  		return NULL;
  	}

  	if(head->next==NULL){
  		if(head->val==val)
  			return NULL;
  		else
  			return head;
  	}

  	Node cur,prev,adj;

  	cur=head;
  	while(cur!=NULL && cur->val==val )
  		cur=cur->next;

  	if(cur==NULL)
  		return NULL;

  	prev=cur;
  	head=cur;
  	cur=cur->next;

  	while(cur!=NULL){
  		if(cur->val==val){
  			prev->next=cur->next;
  			adj=cur;
  			cur=cur->next;
  			free(adj);
  		}else{
  			prev=cur;
  			cur=cur->next;
  		}
  	}

  	return head;
  
}


  int main(){

  	Node head,temp,cur;

  	head=getNode(1);
  	cur=head;

  	for(int i=1;i<10;i++){
  		if(i%3==0){
  			temp=getNode(1);
  		}else{
  			temp=getNode(1);
  		}
  		cur->next=temp;
  		cur=cur->next;
  	}

  	cur=head;
  	while(cur!=NULL){
  		cout <<cur->val <<" ";
  		cur=cur->next;
  	}
  	cout <<endl;

  	cur = removeElements(head,1);

  	cout <<"Post removal\n";

  	while(cur!=NULL){
  		cout <<cur->val <<" ";
  		cur=cur->next;
  	}
  	cout <<endl;

  	return 0;
  }