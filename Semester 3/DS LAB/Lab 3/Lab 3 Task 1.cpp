// TASK 1 - 22k-4080
#include <iostream>
using namespace std;

class node{
	public:
		int data,key;
		node* next;
		
		node(){
			key=0;
			data=0;
			next=NULL;
		}
		
		node(int k, int val){
			key=k;
			data=val;
			next=nullptr;
		}
};

class SinglyLinkedList
{
public:
    node* head;

    SinglyLinkedList(){
    	head = NULL;
    }

    SinglyLinkedList(node* n){
    	head = n;
    }
    
    
};



int main(){
    node* node1 = new node(1, 42);
    node* node2 = new node(2, 53);
    SinglyLinkedList list(node1);

    node1->next = node2;

    cout << "Node 1: Key=" << list.head->key << ", Data=" << list.head->data;
    cout << endl;
    cout << "Node 2: Key=" << list.head->next->key << ", Data=" << list.head->next->data;
    cout << endl;

    delete node1;
    delete node2;
    
    return 0;
}

