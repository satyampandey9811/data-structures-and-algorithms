// linked list
// reverse a linked list iterative
// time comp : O(n)
// space comp : O(1)

#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node* next;
}Node;

struct Node* head;

void insert(int x){					// insert an element at the end of the list
	struct Node* temp1=(struct Node*)malloc(sizeof(struct Node));
	temp1->data=x;
	temp1->next=NULL;
	if(head==NULL){
		head=temp1;
		return;
	}
	struct Node* temp=head;
	while(temp->next!=NULL)
		temp=temp->next;
	temp->next=temp1;
}

void print(){
	struct Node* temp=head;
	while(temp!=NULL)
	{
		printf(" %d",temp->data);
		temp=temp->next;
	}
	printf("\n");
}

void reverse(){
	struct Node *prev,*next,*current;
	current=head;
	prev=NULL;
	while(current!=NULL){
		next=current->next;
		current->next=prev;
		prev=current;
		current=next;
	}
	head=prev;	
}

void main()
{
	head=NULL;				// empty list
	insert(2);			
	insert(4);		
	insert(6);			
	insert(8);			// list is 2,4,6,8
	print();
	reverse();
	print();	
}