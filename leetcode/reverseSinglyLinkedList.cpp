
#include <iostream>
#include <stdlib.h>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
  };
typedef ListNode* Node;

Node getNode(int value){
	Node temp = (Node)malloc(sizeof(struct ListNode));
	temp->val=value;
	return temp;
}

Node reverseList(ListNode* head) {
        if(head==NULL)
            return NULL;
        if(head->next==NULL)
            return head;
            
        
        Node prev=NULL;
        Node cur=head;
        Node adj=head->next;
       
        while(cur->next!=NULL){
        	//cout <<"cur:" <<cur->val <<endl;
            cur->next=prev;
            prev=cur;
            cur=adj;
            adj=adj->next;
            
        }
       
        cur->next=prev;
        
        return cur;
        
}

int main(){
	Node head,temp,head1,cur;
	temp = getNode(0);

	head=temp;
	temp=getNode(1);
	head->next=temp;
	cur=temp;
	temp=getNode(2);
	cur->next=temp;
	cur=temp;
	head1=head;
	
	head1=reverseList(head);
	
	while(head1!=NULL){
		cout <<head1->val <<" ";
		head1=head1->next;

	}
	cout <<endl;

	return 0;
}
