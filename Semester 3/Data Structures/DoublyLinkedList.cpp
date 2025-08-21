#include <iostream>
using namespace std;

class Node{
	public:
		Node* prev;
		Node* next;
		int data;
		
		Node(int d){
			this -> data = d;
			this -> prev = NULL;
			this -> next = NULL;
		}
		
		~Node(){
			int val = this->data;
			if (next != NULL){
				delete next;
				next = NULL;
			}
			cout<<"Memory free for node with data: "<<val<<endl;
		}
};
void deleteNode(int position, Node* &head, Node* &tail){
	if (position == 1){
		Node* temp = head;
		temp->next->prev = NULL;
		head = temp->next;
		tail = head;
		temp->next = NULL;
		
		delete temp;
	}
	else{
		Node* curr = head;
		Node* prev = NULL;
		int cnt = 1;
		while(cnt<position){
			prev = curr;
			curr = curr -> next;
			cnt++;
		}
		if (curr->next == NULL){
			Node* temp = tail;
			tail = temp->prev;
			temp->prev = NULL;
			temp->next = NULL;
			
			delete temp;
			
		}
		curr -> prev = NULL;
		prev -> next = curr -> next;
		curr -> next = NULL;
		
		delete curr;
	}
	
	
}

void insertAthead(Node* &head, Node* &tail, int d){
	if(head == NULL){
		Node* temp = new Node(d);
		head = temp;
		tail = temp;
	}
	else{
	
	Node* temp = new Node(d);
	temp->next = head;
	head->prev = temp;
	head = temp;
	}
}

void insertAtTail(Node* &tail,Node* &head, int d){
	
	if(tail == NULL){
		Node* temp = new Node(d);
		tail = temp;
		head = temp;
	}
	else{
	
	Node* temp = new Node(d);
	tail->next = temp;
	temp->prev = tail;
	tail = temp ;
	}
}

void print(Node* head){
	Node* temp = head;
	cout<<"NULL" << "<- ";
	
	while(temp != NULL){
		cout<< temp -> data<< " -> ";
		temp = temp->next;
	}
	cout<<"NULL"<<endl;
}

void insertAtPosition(Node* &tail,Node* &head,int position, int d){
	
	// starting position
	if(position == 1){
		insertAthead(head,tail,d);
		return;
	}
	
	Node* temp = head;
	int cnt = 1;
	
	while(cnt < position-1) {
        temp = temp->next;
        cnt++;
    }
	
	//inserting at Last Position
    if(temp -> next == NULL) {
        insertAtTail(tail,head,d);
        return ;
    }

    //creating a node for d
    Node* nodeToInsert = new Node(d);

    nodeToInsert -> next = temp -> next;

    temp -> next -> prev = nodeToInsert;
    temp -> next = nodeToInsert;
    nodeToInsert->prev = temp; 
}

int getLength(Node* head){
	int len = 0;
	Node* temp =head;
	
	while(temp != NULL){
		len++;
		temp = temp->next;
	}
	return len;
}

int main(){
	
	Node* node1 = new Node(10);
	Node* head = node1;
	Node* tail = node1;
	
	insertAthead(head,tail,11);
	print(head);
	
	insertAtTail(tail,head, 90);
	insertAtPosition(tail,head,3,45);
	print(head);
	
	deleteNode(4, head, tail);
	print(head);
	cout<<"head: "<<head->data << endl;
	cout<<"tail: "<<tail->data << endl;
	
	cout<<"Total Nodes: "<<getLength(head)<<endl;
	return 0;
}
