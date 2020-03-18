// stack using linked list

#include<bits/stdc++.h>
using namespace std;

template<typename t>
class node{
public:
	t data;
	node<t> *next;
	
	node(t data){
		this -> data = data;
		next = NULL;
	}
};

template<typename t>			// have to mention it for every class in which we use.
class Stack {
    Node<T> *head;
    int size;		// number of elements present in stack
    
public :
    
    Stack() {
        head = NULL;
        size = 0;
    }
    
    int getSize() {
        return size;
    }
    
    bool isEmpty() {
        return head == NULL;
    }
    
    void push(T element) {
        Node<T> *newnode = new Node<T>(element);
        if(head == NULL)
            head = newnode;
        else{
            newnode -> next = head;
            head = newnode;
        }
        size++;
    }
    
    T pop() {
        // Return 0 if stack is empty. Don't display any other message
        if(isEmpty())
            return 0;
        T val = head -> data;
        Node<T> *temp = head;
        head = head -> next;
        delete temp;
        size--;
        return val;
    }
    
    T top() {
        // Return 0 if stack is empty. Don't display any other message
        if(isEmpty())
            return 0;
        return head -> data;
    }  
};