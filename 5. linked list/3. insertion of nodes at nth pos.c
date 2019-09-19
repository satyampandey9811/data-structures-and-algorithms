// linked list 
// insertion of nodes at the nth position

#include<stdlib.h>
#include<stdio.h>

struct Node
{
  int data;
  struct Node* next;
}Node;

struct Node* head;

void insert(int x, int n){
	struct Node* temp1=(struct Node*)malloc(sizeof(struct Node));
	temp1->data=x;
	temp1->next=NULL;
	if(n==1){
		temp1->next=head;
		head=temp1;
		return;
	}
	struct Node* temp2=head;
	for(int i=0;i<n-2;i++){
		temp2=temp2->next;
	}
	temp1->next=temp2->next;
	temp2->next=temp1;
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

void main()
{
	head=NULL;				// empty list
	insert(2,1);			// list is 2
	insert(3,2);			// list is 2,3
	insert(4,1);			// list is 4,2,3
	insert(5,2);			// list is 4,5,2,3
	print();	
}
