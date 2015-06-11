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


int addition(Node head){
	//cout <<head-> val <<endl;

	if(head->next!=NULL){
		int carry = addition(head->next);
		if((head->val+carry)==10){
			head->val=0;
			return 1;

		}else{
			//cout <<head->val <<" " <<"here" <<endl;
			head->val+=carry;
			return 0;
		}
	}else{
		if(head->val==9){
			head->val=0;
			return 1;
		}else{
			head->val++;
			return 0;
		}
	}

}



Node addone(Node head){
	if(head==NULL){
		head=getNode(1);
		return head;
	}

	if(head->next==NULL){
		if(head->val!=9){
			head->val++;
			return head;
		}else{
			Node temp=getNode(1);
			temp->next=head;
			head->val=0;
			head=temp;
			return head;
		}
	}else{
		int carry=addition(head->next);
		//cout <<"carry: " <<carry <<endl;
		if((head->val+carry)!=10){
			head->val+=carry;
			return head;
		}else{
			Node temp=getNode(1);
			temp->next=head;
			head->val=0;
			head=temp;
			return head;
		}

		
	}

}





int main(){

	Node head;

	head=push(head,1);
	head=push(head,2);
	head=push(head,3);


	Node cur=addone(head);

	while(cur!=NULL){
		cout <<cur->val <<" ";
		cur=cur->next;
	}

	cout <<endl;

	return 0;
}