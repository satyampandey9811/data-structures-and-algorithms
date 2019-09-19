// Binary search tree 
// PostOrder Traversal 
// time comp. is O(n)
// space comp. is : O(h) where h is the height of the tree
// height of the tree in worst case will be n-1
// worst case : O(n)
// best/average case : O(log n)

#include<iostream>
#include<queue>
using namespace std;

struct Node {
	char data;
	Node *left;
	Node *right;
};

// Function to print Nodes in a binary tree in Postorder
void PostOrder(Node *root) {
	if(root==NULL){
		return;
	}
	PostOrder(root->left);
	PostOrder(root->right);
	cout<<root->data<<' ';
}
// Function to Insert Node in a Binary Search Tree
Node* Insert(Node *root,char data) {
	if(root == NULL) {
		root = new Node();
		root->data = data;
		root->left = root->right = NULL;
	}
	else if(data <= root->data) root->left = Insert(root->left,data);
	else root->right = Insert(root->right,data);
	return root;
}

int main() {
	/*Code To Test the logic
	  Creating an example tree
	            M
			   / \
			  B   Q
			 / \   \
			A   C   Z
    */
	Node* root = NULL;
	root = Insert(root,'M'); root = Insert(root,'B');
	root = Insert(root,'Q'); root = Insert(root,'Z'); 
	root = Insert(root,'A'); root = Insert(root,'C');
	//Print Nodes in Post Order. 
	PostOrder(root);
}

