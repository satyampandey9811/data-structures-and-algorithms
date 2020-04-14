// Binary search tree
// finding minimum and maximum element
// using iteration

#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	node* left;
	node* right;
};

node* getnewnode(int x){
	node* temp=new node();
	temp->data=x;
	temp->left=temp->right=NULL;
	return temp;
}

node* insert(node* root, int x){
	if(root==NULL){
		root=getnewnode(x);
		return root;
	}
	else if(x<=root->data){
		root->left=insert(root->left,x);
	}
	else
		root->right=insert(root->right,x);
	return root;
}

int findMin(node* root){
    if(root==NULL){
        cout<<"Error : Tree is empty";
        return -1;
    }
    while(root->left!=NULL)
		root=root->left;
	return root->data;
}

int findMax(node* root){
    if(root==NULL){
        cout<<"Error : Tree is empty";
        return -1;
    }
    while(root->right!=NULL)
		root=root->right;
	return root->data;
}

int main(){
	node* root=NULL;
	root=insert(root,15);
	root=insert(root,8);
	root=insert(root,10);
	root=insert(root,12);
	root=insert(root,17);
	root=insert(root,25);
	root=insert(root,20);
	cout<<"minimum element is : "<<findMin(root)<<endl;
	cout<<"maximum element is : "<<findMax(root);
	return 0;
}