//Append the last n elements of a linked list to the front

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

node* append_LinkedList(node* head, int n)
{
    int len = 0, c = 0;
    node *p = head, *q = head;
    while(p != NULL){
        len++;
        p = p -> next;
    }
    p = head;
    while(c < len - n - 1){
        c++;
        q = q -> next;
    }
    p = q -> next;
    q -> next = NULL;
    q = p;
    while(q -> next != NULL)
        q = q -> next;
    q -> next = head;
    head = p;
    return head;
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
    node* head=takeinput();
    int n;
    cin>>n;
    head=append_LinkedList(head,n);
    print(head);
    return 0;
}