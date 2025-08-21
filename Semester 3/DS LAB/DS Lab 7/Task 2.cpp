#include <iostream>
using namespace std;


const int capacty = 10;

class Queue {
    private:
        int itemsinQueue[capacty]; 
        int front; 
        int rear; 
    public:
        Queue(); 
        bool isFull(); 
        bool isEmpty(); 
        void enqueue(int item); 
        int dequeue(); 
        void display(); 
};


Queue::Queue() {
    front = -1;
    rear = -1;
}


bool Queue::isFull() {
    if (rear == capacty - 1) {
        return true;
    }
    else {
        return false;
    }
}


bool Queue::isEmpty() {
    if (front == -1 || front > rear) {
        return true;
    }
    else {
        return false;
    }
}


void Queue::enqueue(int item) {
    if (isFull()) {
        cout << "Queue is full, cannot add more items." << endl;
    }
    else {
        if (front == -1) {
            front = 0; 
        }
        rear++; 
        itemsinQueue[rear] = item; 
    }
}


int Queue::dequeue() {
    int item;
    if (isEmpty()) {
        cout << "Queue is empty, cannot remove further." << endl;
        return -1;
    }
    else {
        item = itemsinQueue[front]; 
        front++; 
        return item; 
    }
}


void Queue::display() {
    if (isEmpty()) {
        cout << "Queue is empty, kuch nhi display krne ko." << endl;
    }
    else {
        cout << "The queue elements are: " << endl;
        for (int i = front; i <= rear; i++) { 
            cout << itemsinQueue[i] << " "; 
        }
        cout << endl;
    }
}


int main() {
    Queue qu1; 
    int customerIDs[] = {13, 7, 4, 1, 6, 8, 10};

    for (int i = 0; i < 7; i++) {
        qu1.enqueue(customerIDs[i]);
    }

    qu1.display();

    // dequeuing each customer ID one by one as they are checked out by the cashier
    while (!qu1.isEmpty()) {
        int id = qu1.dequeue(); // Dequeue and storing the customer ID
        cout << "Checking out customer ID: " << id << endl; 
    }

    qu1.display();

    return 0;
}

