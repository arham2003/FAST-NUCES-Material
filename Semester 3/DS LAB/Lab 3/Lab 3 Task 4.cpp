// TASK 4 22K-4080
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

    void insertNodeAfter(int key, int newValue) {
        node* newNode = new node(newValue);
        node* current = head;

		int keyAppears = 0;
        while (current != nullptr) {
            if (current->data == key) {
                newNode->next = current->next;
                current->next = newNode;
                return;
            }
            current = current->next;
        }

        cout << "Key not found in the list!!" << endl;
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

    cout << "Original Linked List: " << endl;
    myList.displayList();
	cout << endl;
	
	int presentNode, newData;
	cout << "Enter the node after which you want to place the new node:" << endl;
	cin >> presentNode;
	cout << "Enter the data of new node:" << endl;
	cin >> newData;
    myList.insertNodeAfter(presentNode, newData);

    cout << "Updated Linked List: "<< endl;
    myList.displayList();

    return 0;
}
