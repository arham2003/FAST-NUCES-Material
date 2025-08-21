#include <iostream>
using namespace std;
struct Node {
    int key;
    Node* next;
    Node(int k){
    	key = k;
    	next = nullptr;
	}
};

void insertAtEnd(Node*& head, int key) {
    Node* newNode = new Node(key);
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

Node* reverseList(Node* head) {
    Node* prev = nullptr;
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

void extractReverseAppend(Node*& head) {
    if (head == nullptr || head->next == nullptr) {
        return; 
    }

    
    Node* originalList = head;
    Node* extractedList = nullptr;


    Node* current = head;
    Node* prev = nullptr;
    while (current != nullptr) {
        if (current->next != nullptr) {
           
            Node* extractedNode = current->next;
            current->next = current->next->next;

           
            extractedNode->next = nullptr;
            if (extractedList == nullptr) {
                extractedList = extractedNode;
            } else {
                Node* temp = extractedList;
                while (temp->next != nullptr) {
                    temp = temp->next;
                }
                temp->next = extractedNode;
            }
        }
        prev = current;
        current = current->next;
    }

    extractedList = reverseList(extractedList);
    
    if (prev != nullptr) {
        prev->next = extractedList;
    } else {
        head = extractedList;
    }
}

void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->key << "->";
        current = current->next;
    }
    cout <<"NULL"<<endl;
}

int main() {
    Node* head = nullptr;
    insertAtEnd(head, 10);
    insertAtEnd(head, 4);
    insertAtEnd(head, 9);
    insertAtEnd(head, 1);
    insertAtEnd(head, 3);
    insertAtEnd(head, 5);
    insertAtEnd(head, 9);
    insertAtEnd(head, 4);

    cout << "Original Linked List: ";
    printList(head);

    extractReverseAppend(head);

    cout << "Modified Linked List: ";
    printList(head);

    return 0;
}

