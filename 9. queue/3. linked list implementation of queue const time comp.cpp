// queue
// linked list implementation of queue
// time comp. for enqueue : O(1)
// time comp. for dequeue : O(1)

#include<bits/stdc++.h>
using namespace std;
struct node {
	int data;
	node* next;
};

node *front,*rear;

void enqueue(int x){
	node* temp=new node();
	temp->data=x;
	temp->next=NULL;
	if(front==NULL){
		front=rear=temp;
		return;
	}
	rear->next=temp;
	rear=temp;
}

void dequeue(){
	if(front==NULL){
		cout<<"Error : queue is empty";
		return;
	}
	node* temp=front;
	if(front==rear){
		front=rear=NULL;
	}
	else{
		front=front->next;		
	}
	free(temp);
}

int Front(){
	if(front==NULL){
		cout<<"queue is empty";
		return -1;
	}
	return front->data;
}

void print(){
	if(front==NULL){
		cout<<"queue is empty";
		return;
	}
	cout<<"Queue is : ";
	node* temp=front;
	while(temp!=NULL){
		cout<<temp->data<<' ';
		temp=temp->next;
	}
	cout<<endl;
}	

int main() {
	front=NULL;
	rear=NULL;
	enqueue(2); print();
	enqueue(4); print();
	enqueue(6); print();
	dequeue(); print();
	enqueue(8); print();
	system("pause");
	return 0;
}