// doubly linked list 
// inserting at head and tail
// printing in forward and reverse order

#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node* prev;
	struct Node* next;
}Node;

struct Node* head;

// creates a new node and returns pointer to it.
struct Node* getNewNode(int x){
	struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
	newNode->data=x;
	newNode->prev=NULL;
	newNode->next=NULL;
	return newNode;
}

// inserts a node at head of doubly linked list.
void insertAtHead(int x){
	struct Node* temp=getNewNode(x);
	if(head==NULL){
		head=temp;
		return;
	}
	head->prev=temp;
	temp->next=head;
	head=temp;
}

// inserts a node at tail of doubly linked list.
void insertAtTail(int x){
	struct Node* newNode=getNewNode(x);
	if(head==NULL){
		head=newNode;
		return;
	}
	struct Node* temp=head;
	while(temp->next!=NULL)
		temp=temp->next;
	
	temp->next=newNode;
	newNode->prev=temp;
}

// prints all the elements in the linked list in forward traversal order.
void print(){
	struct Node* temp=head;
	printf("Forward : ");
	while(temp!=NULL){
		printf("%d ",temp->data);
		temp=temp->next;
	}
	printf("\n");
}
	
// prints all the elements in the linked list in reverse traversal order.
void reversePrint(){
	struct Node* temp=head;
	if(temp==NULL)						// empty list , exit
		return;
	while(temp->next!=NULL)				// going to last node 
		temp=temp->next;
	printf("Reverse : ");
	while(temp!=NULL){					// traversing backward using prev pointer
		printf("%d ",temp->data);
		temp=temp->prev;
	}
	printf("\n");
}

int main(){
	head=NULL;
	insertAtHead(2); print(); reversePrint();
	insertAtTail(4); print(); reversePrint();
	insertAtHead(6); print(); reversePrint();
	insertAtTail(8); print(); reversePrint();
	return 0;
}