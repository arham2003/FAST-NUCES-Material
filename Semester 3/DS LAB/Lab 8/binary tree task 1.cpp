#include <iostream>
#include <queue>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;

    node(int d) {
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
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

int main() {
    int numArr[] = {1, 2, 3, 4, 5};
    int n = sizeof(numArr) / sizeof(numArr[0]);

    node* root = TreeFromArray(numArr, 0, n - 1);

    cout << "In-order traversal of the binary tree: ";
    inOrderTraversal(root);
    cout << endl;

    return 0;
}

