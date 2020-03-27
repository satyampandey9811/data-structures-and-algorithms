// tree
// replace depth as node value

#include <bits/stdc++.h>
using namespace std;

template <typename T>
class TreeNode {
public:
    T data;
    vector<TreeNode<T>*> children;
    
    TreeNode(T data) {
        this->data = data;
    }
    
    ~TreeNode() {
        for (int i = 0; i < children.size(); i++) {
            delete children[i];
        }
    }
    
};

TreeNode<int>* takeInputLevelWise() {
    int rootData;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);
    
    queue<TreeNode<int>*> pendingNodes;
    
    pendingNodes.push(root);
    while (pendingNodes.size() != 0) {
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++) {
            int childData;
            cin >> childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}

void printLevelATNewLine(TreeNode<int> *root) {
    queue<TreeNode<int>*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()) {
        TreeNode<int> *first = q.front();
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
        for(int i = 0; i < first -> children.size(); i++) {
            q.push(first -> children[i]);
        }
    }
}

void replaceWithDepthValue(TreeNode<int>* root, int depth){
    root -> data = depth;
    for(int i = 0; i < root -> children.size(); i++){
        replaceWithDepthValue(root -> children[i], depth + 1);
    }
}

void replaceWithDepthValue(TreeNode<int> *root){    
    if(root == NULL)
        return;
    replaceWithDepthValue(root, 0); 
}

int main() {
    TreeNode<int>* root = takeInputLevelWise();
    replaceWithDepthValue(root);
    printLevelATNewLine(root);
}

/*	done using level wise traversal and making queue of pair of 
pointer to treenodes and depth value

void replaceWithDepthValue(TreeNode<int> *root){ 
    queue<pair<TreeNode<int>*, int>> q;
    q.push({root, 0});
    int c = 0;
    root -> data = c;
    
    while(q.size() != 0){
        TreeNode<int>* front = q.front().first;
        c = q.front().second;
        q.pop();
        for(int i = 0; i < front -> children.size(); i++){
            q.push({front -> children[i], c + 1});
            front -> children[i] -> data = c + 1;
        }
        c++;
    }    
}
*/