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


Node push(Node head,int val){
	if(head==NULL){
		head=getNode(val);
		return head;
	}
	Node cur=head;

	while(cur->next!=NULL)
		cur=cur->next;

	cur->next=getNode(val);

	return head;
}




Node merge(Node head1,Node head2){

	Node head,temp;

	if(head1==NULL && head2==NULL){
		return NULL;
	}

	if(head1==NULL)
		return head2;

	if(head2==NULL)
		return head1;

	if(head1->val<=head2->val){
		head=head1;
		head1=head1->next;
		
	}else{
		head=head2;
		head2=head2->next;
	}

	head->next==NULL;
	head->next=merge(head1,head2);

	return head;

}


int main(){
	Node head1=NULL,head2=NULL;

	head1=push(head1,1);
	head1=push(head1,1);
	head1=push(head1,3);
	head1=push(head1,3);
	head1=push(head1,5);
	head1=push(head1,6);
	head1=push(head1,7);
	head1=push(head1,8);



	head2=push(head2,2);
	head2=push(head2,4);
	head2=push(head2,6);
	head2=push(head2,8);
	head2=push(head2,10);
	head2=push(head2,12);


	Node res= merge(head1,head2);

	while(res!=NULL){
		cout <<res->val <<endl;
		res=res->next;
	}


	return 0;
}