#include <iostream>
#include <cstdlib>

using namespace std;


struct ListNode {
      int val;
      ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

typedef struct ListNode * Node;

Node getnode(int val){
	Node temp;

	temp = (Node)malloc(sizeof(struct ListNode));
	
	if(temp!=NULL){
		temp->val=val;
		temp->next=NULL;
		return temp;
	}

	return NULL;
}

 ListNode* deleteDuplicates(ListNode* head) {

 	Node cur,prev,temp;
 	if(head==NULL)
 		return NULL;

 	if(head->next==NULL)
 		return head;

 	prev=head;
 	cur=head->next;
 	while(cur!=NULL){
 		if(prev->val!=cur->val){
 			prev->next=cur;
 			prev=cur;
 			cur=cur->next;
 		}else{
 			temp=cur;
 			//cout <<cur->val <<" deleted" <<endl;
 			cur=cur->next;
 			free(temp);
 		}
 	}
 	prev->next=NULL;

 	return head;
        
}

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

	Node cur1,cur2,head,cur,temp;   

	if(l1==NULL)
		return l2;
	if(l2==NULL)
		return l1;


	cur1=l1;
	cur2=l2;


	if(cur1->val<=cur2->val){
		head=getnode(cur1->val);
		cur1=cur1->next;
		
	}else{
		head=getnode(cur2->val);
		cur2=cur2->next;
		
	}

	cur=head;
	cur->next=NULL;

	while(cur1!=NULL && cur2!=NULL){

		if(cur1->val <= cur2->val){
			
			temp=getnode(cur1->val); 
			cur->next=temp;
			cur=cur->next;
			cur1=cur1->next;

		}else{
			
			temp=getnode(cur2->val); 
			cur->next=temp;
			cur=cur->next;
			cur2=cur2->next;
		}

	}
	
	while(cur2!=NULL){
		cur->next=cur2;
		cur2=cur2->next;
		cur=cur->next;
	}

	while(cur1!=NULL){
		cur->next=cur1;
		cur1=cur1->next;
		cur=cur->next;
	}

	cur->next=NULL;



	return head;
}

int main(){

	Node head,temp,cur;

	temp=getnode(1);
	head=temp;
	cur=head;
	temp=getnode(2);
	cur->next=temp;
	cur=cur->next;
	temp=getnode(12);
	cur->next=temp;
	cur=cur->next;
	temp=getnode(13);
	cur->next=temp;
	cur=cur->next;


//	head=deleteDuplicates(head);
	cout <<"before:" <<endl;
	head=mergeTwoLists(head,head);

	cur=head;
	cout <<"after:" <<endl;

	while(cur!=NULL){
		cout <<cur->val <<" ";
		cur=cur->next;
	}
	cout <<endl;
	cout <<"finish:" <<endl;



	return 0;
}