#include <iostream>
using namespace std;

class Node{
	public:
		Node* next;
		int data;

		Node(int d){
			this->data = d;
			this->next = NULL;
		}
		
		

};

void insertNode(Node* &tail, int element, int d){
	if (tail == NULL){
		Node* temp = new Node(d);
		tail = temp;
		temp->next= temp;
	}
	else{
		//Non-Empty List
		
		Node* curr = tail;
		
		while(curr->data != element){
			curr = curr->next;
		}
		
		Node* temp = new Node(d);
		temp->next = curr->next;
		curr->next = temp;
	}
}

int main(){
	Node* tail = NULL
}
