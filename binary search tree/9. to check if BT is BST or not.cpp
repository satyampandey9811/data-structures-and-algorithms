// Binary Search Tree 
// to check if BT is BST or not

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

bool isbinarysearchtree(node *root, int minvalue, int maxvalue){
	if(root==NULL) 
		return true;
	if(root->data>minvalue and root->data<=maxvalue and 
	isbinarysearchtree(root->left,minvalue,root->data) and
	isbinarysearchtree(root->right,root->data,maxvalue))
		return true;
	else
		return false;
}

int main(){
	node* root=NULL;
	root=insert(root,7);
	root=insert(root,4);
	root=insert(root,9);
	root=insert(root,1);
	root=insert(root,6);
	cout<<isbinarysearchtree(root,INT_MIN,INT_MAX);
	return 0;
}