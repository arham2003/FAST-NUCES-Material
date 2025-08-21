#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
    	data = value;
    	this->left=NULL;
    	this->right=NULL;
	}
};

class BinarySearchTree {
public:
    Node* root;

    Node* insert(Node* root, int value, int& depth, bool& isRoot) {
        if (root == NULL) {
            root = new Node(value);
            depth = 0;
            isRoot = true;
            return root;
        }
        if (value < root->data) {
        	isRoot = false;
            root->left = insert(root->left, value, ++depth, isRoot);
        }
        else if (value > root->data) {
        	isRoot = false;
            root->right = insert(root->right, value, ++depth, isRoot);
        }
        return root;
        
    }

    BinarySearchTree() {
    	root = NULL;
	}
	int depth = 0;
    void insert(int value) {
        
        bool isRoot = false;
        root = insert(root, value, depth, isRoot);

        if (isRoot) {
            cout << value << " is the root at level " << depth << endl;
        }
        else if (value < root->data) {
            cout << value << " is the left child at level " << depth << endl;
        }
        else {
            cout << value << " is the right child at level " << depth << endl;
        }
    }

    bool search(int value) {
        Node* current = root;
        while (current) {
            if (value == current->data) {
                return true;
            }
            else if (value < current->data) {
                current = current->left;
            }
            else {
                current = current->right;
            }
        }
        return false;
    }
};

int main() {
    BinarySearchTree bst;
    int valueToSearch;

    cout << "Enter values to insert into the binary search tree (-1 to stop):" << endl;
    int value;
    while (true) {
        cin >> value;
        if (value == -1) {
            break;
        }
        bst.insert(value);
    }

    cout << "Enter a value to search for in the tree: ";
    cin >> valueToSearch;

    if (bst.search(valueToSearch)) {
        cout << valueToSearch << " exists in the tree." << endl;
    } else {
        cout << valueToSearch << " does not exist in the tree." << endl;
        bst.insert(valueToSearch);
        bst.search(valueToSearch);
    }

    return 0;
}

