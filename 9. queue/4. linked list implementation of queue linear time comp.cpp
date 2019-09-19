// queue
// linked list implementation of queue
// time comp. for enqueue : O(1)
// time comp. for dequeue : O(n)

#include<bits/stdc++.h>
using namespace std;
struct node {
	int data;
	node* next;
};

node* head;

void enqueue(int x) {
	node* temp1 = new node();
	temp1->data = x;
	temp1->next = head;
	head = temp1;
}

void dequeue() {
	if (head == NULL) {
		cout << "Error : queue is empty";
		return;
	}
	node* temp = head;
	if (temp->next == NULL) {
		head = NULL;
		free(temp);
		return;
	}
	node* temp1 = head;
	temp1 = temp1->next;
	while (temp1->next != NULL) {
		temp1 = temp1->next;
		temp = temp->next;
	}
	free(temp1);
	temp->next = NULL;
}

int Front() {
	if (head==NULL) {
		cout << "Queue is empty";
		return -1;
	}
	node* temp = head;
	while (temp->next != NULL)
		temp = temp->next;
	return temp->data;
}

void print() {
	if (head==NULL) {
		cout << "No elements in the queue right now";
		return;
	}
	node* temp = head;
	cout << "Queue is : ";
	while (temp != NULL) {
		cout << temp->data << ' ';
		temp = temp->next;
	}
	cout << endl;
}

int main() {
	head = NULL;
	enqueue(2); print();
	enqueue(4); print();
	enqueue(6); print();
	dequeue(); print();
	enqueue(8); print();
	system("pause");
	return 0;
}