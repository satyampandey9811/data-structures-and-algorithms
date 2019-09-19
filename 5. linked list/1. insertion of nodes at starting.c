// linked list 
// insertion of nodes at the beginning

#include<stdlib.h>
#include<stdio.h>

struct Node
{
  int data;
  struct Node* next;
}Node;

struct Node* head;

void insert(int x){
	struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
	temp->data=x;
	temp->next=head;
	head=temp;
}

void print(){
	struct Node* temp=head;
	printf("List is : ");
	while(temp!=NULL)
	{
		printf(" %d",temp->data);
		temp=temp->next;
	}
	printf("\n");
}	

void main()
{
	head=NULL;								// empty list
	printf("how many numbers?\n");
	int n,i,x;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("enter the number\n");
		scanf("%d",&x);
		insert(x);
		print();
	}
}
