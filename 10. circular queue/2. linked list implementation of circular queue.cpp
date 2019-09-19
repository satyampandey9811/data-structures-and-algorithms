// circular queue
// implementation using linked list

#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	node* next;
};

node *front,*rear;

bool isempty(){
	if(front==NULL and rear==NULL)
		return true;
	return false;
}

void enqueue(int x){
	node *temp=new node();
	temp->data=x;
	if(isempty()){
		front=rear=temp;
		front->next=temp;
		return;
	}
	temp->next=rear->next;
	rear->next=temp;
	rear=temp;
}

void dequeue(){
	if(isempty()){
		cout<<"queue is empty";
		return;
	}
	node *temp=front;
	if(front==rear)
		front=rear=NULL;
	else{
		rear->next=front->next;
		front=rear->next;
	}
	delete(temp);
}

int Front(){
	if(front==NULL){
		cout<<"queue is empty";
		return -1;
	}
	return front->data;
}

void print(){
	if(isempty()){
		cout<<"queue is empty";
		return;
	}
	cout<<"queue is : ";
	node* temp=front;
	while(temp!=rear){
		cout<<temp->data<<' ';
		temp=temp->next;
	}
	cout<<rear->data<<endl;
}

int main(){
	enqueue(2); print();
	enqueue(4); print();
	enqueue(6); print();
	enqueue(8); print();
	dequeue(); print();
	enqueue(10); print();
	return 0;
}