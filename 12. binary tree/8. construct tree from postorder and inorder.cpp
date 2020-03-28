// binary tree
// construct tree from postorder and inorder

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

void printLevelATNewLine(BinaryTreeNode<int> *root) {
		queue<BinaryTreeNode<int>*> q;
		q.push(root);
		q.push(NULL);
		while(!q.empty()) {
			BinaryTreeNode<int> *first = q.front();
			q.pop();
			if(first == NULL) {
				if(q.empty()) {
					break;
				}
				cout << endl;
				q.push(NULL);
				continue;
			}
			cout << first -> data << " ";
			if(first -> left != NULL) {
				q.push(first -> left);
			}
			if(first -> right != NULL) {
				q.push(first -> right);
			}
		}
}

BinaryTreeNode<int>* helper(int *post, int *in, int inS, int inE, int postS, int postE){
    if(inS > inE)
        return NULL;
    int rootData = post[postE];
    
    int rootIndex = -1;
    for(int i = inS; i <= inE; i++){
        if(in[i] == rootData){
            rootIndex = i;
            break;
        }
    }
    int lInS = inS;
    int lInE = rootIndex - 1;    
    int lPostS = postS;
    int lPostE = lPostS + lInE - lInS;
    int rPostS = lPostE + 1;
    int rPostE = postE - 1;
    int rInS = rootIndex + 1;  
    int rInE = inE;
    
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);        
    
    root -> left = helper(post, in, lInS, lInE, lPostS, lPostE);
    root -> right = helper(post, in, rInS, rInE, rPostS, rPostE);
    return root;
}

BinaryTreeNode<int>* getTreeFromPostorderAndInorder(int *post,int size,int *in,int insize){
    
    BinaryTreeNode<int>* root = helper(post, in, 0, size - 1, 0, size - 1);
    return root;
}

int main() {
    int size;
    cin >> size;
    int *post = new int[size];
    int *in = new int[size];
    for(int i=0;i<size;i++)
		cin>>post[i];
    for(int i=0;i<size;i++)
		cin>>in[i];
    BinaryTreeNode<int>* root = getTreeFromPostorderAndInorder(post, size, in, size);
    printLevelATNewLine(root);
}