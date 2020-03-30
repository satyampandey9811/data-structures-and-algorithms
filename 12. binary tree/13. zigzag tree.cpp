// binary tree
// 13. zigzag tree

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

void zigZagOrder(BinaryTreeNode<int> *root) {
    if(root == NULL)
        return;
    queue<BinaryTreeNode<int>*> q;
    vector<int> temp;
    bool flag = true;
    q.push(root);
    q.push(NULL);
    
    while(q.size() != 0){
        BinaryTreeNode<int>* front = q.front();
        q.pop();
        if(front == NULL){
            if(q.empty()){
                if(!flag)
                    reverse(temp.begin(), temp.end());
                for(int i = 0; i < temp.size(); i++)
                    cout << temp[i] << ' ';
                break;
            }
            else{
                if(!flag){
                    flag = true;
                    reverse(temp.begin(), temp.end());
                }
                else
                    flag = false;
                for(int i = 0; i < temp.size(); i++)
                    cout << temp[i] << ' ';
                cout << endl;
                temp = {};
                q.push(NULL);                
                continue;
            }
        }
        temp.push_back(front -> data);
        if(front -> left)
            q.push(front -> left);
        if(front -> right)
            q.push(front -> right);    
    }
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    zigZagOrder(root);
}