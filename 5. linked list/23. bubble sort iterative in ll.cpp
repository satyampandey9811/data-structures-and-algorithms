//bubble sort iterative

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

node* swap(node *head, node *iprev, node *icurr)
{    
    node *jprev = icurr, *jcurr = icurr -> next, *temp;                           
    
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

node* bubble_sort_LinkedList_itr(node* head)
{
    int len = 0;
    node *temp = head, *prev;
    while(temp != NULL){
        len++;
        temp = temp -> next;
    }    
    
    for(int i = 0; i < len - 1; i++){        
        temp = head;        
        prev = NULL;
        while(temp -> next != NULL){
            if(temp -> data > temp -> next -> data)
                head = swap(head, prev, temp);                                  
            else                       
                temp = temp -> next;   
            
            if(prev == NULL)
                prev = head;
            else
                prev = prev -> next;
        }
    }        
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
    head=bubble_sort_LinkedList_itr(head);
    print(head);
}