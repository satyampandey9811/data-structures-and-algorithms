// stack
// reverse linked list using stack

#include<bits/stdc++.h>
#include<stack>
using namespace std;

struct Node{
	int data;
	Node* next;
};

Node* head;

void insert(int x){					// insert an element at the end of the list
	Node* temp1=new Node();
	temp1->data=x;
	temp1->next=NULL;
	if(head==NULL){
		head=temp1;
		return;
	}
	Node* temp=head;
	while(temp->next!=NULL)
		temp=temp->next;
	temp->next=temp1;
}

void print(){
	Node* temp=head;
	while(temp!=NULL)
	{
		printf(" %d",temp->data);
		temp=temp->next;
	}
	printf("\n");
}

void reverse(){
	if(head==NULL) return;
	stack<struct Node*> s;
	Node* temp=head;
	while(temp!=NULL){
		s.push(temp);
		temp=temp->next;
	}
	temp=s.top();
	head=temp;
	s.pop();
	while(!s.empty()){
		temp->next=s.top();
		s.pop();
		temp=temp->next;
	}
	temp->next=NULL;
}	

int main()
{
	head=NULL;				// empty list
	insert(2);			
	insert(4);		
	insert(6);			
	insert(8);			// list is 2,4,6,8
	print();
	reverse();
	print();	
	return 0;
}