// binary search tree
// 12. check bst-2

#include <bits/stdc++.h>
using namespace std;

template <typename T>
class BinaryTreeNode {
    public : 
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
    ~BinaryTreeNode() {
    	if(left) 
       		delete left;
    	if(right) 
       		delete right;
    }
};

BinaryTreeNode<int>* takeInput() {
    int rootData;
    //cout << "Enter root data : ";
    cin >> rootData;
    if(rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while(!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
	q.pop();
        int leftChild, rightChild;
        //cout << "Enter left child of " << currentNode -> data << " : ";
        cin >> leftChild;
        if(leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode -> left =leftNode;
            q.push(leftNode);
        }
        //cout << "Enter right child of " << currentNode -> data << " : ";
        cin >> rightChild;
        if(rightChild != -1) {
            BinaryTreeNode<int>* rightNode = new BinaryTreeNode<int>(rightChild);
            currentNode -> right =rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

class bst{
public:    
    bool isbst;
    int minval;
    int maxval;
};

bst helper(BinaryTreeNode<int> *root){
    bst output;
    if(root == NULL){
        output.isbst = true;
        output.minval = INT_MAX;
        output.maxval = INT_MIN;
        return output;
    }
    bst left = helper(root -> left);
    bst right = helper(root -> right);
    
    int minimum = min(root -> data, min(left.minval, right.minval));
    int maximum = max(root -> data, max(left.maxval, right.maxval));
	bool isbstval = (root -> data > left.maxval) and (root -> data <= right.minval) and left.isbst and right.isbst;
    
    output.isbst = isbstval;
    output.minval = minimum;
    output.maxval = maximum;
    return output;
}

bool isBST(BinaryTreeNode<int> *root){
    bst answer = helper(root);
	return answer.isbst;
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    if(isBST(root)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
    delete root;
}