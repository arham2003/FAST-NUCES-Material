// TASK 5 22K-4080
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

class LinkedList {
public:
    node* head;

    LinkedList() {
        head = nullptr;
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
		node* todelete = head;
		head=head->next;
	
		delete todelete;
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

    void displayList() {
        node* current = head;
        while (current != nullptr) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    LinkedList myList;

    int values[] = {4, 1, 6, 7, 2, 10};
    int n = sizeof(values) / sizeof(values[0]);
    node* currentNode = nullptr;

    for (int i = 0; i < n; i++) {
        node* newNode = new node(values[i]);
        if (currentNode == nullptr) {
            myList.head = newNode;
            currentNode = newNode;
        } else {
            currentNode->next = newNode;
            currentNode = newNode;
        }
    }
	node* head = myList.head;
    cout << "Original Linked List: " << endl;
    myList.displayList();
	cout << endl;
	
	
	int presentNode;
	cout << "Enter the node to delete:" << endl;
	cin >> presentNode;
	cout << "Updated Linked List: " << endl;
	myList.deletion(head, presentNode);
	myList.displayList();
	
	
	cout << "Updated Linked List(deleted at last): " << endl;
	myList.deleteAtLast(head);
	myList.displayList();
	cout << endl;
	
	
	
	
	return 0;
}
