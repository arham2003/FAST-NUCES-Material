// TASK 3 22k-4080

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

void insertAtHead(node* &head, int val){
	node* n = new node(val);
	n->next=head;
	head=n;
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
	insertAtHead(head,4);
	insertAtHead(head,6);
	display(head);
	insertAtHead(head,5);
	display(head);
	
	return 0;
}
