#include <iostream>
using namespace std;

class Node {
	public:
		int data;
		Node* right;
		Node* left;
		
	Node(int val){
		data = val;
		this->left = NULL;
		this->right = NULL;
	} 
};

class BinarySearchTree{
	public:
	Node* root;
	
	BinarySearchTree(){
		root = NULL;
	}
	
	Node* insert(Node* root, int value){
		if(root == NULL){
			return new Node(value);
		}
		
		if(value < root->data){
			root->left = insert(root->left,value);
		}
		else if(value > root->data){
			root->right = insert(root->right,value);
		}
		
		return root;
	}
	
	void inOrderTraversal(Node* root){
		if(root == NULL){
			return;
		}
		
		inOrderTraversal(root->left);
		cout << root->data << " ";
		inOrderTraversal(root->right);
	}
	
	void insert(int value){
		root = insert(root,value);
	}
	
	int height(Node* node){
		if(node == NULL){
			return 0;
		}
		
		int left = height(node->left);
		int right = height(node->right);
		
		int ans = max(left,right) + 1;
		return ans;
	}
	// first val: diameter
	// sec val: height
	
		
};

pair<int,int> diameterCalc(Node* root){
		if(root == NULL){
			pair<int,int> p = make_pair(0,0);
			return p;
		}
		
		pair<int,int> left = diameterCalc(root->left);
		pair<int,int> right = diameterCalc(root->right);
		
		int opt1 = left.first;
		int opt2 = right.first;
		int opt3 = left.second + right.second + 1;
		
		pair<int,int> ans;
		ans.first = max(opt1 , max(opt2,opt3)); //diameter formula
		ans.second = max(left.second,right.second) + 1; // same formula as in height function
		return ans;
	}

bool isIdentical(Node* r1, Node* r2){
	if(r1 == NULL && r2 == NULL){
		return true;
	}
	if(r1 == NULL && r2!=NULL){
		return false;
	}
	if(r1 != NULL && r2==NULL){
		return true;
	}
	
	bool left = isIdentical(r1->left,r2->left);
	bool right = isIdentical(r1->right,r2->right);
	
	bool value = r1->data == r2->data;
	
	if(left && right && value){
		return true;
	}
	else{
		return false;
	}
}

int main(){
	BinarySearchTree bst;
	BinarySearchTree bst2;
	bst.insert(5);
	bst.insert(10);
	bst.insert(11);
	bst.insert(15);
	bst.insert(16);
	bst.insert(19);
	
	bst2.insert(4);
	bst2.insert(8);
	bst2.insert(26);
	bst2.insert(15);
	bst2.insert(7);
	bst2.insert(12);
	
	cout<< "In Order Traversal: "<< endl;
	bst.inOrderTraversal(bst.root);
    cout<<endl;
    
    cout<< "In Order Traversal 2: "<< endl;
	bst2.inOrderTraversal(bst2.root);
    cout<<endl;
    
	cout<< "Height of Tree: " << endl;
	int hTree = bst.height(bst.root);
	cout<<hTree <<endl;
	
	cout<< "Diameter of Tree:" << endl;
	cout << diameterCalc(bst.root).first <<endl;
	
	cout<< "are trees identical? "<<endl;
	cout<<isIdentical(bst.root,bst2.root);
	
	return 0;
}
