// TASK 6 22k-4080
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val){
    	data = val;
    	next = NULL;
	}
};

class SinglyLinkedList {
private:
    Node* head;

public:
    SinglyLinkedList(){
    	head = nullptr;
	}

    void addNode(int value) {
        Node* newNode = new Node(value);

        if (head == nullptr) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    bool updateNode(int position, int newValue) {
        if (position < 0) {
            cout << "Invalid position." << endl;
            return false;
        }

        Node* current = head;
        int currentPosition = 0;

        while (current != nullptr) {
            if (currentPosition == position) {
                current->data = newValue;
                return true;
            }

            current = current->next;
            currentPosition++;
        }

        cout << "Position " << position << " is out of bounds." << endl;
        return false;
    }

    void printList() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    SinglyLinkedList myList;

    myList.addNode(10);
    myList.addNode(20);
    myList.addNode(30);
    myList.addNode(40);

    cout << "Original Linked List: " << endl;
    myList.printList();
    cout << endl;

    if (myList.updateNode(2, 35)) {
        cout << "Node at position 3 updated successfully." << endl;
        cout << "Updated Linked List: " << endl;
        myList.printList();
    } else {
        cout << "Failed to update node." << endl;
    }

    return 0;
}

