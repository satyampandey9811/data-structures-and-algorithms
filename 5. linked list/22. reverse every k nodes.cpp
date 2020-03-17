//Implement kReverse(int k) i.e. you reverse first k elements then reverse next k elements and so on

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

node* kReverse(node* head, int n)
{
    node *temp = head, *prev = NULL, *curr = head, *next;
    node *th = head, *th1 = head, *th2 = head;
    bool flag = true;
    int len = 0, c = 0;
    while(temp != NULL){
        len++;
        temp = temp -> next;
    }
    if(n < 2 or n > len)
        return head;
    temp = head;
    
    while(temp != NULL){
        c++;
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
        if(curr == NULL or c == n){            
            th2 = prev;
            th -> next = th2;
            th = th1;
            th1 = curr;
            if(flag){
                head = th2;
                flag = false;
            }
            prev = NULL;
            c = 0;
        }
        temp = curr;                                                                   
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
    int n;
    cin>>n;
    head=kReverse(head,n);
    print(head);
    return 0;
}