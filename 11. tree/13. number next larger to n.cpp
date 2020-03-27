// tree
// next larger

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

TreeNode<int>* nextLargerElement(TreeNode<int> *root, int n) {

    TreeNode<int>* ans;
    queue<TreeNode<int>*> q;
    q.push(root);
    bool flag = false;

    while(q.size() != 0){
        TreeNode<int>* front = q.front();
        if(!flag and n < front -> data){
            ans = front;
            flag = true;
        }
        if(flag and n < front -> data and front -> data < ans -> data)
            ans = front;
        q.pop();
        for(int i = 0; i < front -> children.size(); i++){
            q.push(front -> children[i]);
        }
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    TreeNode<int>* root = takeInputLevelWise();
    TreeNode<int>* ans = nextLargerElement(root, n);
    if(ans != NULL) {
        cout << ans -> data << endl;
    }
    else {
        cout << INT_MIN << endl;
    }
}