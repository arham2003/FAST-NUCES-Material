// TASK 2 - 22k-4080
#include <iostream>
using namespace std;

class node{
	public:
		int data;
		node* next;
		
		node(int val){
			data=val;
			next=NULL;
		}
};

void insertAtTail(node* &head, int val){
	node* n = new node(val);
	
	if(head==NULL){
		head=n;
		return;
	}
	
	node* temp=head;
	while(temp->next != NULL){
		temp=temp->next;
	}
	temp->next=n;
}

void display(node* head){
	node* temp=head;
	
	while(temp!=NULL){
		cout<<temp->data<<"->";
		temp=temp->next;
	}
	cout<<"NULL"<<endl;
}

int main(){
	
	node* head = NULL;
	insertAtTail(head,1);	
	insertAtTail(head,2);	
	display(head);
	cout<< "After Adding 2 more Nodes:"<<endl;
	insertAtTail(head,3);
	insertAtTail(head,4);
	display(head);
	
	return 0;
	
}




//
//void insertAtTail(node* newNode){
//	
//	if(head==NULL){
//		head=newNode;
//		return;
//	}
//	else{
//	
//	node* temp=head;
//	while(temp->next != NULL){
//		temp=temp->next;
//	}
//		temp->next=newNode;
//	
//	}
// } 
