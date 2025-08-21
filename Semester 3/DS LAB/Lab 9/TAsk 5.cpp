#include <iostream>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    int height;
};

int height(Node* node) {
    if (node == NULL)
        return 0;
    return node->height;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

Node* newNode(int key) {
    Node* node = new Node();
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

Node* AVLrightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return x;
}

Node* AVLleftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    return y;
}

int getBalance(Node* node) {
    if (node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}

Node* minValueNode(Node* node) {
    Node* current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}

Node* insert(Node* root, int key) {
    if (root == NULL)
        return newNode(key);
    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);
    else
        return root;
    root->height = 1 + max(height(root->left), height(root->right));
    int balance = getBalance(root);
    if (balance > 1 && key < root->left->key)
        return AVLrightRotate(root);
    if (balance < -1 && key > root->right->key)
        return AVLleftRotate(root);
    if (balance > 1 && key > root->left->key) {
        root->left = AVLleftRotate(root->left);
        return AVLrightRotate(root);
    }
    if (balance < -1 && key < root->right->key) {
        root->right = AVLrightRotate(root->right);
        return AVLleftRotate(root);
    }
    return root;
}

Node* deleteNode(Node* root, int key) {
    if (root == NULL)
        return root;
    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        if ((root->left == NULL) || (root->right == NULL)) {
            Node* temp = root->left ? root->left : root->right;
            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else
                *root = *temp;
            delete temp;
        } else {
            Node* temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }
    if (root == NULL)
        return root;
    root->height = 1 + max(height(root->left), height(root->right));
    int balance = getBalance(root);
    if (balance > 1 && getBalance(root->left) >= 0)
        return AVLrightRotate(root);
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = AVLleftRotate(root->left);
        return AVLrightRotate(root);
    }
    if (balance < -1 && getBalance(root->right) <= 0)
        return AVLleftRotate(root);
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = AVLrightRotate(root->right);
        return AVLleftRotate(root);
    }
    return root;
}

Node* kthSmallest(Node* root, int& k) {
    if (root == NULL)
        return NULL;
    Node* left = kthSmallest(root->left, k);
    if (left != NULL)
        return left;
    k--;
    if (k == 0)
        return root;
    return kthSmallest(root->right, k);
}

Node* kthLargest(Node* root, int& k) {
    if (root == NULL)
        return NULL;
    Node* right = kthLargest(root->right, k);
    if (right != NULL)
        return right;
    k--;
    if (k == 0)
        return root;
    return kthLargest(root->left, k);
}

void printHeight(Node* root) {
    if (root == NULL)
        return;
    cout << "Root Height: " << root->height << ", Left Height: " << height(root->left) << ", Right Height: " << height(root->right) << endl;
}

int main() {
    Node* root = NULL;

    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 3);
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 6);
    root = insert(root, 7);

    printHeight(root);

    int kSmallest = 3;
    Node* kthSmallestNode = kthSmallest(root, kSmallest);
    if (kthSmallestNode != NULL)
        cout << "Kth Smallest Value (" << kSmallest << "): " << kthSmallestNode->key << endl;

    int kLargest = 2;
    Node* kthLargestNode = kthLargest(root, kLargest);
    if (kthLargestNode != NULL)
        cout << "Kth Largest Value (" << kLargest << "): " << kthLargestNode->key << endl;

    root = deleteNode(root, 4);
    printHeight(root);

    return 0;
}

