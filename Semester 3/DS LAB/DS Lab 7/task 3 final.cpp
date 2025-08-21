#include <iostream>
#include <string>
#include <stack>
#include <cctype>
using namespace std;

// Doubly linked list
struct Node {
    char data;
    Node* next;
    Node* prev;
    Node(char c) : data(c), next(nullptr), prev(nullptr) {}
};

class LinkedList {
private:
    Node* top;

public:
    LinkedList() : top(nullptr) {}

    void push(char c) {
        Node* newNode = new Node(c);
        if (top == nullptr) {
            top = newNode;
        } else {
            newNode->next = top;
            top->prev = newNode;
            top = newNode;
        }
    }

    char pop() {
        if (top == nullptr) {
            cerr << "Stack is empty!" << endl;
            return '\0'; 
        }
        char data = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return data;
    }

    char peek() {
        if (top == nullptr) {
            cerr << "Stack is empty!" << endl;
            return '\0'; 
        }
        return top->data;
    }

    bool isEmpty() {
        return top == nullptr;
    }
};

int evaluateExpression(const string& expression) {
    stack<int> values;
    stack<char> operators;
    size_t i = 0;

    for (char c : expression) {
        if (c == ' ') {
            continue;
        } else if (isdigit(c)) {
            int num = 0;
            while (isdigit(c)) {
                num = num * 10 + (c - '0');
                c = expression[++i];
            }
            values.push(num);
        } else if (c == '(') {
            operators.push(c);
        } else if (c == ')') {
            while (!operators.empty() && operators.top() != '(') {
                int b = values.top();
                values.pop();
                int a = values.top();
                values.pop();
                char op = operators.top();
                operators.pop();
                if (op == '+') {
                    values.push(a + b);
                } else if (op == '-') {
                    values.push(a - b);
                }
            }
            operators.pop(); // Remove the '('
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {
            while (!operators.empty() && operators.top() != '(' && ((c == '+' || c == '-') && (operators.top() == '*' || operators.top() == '/'))) {
                int b = values.top();
                values.pop();
                int a = values.top();
                values.pop();
                char op = operators.top();
                operators.pop();
                if (op == '+') {
                    values.push(a + b);
                } else if (op == '-') {
                    values.push(a - b);
                } else if (op == '*') {
                    values.push(a * b);
                } else if (op == '/') {
                    values.push(a / b);
                }
            }
            operators.push(c);
        }
    }

    while (!operators.empty()) {
        int b = values.top();
        values.pop();
        int a = values.top();
        values.pop();
        char op = operators.top();
        operators.pop();
        if (op == '+') {
            values.push(a + b);
        } else if (op == '-') {
            values.push(a - b);
        } else if (op == '*') {
            values.push(a * b);
        } else if (op == '/') {
            values.push(a / b);
        }
    }

    return values.top();
}

int main() {
    string expression = "x=12+13-5*(0.5+0.5)+1";

    LinkedList st1;
    string postfixExpression;

    for (char c : expression) {
        if (c == ' ') {
            continue;
        }

        if (c == '=') {
            // Push '=' onto the stack
            st1.push(c);
        } else if (c == 'x') {
            
            st1.push(c);
        } else {
            
            while (!st1.isEmpty() && (st1.peek() == '+' || st1.peek() == '-' || st1.peek() == '(') &&
                   (c == '*' || c == '/')) {
                st1.push(c);
                break;
            }
            st1.push(c);
        }

        postfixExpression += c;
    }

    
    
    cout << "Stack contents: ";
    while (!st1.isEmpty()) {
        cout << st1.pop();
    }
    cout << endl;

    

    return 0;
}

