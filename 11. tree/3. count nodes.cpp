// tree
// count nodes

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

TreeNode<int>* takeInputLevelWise(){
	int rootData;
	cout << "enter root data : ";
	cin >> rootData;
	TreeNode<int>* root = new TreeNode<int>(rootData);
	
	queue<TreeNode<int>*> pendingNodes;
	pendingNodes.push(root);
	
	while(pendingNodes.size() != 0){
		TreeNode<int>* front = pendingNodes.front();
		pendingNodes.pop();
		cout << "enter the num of children of " << front -> data << endl;
		int n;
		cin >> n;
		
		for(int i = 0; i < n; i++){
			int childData;
			cout << "enter " << i << "th child of " << front -> data << endl;
			cin >> childData;
			TreeNode<int>* child = new TreeNode<int>(childData);
			pendingNodes.push(child);
			front -> children.push_back(child);
		}
	}
	return root;
}

void printTree(TreeNode<int>* root){
	queue<TreeNode<int>*> pendingNodes;
	pendingNodes.push(root);
	
	while(pendingNodes.size() != 0){
		TreeNode<int>* front = pendingNodes.front();
		pendingNodes.pop();
		cout << front -> data << ":";
	
		for(int i = 0; i < front -> children.size(); i++){
			cout << front -> children[i] -> data;
            if(i < front -> children.size() - 1)
                cout << ',';
			pendingNodes.push(front -> children[i]);
		}
		cout << endl;
	}
}

int countNodes(TreeNode<int>* root){
	int ans = 1;
	for(int i = 0; i < root -> children.size(); i++){
		ans += countNodes(root -> children[i]);
	}
	return ans;
}

int main(){
	TreeNode<int>* root = takeInputLevelWise();
	int nodes = countNodes(root);
	cout << nodes << endl;
}