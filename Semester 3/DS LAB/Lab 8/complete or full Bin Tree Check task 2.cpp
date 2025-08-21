#include <iostream>
#include <queue>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;

    node(int d) {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node* TreeFromArray(int arr[], int start, int end) {
    if (start > end) {
        return NULL;
    }

    int mid = (start + end) / 2;
    node* root = new node(arr[mid]);

    root->left = TreeFromArray(arr, start, mid - 1);
    root->right = TreeFromArray(arr, mid + 1, end);

    return root;
}

void inOrderTraversal(node* root) {
    if (root == NULL) {
        return;
    }

    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}


node* insertValue(node* root, int value) {
    if (root == NULL) {
        return new node(value);
    }

    queue<node*> q;
    q.push(root);

    while (!q.empty()) {
        node* current = q.front();
        q.pop();

        if (current->left == NULL) {
            current->left = new node(value);
            return root;
        } else {
            q.push(current->left);
        }

        if (current->right == NULL) {
            current->right = new node(value);
            return root;
        } else {
            q.push(current->right);
        }
    }

    return root;
}

bool isCompleteBinaryTree(node* root) {
    if (root == NULL) {
        return true;
    }

    queue<node*> q;
    q.push(root);

    bool nonFullNode = false; 

    while (!q.empty()) {
        node* current = q.front();
        q.pop();

        if (current == NULL) {
            nonFullNode = true;
        } else {
            if (nonFullNode) {
                return false;
            }
            q.push(current->left);
            q.push(current->right);
        }
    }

    return true;
}

bool isFullBinaryTree(node* root) {
    if (root == NULL) {
        return true;
    }

    if (root->left == NULL && root->right == NULL) {
        return true;
    }

    if (root->left != NULL && root->right != NULL) {
        return isFullBinaryTree(root->left) && isFullBinaryTree(root->right);
    }

    return false;
}

node* CompleteAndFullBT(node* root) {
    if (root == NULL) {
        return root;
    }

    if (!isFullBinaryTree(root)) {
        // If the tree is not full, adding dummy node to make it full
        root = insertValue(root, -1);
    }

    return root;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    node* root = TreeFromArray(arr, 0, n - 1);

    root = insertValue(root, 6);
    root = insertValue(root, 7);
    root = insertValue(root, 8);

    cout << "In-order traversal of the binary tree: ";
    inOrderTraversal(root);
    cout << endl;

    if (isCompleteBinaryTree(root)) {
        cout << "The binary tree is complete." << endl;
    } else {
        cout << "The binary tree is not complete. Making it complete." << endl;
        root = CompleteAndFullBT(root);
        
        cout << "In-order traversal of the modified binary tree: ";
    	inOrderTraversal(root);
    	cout << endl;

    }

    
    if (isFullBinaryTree(root)) {
        cout << "The binary tree is full." << endl;
    } else {
        cout << "The binary tree is not full. Making it Full." << endl;
        root = CompleteAndFullBT(root);
        
        cout << "In-order traversal of the modified binary tree: ";
    	inOrderTraversal(root);
    	cout << endl;
    }
    
    if (isFullBinaryTree(root)) {
        cout << "The binary tree is now full." << endl;
    }

    return 0;
}

