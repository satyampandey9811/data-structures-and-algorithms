// circular linked list
// insertion at start,end and in between

#include<bits/stdc++.h> 
using namespace std; 

struct Node 
{ 
	int data; 
	struct Node *next; 
}; 

struct Node *addToEmpty(struct Node *last, int data) 
{ 
	// This function is only for empty list 
	if (last != NULL) 
	return last; 

	// Creating a node dynamically. 
	struct Node *temp = 
		(struct Node*)malloc(sizeof(struct Node)); 

	// Assigning the data. 
	temp -> data = data; 
	last = temp; 

	// Creating the link. 
	last -> next = last; 

	return last; 
} 

struct Node *addBegin(struct Node *last, int data) 
{ 
	if (last == NULL) 
		return addToEmpty(last, data); 

	struct Node *temp = 
			(struct Node *)malloc(sizeof(struct Node)); 

	temp -> data = data; 
	temp -> next = last -> next; 
	last -> next = temp; 

	return last; 
} 

struct Node *addEnd(struct Node *last, int data) 
{ 
	if (last == NULL) 
		return addToEmpty(last, data); 
	
	struct Node *temp = 
		(struct Node *)malloc(sizeof(struct Node)); 

	temp -> data = data; 
	temp -> next = last -> next; 
	last -> next = temp; 
	last = temp; 

	return last; 
} 

struct Node *addAfter(struct Node *last, int data, int item) 
{ 
	if (last == NULL) 
		return NULL; 

	struct Node *temp, *p; 
	p = last -> next; 
	temp=(struct Node*)malloc(sizeof(struct Node));
	temp->data=data;
	while(p!=last and p->data!=item){
	    p=p->next;
	}
	if(p!=last){
	    temp->next=p->next;
	    p->next=temp;
	}
	else{
	    if(p->data==item){
	        temp->next=last->next;
	        last->next=temp;
	        last=temp;
	    }
	    else{
	        cout<<"element "<<item<<" is not in the list"<<endl;
	        cout<<"so , the data "<<data<<" can't be added"<<endl;
	    }
	}
    return last;
} 

void traverse(struct Node *last) 
{ 
	struct Node *p; 

	// If list is empty, return. 
	if (last == NULL) 
	{ 
		cout << "List is empty." << endl; 
		return; 
	} 

	// Pointing to first Node of the list. 
	p = last -> next; 

	// Traversing the list. 
	while(p!=last){
	    cout<<p->data<<' ';
	    p=p->next;
	} 
    cout<<p->data;
} 

// Driven Program 
int main() 
{ 
	struct Node *last = NULL; 

	last = addToEmpty(last, 6); 
	last = addBegin(last, 4); 
	last = addBegin(last, 2); 
	last = addEnd(last, 8); 
	last = addEnd(last, 12); 
	last = addAfter(last, 14, 12); // adding after 12 which is at the end
	last = addAfter(last, 10, 8);  // adding after 8
	last = addAfter(last, 16, 15); // adding after 15 which is not in the list 

	traverse(last); 

	return 0; 
}