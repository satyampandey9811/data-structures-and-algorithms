// stack 
// linked list implementation of stack

#include<stdio.h>

struct Node{
	int data;
	struct Node* link;
}Node;

struct Node* top=NULL;

void push(int x){
	struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
	temp->data=x;
	temp->link=top;
	top=temp;
}

void pop(){
	if(top==NULL){
		printf("Stack is empty\n");
		return;
	}
	struct Node* temp=top;
	top=top->link;
	free(temp);
}

void print(){
	printf("Stack : ");
	struct Node* temp=top;
	while(temp!=NULL){
		printf("%d ",temp->data);
		temp=temp->link;
	}
	printf("\n");
}

int main(){
	push(2); print();
	push(4); print();
	push(6); print();
	pop(); print();
	push(8); print();
	return 0;
}
