// TASK 7 22k-4080
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

void append(ListNode*& head, ListNode*& tail, int val) {
    ListNode* newNode = new ListNode(val);
    if (!head) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}


void printList(ListNode* head) {
    ListNode* current = head;
    while (current) {
        cout << current->val << "->";
        current = current->next;
    }
    cout<< "NULL" << endl;
}


ListNode* modifyLinkedList(ListNode* head) {
	
    if (!head || !head->next) {
        return head;
    }

    ListNode* evenHead = nullptr; 
    ListNode* evenTail = nullptr; 
    ListNode* oddHead = nullptr;  
    ListNode* oddTail = nullptr;  

    ListNode* current = head;

    while (current) {
        if (current->val % 2 == 0) {
            append(evenHead, evenTail, current->val);
        } else {
            append(oddHead, oddTail, current->val);
        }
        current = current->next;
    }

    if (!evenHead) {
        return head;
    } else {
        evenTail->next = oddHead;
        return evenHead;
    }
}

int main() {
	ListNode* head = new ListNode(1);
    int values[] = {4, 1, 6, 7, 2, 10, 8, 11, 17, 22};
    int n = sizeof(values) / sizeof(values[0]);
    ListNode* currentNode = nullptr;

    for (int i = 0; i < n; i++) {
        ListNode* newNode = new ListNode(values[i]);
        if (currentNode == nullptr) {
            head = newNode;
            currentNode = newNode;
        } else {
            currentNode->next = newNode;
            currentNode = newNode;
        }
    }

    cout << "Original Linked List: " << endl;
    printList(head);

    ListNode* modifiedHead = modifyLinkedList(head);

    cout << "Updated Linked List: " << endl;
    printList(modifiedHead);


    while (modifiedHead) {
        ListNode* temp = modifiedHead;
        modifiedHead = modifiedHead->next;
        delete temp;
    }

    return 0;
}

