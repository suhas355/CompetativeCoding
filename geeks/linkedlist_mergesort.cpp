#include <iostream>
#include <cstdlib>

using namespace std;

typedef struct node * Node;

struct node{
	int val;
	Node next;
};

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

Node getmiddle(Node root){
	Node first,sec;
	first=root;
	sec=root;
	/*cout <<"middle:" <<endl;
	Node cur=root;
	while(cur!=NULL){
		cout <<cur->val <<" ";
		cur=cur->next;
	}

	cout <<endl;*/

	if(first->next->next==NULL){
		sec=first->next;
		first->next=NULL;
		return sec;
	}


	while(sec!=NULL && sec->next!=NULL){
		//cout <<endl;
		//cout <<"first: " <<first->val <<endl;
		//cout <<"sec: " <<sec->val <<endl;
		first=first->next;
		sec=sec->next->next;
	}

	Node sec1;
	sec1=first;
	first=first->next;
	sec1->next=NULL;
	
	return first;
}

Node merge(Node a,Node b){
	if(a==NULL){
		return b;
	}

	if(b==NULL){
		return a;
	}

	Node root;

	if(a->val<b->val){
		root=a;
		a=a->next;
		root->next=NULL;
	}else{
		root=b;
		b=b->next;
		root->next=NULL;
	}

	Node head=root;
	while(a!=NULL && b!=NULL){
		if(a->val<b->val){
			root->next=a;
			root=root->next;
			a=a->next;
			root->next=NULL;
		}else{
			root->next=b;
			root=root->next;
			b=b->next;
			root->next=NULL;
		}
	}

	if(a==NULL){
		root->next=b;
	}

	if(b==NULL){
		root->next=a;
	}

	return head;


}


void mergesort(Node *root){
	Node head= *root;
	//cout <<"heh: " <<(*root)->val <<endl;
	if(head==NULL || head->next==NULL){
		return;
	}

	Node first,sec;
	first=head;
	//cout <<"before middle:" <<endl;
	sec=getmiddle(head);
	//cout <<"after middle:"<<sec->val <<endl;
	
	mergesort(&first);
	mergesort(&sec);

	*root=merge(first,sec);
}






int main(){

	Node head=NULL;

	head=push(head,1);
	head=push(head,2);
	head=push(head,3);

	head=push(head,9);
	head=push(head,8);
	head=push(head,7);

	head=push(head,11);
	head=push(head,2);
	head=push(head,31);

	
	
	mergesort(&head);
	
	Node cur=head;
	while(cur!=NULL){
		cout <<cur->val <<" ";
		cur=cur->next;
	}

	cout <<endl;

	return 0;
}
