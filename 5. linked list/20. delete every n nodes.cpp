// you have to retain m nodes then delete next n nodes and repeat this process.
// example :
// input : 1 2 3 4 5 6 7 8 -1 and m = 2 and n = 3;
// output : 1 2 6 7 

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

node* skipMdeleteN(node *head, int m, int n) {
    
    if(m == 0){
        head = NULL;
        return head;
    }
    node *travel = head, *remove, *temp;
    int t = 0, r;
    while(travel != NULL){
        t++;
        if(t == m){
            remove = travel -> next;            
            r = 0;
            while(r < n and remove != NULL){
                r++;
                temp = remove;
                remove = remove -> next;
                delete temp;
                travel -> next = remove;                
            }
            travel = remove;
            t = 0;
        }
        else
            travel = travel -> next;
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
    int m,n;
    cin>>m >> n;
    head= skipMdeleteN(head,m,n);
    print(head);
    return 0;
}