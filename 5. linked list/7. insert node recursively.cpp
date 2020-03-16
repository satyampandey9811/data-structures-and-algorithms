#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node *next;
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};

Node* insertNodeRec(Node *head, int i, int data) {
    
  if(head == NULL and i != 0)			// for inserting at the last of the linked list
    return head;						// that is it should be the last element of the ll
  
  if(i == 0)
  {
    Node *newnode = new Node(data);
    newnode -> next = head;
    head = newnode;
    return head;
  }
  Node * x = insertNodeRec(head -> next, i - 1, data);
  head -> next = x;
  return head;
}

Node* takeinput() {
    int data;
    cin >> data;
    Node* head = NULL, *tail = NULL;
    while(data != -1){
        Node *newNode = new Node(data);
        if(head == NULL)                  {
            head = newNode;
            tail = newNode;
        }
        else{
            tail -> next = newNode;
            tail = newNode;
        }
        cin >> data;
    }
    return head;
}

void print(Node *head) {
    Node *temp = head;
    while(temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout<<endl;
}

int main() {
    Node *head = takeinput();
    int pos, data;
    cin >> pos >> data;
    head = insertNodeRec(head, pos, data);
    print(head);
    return 0;
}
