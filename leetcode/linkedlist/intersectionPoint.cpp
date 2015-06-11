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

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
	if(headA==NULL || headB==NULL)
		return NULL;
        
    if(headA==headB)
    	return headB;

    int len1=0,len2=0;
    
    Node cur=headA;
    while(cur!=NULL){
    	len1++;
    	cur=cur->next;
    }	 

    cur=headB;
    while(cur!=NULL){
    	len2++;
    	cur=cur->next;
    }

    int diff,pos=0;
    Node cur2;

    if(len1>len2){
    	diff=len1-len2;
    	cur=headA;
    	cur2=headB;
    }else{
    	diff=len2-len1;
    	cur=headB;
    	cur2=headA;
    }

    while(pos<diff){
    	cur=cur->next;
    	pos++;
    }

    if(cur==cur2){
    	return cur;
    }

    while(cur->next!=NULL){
    	if(cur->next==cur2->next)
    		return cur->next;
    	cur=cur->next;
    	cur2=cur2->next;
    }

    if(cur==cur2){
    	return cur;
    }

    return NULL;

}

int main(){

	Node head1,head2,cur1,cur2,temp;

	head1=getNode(1);
	cur1=getNode(2);
	head1->next=cur1;
	
	temp=getNode(3);
	cur1->next=temp;
	cur1=cur1->next;


	head2=getNode(9);
	cur2=getNode(8);
	head2->next=cur2;
	cur2->next=cur1;

	temp=getNode(4);
	cur1->next=temp;
	cur1=cur1->next;

	temp=getNode(5);
	cur1->next=temp;
	cur1=cur1->next;


	Node here=head1;
	

	while(here!=NULL){
		cout <<here->val <<" ";
		here=here->next;
	}
	cout <<endl;


	here=head2;

	while(here!=NULL){
		cout <<here->val <<" ";
		here=here->next;
	}
	cout <<endl;


	Node res=getIntersectionNode(head1,head2);

	cout <<res->val <<endl;
	

	return 0;
}


