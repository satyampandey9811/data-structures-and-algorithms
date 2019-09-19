// linked list 
// delete a node at the nth position

#include<stdlib.h>
#include<stdio.h>

struct Node
{
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

void delete(int n){
	struct Node* temp1=head;
	if(n==1){
		head=temp1->next;				// head now points to second node
		free(temp1);
		return;
	}
	int i;
	for(i=0;i<n-2;i++)
		temp1=temp1->next;
	// temp1 points to (n-1)th node
	struct Node* temp2=temp1->next;		// nth node
	temp1->next=temp2->next;			// (n+1)th node
	free(temp2);						// delete temp2 in c++
}

void main()
{
	head=NULL;				// empty list
	insert(2);			
	insert(3);		
	insert(4);			
	insert(5);			// list is 2,4,6,5
	print();
	int n;
	printf("Enter a position : ");
	scanf("%d",&n);
	delete(n);
	print();	
}
