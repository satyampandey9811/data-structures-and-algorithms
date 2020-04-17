// binary search tree
// 16. bst class

#include<iostream>
using namespace std;

template <typename T>
class BinaryTreeNode {
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;
    
    BinaryTreeNode(T data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

class BST {
    
	BinaryTreeNode<int> *root;
    
    BinaryTreeNode<int> *input(int data, BinaryTreeNode<int> *node){
        if(node == NULL){
            BinaryTreeNode<int> *newnode = new BinaryTreeNode<int>(data);
            return newnode;
        }
        if(data < node -> data)
            node -> left = input(data, node -> left);
        else
            node -> right = input(data, node -> right);
        return node;
    }
    
    BinaryTreeNode<int> *deleteData(int data, BinaryTreeNode<int> *node){
        if(node == NULL)
            return NULL;
            
        if(data == node -> data){
			if(node -> left and node -> right){
                BinaryTreeNode<int> *minnode = node -> right;
                while(minnode -> left != NULL)
                    minnode = minnode -> left;
                node -> data = minnode -> data;
                node -> right = deleteData(minnode -> data, node -> right);                
            }   
            else if(node -> left){
                BinaryTreeNode<int> *ans = node -> left;
                node -> left = NULL;
                delete node;
                return ans;
            }
            else if(node -> right){
                BinaryTreeNode<int> *ans = node -> right;
                node -> right = NULL;
                delete node;
                return ans;
            }
            else{
                delete node;
                return NULL;
            }
        }
        else if(data < node -> data)
            node -> left = deleteData(data, node -> left);
        else
            node -> right = deleteData(data, node -> right);  
        return node;
    }
        
    bool hasData(int data, BinaryTreeNode<int> *node){
        if(node == NULL)
            return false;
        if(data == node -> data)
            return true;
        if(data < node -> data)
            return hasData(data, node -> left);
        else 
            return hasData(data, node -> right);
    } 
        
    void printTree(BinaryTreeNode<int> *node){
        if(node == NULL)
            return;
        cout << node -> data << ':';
        if(node -> left){
            cout << "L:" << node -> left -> data << ',';            
        }
        if(node -> right){            
            cout << "R:" << node -> right -> data;
        }
        cout << endl;
        printTree(node -> left);
        printTree(node -> right);
    }
    
public:    
    
    BST(){
        root = NULL;
    }       
        
    ~BST(){
        delete root;
    }
 
    void insert(int data){
        root = input(data, root);
    }
    
    void deleteData(int data){
        root = deleteData(data, root);
    }
        
	bool hasData(int data){
        return hasData(data, root);
    }
        
    void printTree(){
        printTree(root);
    }                   
};

int main(){
    BST *tree = new BST();
    int choice, input;
    while(true){
        cin>>choice;
        switch(choice){
            case 1:
                cin >> input;
                tree->insert(input);
                break;
            case 2:
                cin >> input;
                tree->deleteData(input);
                break;
            case 3:
                cin >> input;
                if(tree->hasData(input)) {
                    cout << "true" << endl;
                }
                else {
                    cout << "false" << endl;
                }
                break;
            default:
                tree->printTree();
                return 0;
                break;
        }
    }
}