// queue
// array implementation of queue

#include<bits/stdc++.h>
using namespace std;
#define max_size 101
int a[max_size];
int front = -1, rear = -1;

bool isempty() {
	if (front == -1 and rear == -1)
		return true;
	else
		return false;
}

void enqueue(int x) {
	if (rear == max_size-1) {
		cout << "Error : queue is full";
		return;
	}
	if (isempty()) {
		front = 0;
		rear = 0;
	}
	else
		rear++;
	a[rear] = x;
}

void dequeue() {
	if (isempty()) {
		cout << "Error : queue is empty";
		return;
	}
	if (front == rear) {
		front = -1;
		rear = -1;
	}
	else
		front++;
}

int Front() {
	if (isempty()) {
		cout << "Queue is empty";
		return -1;
	}
	return a[front];
}

void print() {
	if (isempty()) {
		cout << "No elements in the queue right now";
		return;
	}
	cout << "Queue is : ";
	for (int i = front; i <= rear; i++)
		cout << a[i] << ' ';
	cout << endl;
}

int main() {
	enqueue(2); print();
	enqueue(4); print();
	enqueue(6); print();
	dequeue(); print();
	enqueue(8); print();
	system("pause");
	return 0;
}