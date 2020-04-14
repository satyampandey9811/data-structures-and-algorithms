// Binary search tree
// finding height of binary tree
// time comp. is O(n)

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

int findheight(node* root){
	if(root==NULL)
		return -1;
	int a=findheight(root->left);
	int b=findheight(root->right);
	return 1+max(a,b);
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
	root=insert(root,5);
	root=insert(root,13);
	cout<<"height of binary tree is : "<<findheight(root);
	return 0;
}