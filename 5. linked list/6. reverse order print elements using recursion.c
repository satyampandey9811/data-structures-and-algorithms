// linked list
// print elements in reverse order using recursion

#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node* next;
}Node;

struct Node* insert(struct Node *head, int x){					// insert an element at the end of the list
	struct Node* temp1=(struct Node*)malloc(sizeof(struct Node));
	temp1->data=x;
	temp1->next=NULL;
	if(head==NULL){
		head=temp1;
		return head;
	}
	struct Node* temp=head;
	while(temp->next!=NULL)
		temp=temp->next;
	temp->next=temp1;
	return head;
}

void print(struct Node* head){
	if(head==NULL)
		return;	
	print(head->next);
	printf("%d ",head->data);
}

void main()
{
	struct Node* head=NULL;				// empty list
	head=insert(head,2);			
	head=insert(head,4);		
	head=insert(head,6);			
	head=insert(head,8);			// list is 2,4,6,8
	print(head);	
}