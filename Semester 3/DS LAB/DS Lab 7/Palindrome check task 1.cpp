#include <iostream>
#include <cstring>

using namespace std;

class Stack {
private:
    char stckArr[100]; // Array to store the stack
    int top; // Index of the top element

public:
    Stack() {
        top = -1; // Initialize top to -1 (empty stack)
    }

    void push(char value) {
        if (top < 99) {
            stckArr[++top] = value; // Push the value onto the stack
        }
    }

    char pop() {
        if (top >= 0) {
            return stckArr[top--]; // Pop the top element from the stack
        }
        return '\0'; // Return null character if stack is empty
    }

    bool isEmpty() {
        return top == -1; 
    }
};

int main() {
    Stack st1;
    const char* givInput = "BORROWROB";
    cout<<givInput<<endl;
    int inpLength = strlen(givInput);
    
    
    for (int i = 0; i < inpLength; i++) {
        st1.push(givInput[i]);
    }

    
    bool palindCheck = true;
    for (int i = 0; i < inpLength; i++) {
        if (st1.pop() != givInput[i]) {
            palindCheck = false;
            break;
        }
    }

    if (palindCheck) {
        cout << "Yay!! The string is a palindrome." << endl;
    } else {
        cout << "Aww! The string is not a palindrome." << endl;
    }

    return 0;
}

