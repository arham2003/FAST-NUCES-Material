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

Node* AvlRightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

Node* AvlLeftRotate(Node* x) {
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
        return AvlRightRotate(root);

    if (balance < -1 && key > root->right->key)
        return AvlLeftRotate(root);

    if (balance > 1 && key > root->left->key) {
        root->left = AvlLeftRotate(root->left);
        return AvlRightRotate(root);
    }
    
    if (balance < -1 && key < root->right->key) {
        root->right = AvlRightRotate(root->right);
        return AvlLeftRotate(root);
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
        return AvlRightRotate(root);

    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = AvlLeftRotate(root->left);
        return AvlRightRotate(root);
    }

    if (balance < -1 && getBalance(root->right) <= 0)
        return AvlLeftRotate(root);

    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = AvlRightRotate(root->right);
        return AvlLeftRotate(root);
    }

    return root;
}

void preOrder(Node* root) {
    if (root != NULL) {
        cout << root->key << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        cout << root->key << " ";
        inOrder(root->right);
    }
}

void postOrder(Node* root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->key << " ";
    }
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

    cout << "Pre-order traversal before deletion: ";
    preOrder(root);
    cout << endl;

    cout << "In-order traversal before deletion: ";
    inOrder(root);
    cout << endl;

    cout << "Post-order traversal before deletion: ";
    postOrder(root);
    cout << endl;

    root = deleteNode(root, 4);
    cout<< "4 deleted!"<<endl;
	cout<<endl;
    cout << "Pre-order traversal after deletion: ";
    preOrder(root);
    cout << endl;

    cout << "In-order traversal after deletion: ";
    inOrder(root);
    cout << endl;

    cout << "Post-order traversal after deletion: ";
    postOrder(root);
    cout << endl;

    return 0;
}

