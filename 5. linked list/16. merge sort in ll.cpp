// merge sort in linked list

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

node* mergeTwoLl(node *h1, node *h2){
    
    node *fh = NULL, *ft = NULL, *temp = NULL;    
    
    while(h1 != NULL and h2 != NULL){
        if(h1 -> data < h2 -> data){
            temp = h1;
            h1 = h1 -> next;
        }
        else{
            temp = h2;
            h2 = h2 -> next;
        }
        if(fh == NULL)
            fh = ft = temp;
        else{
            ft -> next = temp;
            ft = temp;            
        }
    }    
    while(h1 != NULL){
        ft -> next = h1;
        ft = h1;
        h1 = h1 -> next;
    }
        
    while(h2 != NULL){
        ft -> next = h2;
        ft = h2;
        h2 = h2 -> next;
    }
    return fh;
}

node* mergeSort(node *head) {
    if(head -> next == NULL)
        return head;
    
    node* slow = head, *fast = head -> next;
    while(fast != NULL and fast -> next != NULL){
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    
    node *h1 = head, *h2 = slow -> next;
    slow -> next = NULL;
    
    h1 = mergeSort(h1);
    h2 = mergeSort(h2);
    
    head = mergeTwoLl(h1, h2);
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
    head= mergeSort(head);
    print(head);
    return 0;
}