//Task 8 22k-4080
#include <iostream>
#include <string>

using namespace std;

struct ListNode {
    string val;
    ListNode* next;
    ListNode(string x) : val(x), next(nullptr) {}
};

ListNode* reverseLinkedList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* current = head;
    ListNode* next = nullptr;
    
    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    
    return prev;
}


bool isPalindrome(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
        return true; 
    }
    
    int length = 0;
    ListNode* current = head;
    while (current != nullptr) {
        length++;
        current = current->next;
    }
    
    int halfLength = length / 2;
    ListNode* firstHalfEnd = head;
    for (int i = 0; i < halfLength - 1; i++) {
        firstHalfEnd = firstHalfEnd->next;
    }
    
    ListNode* secondHalfStart = firstHalfEnd->next;
    secondHalfStart = reverseLinkedList(secondHalfStart);
    

    ListNode* p1 = head;
    ListNode* p2 = secondHalfStart;
    bool isPalin = true;
    
    for (int i = 0; i < halfLength; i++) {
        if (p1->val != p2->val) {
            isPalin = false;
            break;
        }
        p1 = p1->next;
        p2 = p2->next;
    }
    
   
    secondHalfStart = reverseLinkedList(secondHalfStart);
    firstHalfEnd->next = secondHalfStart;
    
    return isPalin;
}

void printLinkedList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        cout << current->val << " -> ";
        current = current->next;
    }
    cout << "NULL" << endl;
}

int main() {
  
	ListNode* head = new ListNode("c");
    head->next = new ListNode("i");
    head->next->next = new ListNode("v");
    head->next->next->next = new ListNode("i");
    head->next->next->next->next = new ListNode("c");

    cout << "Original Linked List: " << endl;
    printLinkedList(head);

    bool isPalin = isPalindrome(head);

    if (isPalin) {
        cout << "The linked list is a palindrome." << endl;
    } else {
        cout << "The linked list is not a palindrome." << endl;
    }

    return 0;
}

