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

/*************************************************************************/

Node getmid(Node low){
	Node cur1,cur2;

	cur1=low;
	cur2=low;

	while(cur2!=NULL && cur2->next!=NULL){
		cur1=cur1->next;
		cur2=cur2->next->next;
	}
	//cout <<"cur1:" <<cur1->val <<endl;
	return cur1;
}

Node merge(Node low,Node low2){
	Node p,q,r,temp,del,head;
	
	p=low;
	q=low2;
	head=getNode(-1);
	r=head;

	//cout <<"merge:" <<low->val <<" " <<low2->val <<endl;
	while(p!=NULL && q!=NULL){
		if(p->val < q->val){
			r->next=p;
			p=p->next;
			//r->next=temp;
			r=r->next;
			r->next=NULL;
		}else{
			r->next=q;
			q=q->next;
			r=r->next;
			r->next=NULL;
		}
	}

	while(p!=NULL){
		//temp=getNode(p->val);
		r->next=p;
		p=p->next;
		//r->next=temp;
		r=r->next;
		r->next=NULL;
		//cout <<temp->val <<" ";
		//del=p;
		//free(del);
	}

	while(q!=NULL){
		
		r->next=q;
		q=q->next;
		r=r->next;
		r->next=NULL;
		//cout <<temp->val <<" ";
		//del=q;
		
		//free(del);
	}
	//cout <<endl;
	head=head->next;
	//cout <<"head:" <<head->val <<endl;
	return head;
}

Node mergesort(Node low){
	Node mid,head,temp;
	if(low==NULL || low->next==NULL)
		return low;

	

	if((low!=NULL) && (low->next!=NULL)){
		mid=getmid(low);
		//cout <<"low:" <<low->val <<" high:" <<high->val <<endl;
		temp=mid->next;
		mid->next=NULL;
		low=mergesort(low);
		//cout <<"2" <<endl;
		temp=mergesort(temp);
		
		//cout <<"low:" <<low->val <<" high:" <<high->val <<endl;
		//cout <<mid->val <<"  mid" <<endl;
		head=merge(low,temp);
		//cout <<"head: " <<head->val <<endl;
	}

	
	return head;
}


ListNode* sortList(ListNode* head) {
	if(head==NULL)
		return NULL;

	if(head->next==NULL)
		return head;

	Node low,high;
	low=head;
	
	head=mergesort(low);
        
}


int main(){

	Node head1,cur1,temp;

	int a[200]={-84,142,41,-17,-71,170,186,183,-21,-76,76,10,29,81,112,-39,-6,-43,58,41,111,33,69,97,-38,82,-44,-7,99,135,42,150,149,-21,-30,164,153,92,180,-61,99,-81,147,109,34,98,14,178,105,5,43,46,40,-37,23,16,123,-53,34,192,-73,94,39,96,115,88,-31,-96,106,131,64,189,-91,-34,-56,-22,105,104,22,-31,-43,90,96,65,-85,184,85,90,118,152,-31,161,22,104,-85,160,120,-31,144,115,9999};

	head1=getNode(-84);
	cur1=getNode(142);
	head1->next=cur1;

	for(int i=2;i<5;i++){//a[i]<9999;i++){
	
	temp=getNode(a[i]);
	cur1->next=temp;
	cur1=cur1->next;
	}



	Node here=head1;
	
	cout <<"before" <<endl;
	while(here!=NULL){
		cout <<here->val <<" ";
		here=here->next;
	}
	cout <<endl;

	here=sortList(head1);

	cout <<endl;
	cout <<"----after----" <<endl;
	while(here!=NULL){
		cout <<here->val <<" ";
		here=here->next;
	}
	cout <<endl;



	
	return 0;
}