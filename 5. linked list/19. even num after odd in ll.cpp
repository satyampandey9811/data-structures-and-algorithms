//Arrange elements in a Linked List such that all even numbers are placed after odd numbers

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

node* arrange_LinkedList(node* head)
{
    node *evenhead = NULL, *eventail, *oddhead = NULL, *oddtail;
    
    while(head != NULL){
        if(head -> data % 2 == 0){
            if(evenhead == NULL)
                evenhead = eventail = head;
            else{
                eventail -> next = head;
                eventail = head;
            }
            head = head -> next;
            eventail -> next = NULL;
        }
        else{
            if(oddhead == NULL)
                oddhead = oddtail = head;
            else{
                oddtail -> next = head;
                oddtail = head;
            }
            head = head -> next;
            oddtail -> next = NULL;
        }        
    }
    
    if(oddhead != NULL){
        oddtail -> next = evenhead;
        return oddhead;
    }
    return evenhead;
}

node* takeinput(){
    int data;
    cin>>data;
    node* head=NULL,*tail=NULL;
    while(data!=-1){
        node *newnode=new node(data);
        if(head==NULL)                  {
            head=newnode;
            tail=newnode;
        }
        else{
            tail->next=newnode;
            tail=newnode;
        }
        cin>>data;
    }
    return head;
}

void print(node *head)
{
    node*temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main()
{
    node*head=takeinput();
    head=arrange_LinkedList(head);
    print(head);
    return 0;
}