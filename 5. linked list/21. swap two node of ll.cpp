//Implement code to swap two elements of a Linked List. You need to swap the nodes not the data

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

node* swap_nodes(node *head, int i, int j)
{    
    node *iprev, *icurr, *jprev, *jcurr, *temp = head;
    if(i > j)
        swap(i, j);
    if(i == 0){
        iprev = NULL;
        icurr = head;
    }
    int c = 0;
    
    while(temp != NULL){
        if(c + 1 == i){
            iprev = temp;
            icurr = temp -> next;
        }
        if(c + 1 == j){
            jprev = temp;
            jcurr = temp -> next;
            break;
        }
        temp = temp -> next;
        c++;
    }
    
    if(iprev != NULL)
        iprev -> next = jcurr;
    else
        head = jcurr;
    if(jprev != NULL)
        jprev -> next = icurr;
    
    temp = jcurr -> next;  
    jcurr -> next = icurr -> next;  
    icurr -> next = temp;  
            
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
    int i,j;
    node* head =takeinput();
    cin>>i;
    cin>>j;
    head=swap_nodes(head,i,j);
    print(head);
    return 0;
}