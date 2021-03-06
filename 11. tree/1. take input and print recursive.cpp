// tree
// take input and print recursive

#include<bits/stdc++.h>
using namespace std;

template <typename T>
class TreeNode{
public:
	T data;
	vector<TreeNode*> children;

	TreeNode(T data){
		this -> data = data;		
};

TreeNode<int>* takeInput(){
	int rootData;
	cout << "enter data : ";
	cin >> rootData;
	TreeNode<int>* root = new TreeNode<int>(rootData);

	int n;
	cout << "enter the number of children of " << rootData;
	cin >> n;
	for(int i = 0; i < n; i++){
		TreeNode<int>* child = takeInput();
		root -> children.push_back(child);
	}
	return root;
}

void printTree(TreeNode<int>* root){
	if(root == NULL)
		return;
	cout << root -> data << " : ";
	
	for(int i = 0; i < root -> children.size(); i++){
		cout << root -> children[i] -> data << ",";
	}
	cout << endl;
	for(int i = 0; i < root -> children.size(); i++){
		printTree(root -> children[i]);
	}
}

int main(){
	TreeNode* root = takeInput();
	printTree(root);
}