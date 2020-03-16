//Check if a linked list is a palindrome or not

#include <iostream>
using namespace std;

class node{
public:
    int data;
    node * next;
    node(int data){
        this->data=data;
        this->next=NULL;
    }
};

node* reverse(node *i){
    if(i -> next == NULL)
        return i;
    node* temp = reverse(i -> next);
    i -> next -> next = i;
    i -> next = NULL;
    return temp;
}

bool check_palindrome(node* head)
{
    node *i = head, *temp = head;
    while(temp != NULL and temp -> next != NULL){
        i = i -> next;
        temp = temp -> next -> next;        
    }
    temp = head;
    i = reverse(i);
    while(temp != NULL and i != NULL){
        if(temp -> data != i -> data)
            return false;
        temp = temp -> next; 
        i = i -> next;
    }
    return true;
}

node* takeinput(){
    int data;
    cin >> data;
    node *head = NULL, *tail = NULL;
    while(data != -1){
        node *newnode = new node(data);
        if(head == NULL)                  {
            head = newnode;
            tail = newnode;
        }
        else{
            tail -> next = newnode;
            tail = newnode;
        }
        cin >> data;
    }
    return head;
}

void print(node *head)
{
    node *temp = head;
    while(temp != NULL)
    {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

int main()
{
    node* head = takeinput();
    bool ans = check_palindrome(head);
    if(ans)
        cout<<"true";
    else 
        cout << "false";
    return 0;
}