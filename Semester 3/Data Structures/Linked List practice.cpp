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

//inserting a node at the end of linked list

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

bool search(node* head, int key){
	node* temp = head;
	while(temp!=NULL){
		if(temp->data == key){
			return true;
		}
		temp=temp->next;
	}
	return false;
}

void deleteAtHead(node* &head){
	node* todelete = head;
	head=head->next;
	
	delete todelete;
}

node* reverseRecursive(node* &head){
    if (head==NULL || head->next==NULL){
        return head;
    }
    
    node* newhead=reverseRecursive(head->next);
    head->next->next=head;
    head->next=NULL;
    return newhead;
    
}

node* deleteAtLast(node* head){
	if (head == NULL)
        return NULL;
 
    if (head->next == NULL) {
        delete head;
        head= NULL;
    }
    node* temp = head;
    node* temp2 = head;
    
    while (temp->next != NULL){
    	temp2 = temp;
    	temp = temp->next;
	}
    temp2->next = NULL;
    delete temp;
    temp = NULL;
    
    return head;
}

void deletion(node* &head, int val){
	
	if(head == NULL){
		return;
	}
	
	if(head->next==NULL){
		deleteAtHead(head);
		return;
	}
	
	node* temp = head;
	while(temp->next->data != val){
		temp=temp->next;
	}
	node* todelete=temp->next;
	temp->next = temp->next->next;
	
	delete todelete;
	
}

node* reverse(node* &head){
	
	node* prevptr=NULL;
	node* currptr=head;
	node* nextptr;
	
	while(currptr!=NULL){
		nextptr=currptr->next;
		currptr->next=prevptr;
		
		prevptr=currptr;
		currptr=nextptr;
	}
	
	return prevptr;
}

int main(){
	
	node* head = NULL;
	insertAtTail(head,1);	
	insertAtTail(head,2);	
	insertAtTail(head,3);
	insertAtTail(head,4);
	display(head);
	//insertAtHead(head,4);
	//display(head);
	cout<<search(head,5)<<endl;
	
	//deletion(head, 3);
//	deleteAtHead(head);
//	display(head);

	node* newhead = reverse(head);
	display(newhead);
	
	deleteAtLast(newhead);
	display(newhead);

	return 0;
}
