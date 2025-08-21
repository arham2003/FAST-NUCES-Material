#include <iostream>
#include <cstdlib>
using namespace std;
 
class Task {
public:
    int priority;
    int taskID;
};
 
class taskNode {
public:
    Task task;
    taskNode* left;
    taskNode* right;
 
    taskNode(Task task) {
        this->task = task;
        this->left = NULL;
        this->right = NULL;
    }
};
 
taskNode* insert(taskNode* root, Task task) {
    if (root == NULL) {
        taskNode* newNode = new taskNode(task);
        return newNode;
    }
 
    if(task.priority > root->task.priority) {
        root->left = insert(root->left, task);
    }
else{
        root->right = insert(root->right, task);
    }
    return root;
}
 
void deleteNodes(taskNode* root) {
    if (root == NULL){
        return;
    }
 
    deleteNodes(root->left);
    cout << "Deleting Task " << root->task.taskID << " with Priority " << root->task.priority << endl;
    deleteNodes(root->right);
    delete root;
}
 
void printTree(taskNode* root) {
    if (root == NULL) {
        return;
    }
 
//TO GET TO THE LEFT MOST NODE AS IT WILL HAVE THE GREATEST PRIORITY while Inserting
    printTree(root->left);
    cout << "Task " << root->task.taskID << " with Priority " << root->task.priority << endl;
    printTree(root->right);
}
 
int main() {
    int tasksAmnt;
    taskNode* root = NULL;
 
    cout << "Input tasks: ";
    cin >> tasksAmnt;
 
    for (int i = 0; i < tasksAmnt; i++) {
        Task task;
        cout << "Enter the ID for task " << i + 1 << ": ";
        cin >> task.taskID;
        task.priority = rand() % 10;
        root = insert(root, task);
    }
 
    cout << "The initial tree is:" << endl;
    printTree(root);
    cout<<endl;
 
    cout << "The tree is being deleted according to descending priority:" << endl;
    deleteNodes(root);
 
    return 0;
}

