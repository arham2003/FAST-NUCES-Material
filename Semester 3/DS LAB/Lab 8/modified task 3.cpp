#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value){
	data = value;
	this->right = NULL;
	this->left = NULL;
	}
};

class BinarySearchTree {
private:
    Node* root;

    Node* insert(Node* root, int value) {
        if (root == NULL) {
            root = new Node(value);
        }
        else if (value < root->data) {
            root->left = insert(root->left, value);
        }
        else if (value > root->data) {
            root->right = insert(root->right, value);
        }
        return root;
    }

public:
    BinarySearchTree() : root(NULL) {}

    void insertAndLocate(int value) {
        root = insert(root, value);

        int depth = findDepth(root, value);
        if (depth == 0) {
            cout << value << " is the root at level " << depth << endl;
        }
        else if (value < root->data) {
            cout << value << " is the left child at level " << depth << endl;
        }
        else {
            cout << value << " is the right child at level " << depth << endl;
        }
    }

    int findDepth(Node* root, int x) {
        if (root == NULL) {
            return -1;
        }

        int dist = -1;

        if (root->data == x || (dist = findDepth(root->left, x)) >= 0 || (dist = findDepth(root->right, x)) >= 0) {
            return dist + 1;
        }

        return dist;
    }

    bool search(int value) {
        Node* current = root;
        while (current) {
            if (value == current->data) {
                int depth = findDepth(root, value);
                if (depth == 0) {
                    cout << value << " is the root at level " << depth << endl;
                }
                else if (value < root->data) {
                    cout << value << " is the left child at level " << depth << endl;
                }
                else {
                    cout << value << " is the right child at level " << depth << endl;
                }
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
        bst.insertAndLocate(value);
    }

    cout << "Enter a value to search for in the tree: ";
    cin >> valueToSearch;

    if (!bst.search(valueToSearch)) {
        cout << valueToSearch << " does not exist in the tree. Inserting and locating..." << endl;
        bst.insertAndLocate(valueToSearch);
    }

    return 0;
}

