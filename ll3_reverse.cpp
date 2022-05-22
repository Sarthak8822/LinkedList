#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    // Constructor build
    node(int val){
        data=val;
        next=NULL;
    }
};

void insertAtHead(node *&head, int val){
    node* n = new node(val);
    n->next = head;
    head=n;
}

void insertAtTail(node *&head, int val){
    node* n = new node(val);

    if (head==NULL)
    {
        head=n;
        return;
    }
    node* temp=head;
    while (temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=n;
}
void display(node* head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

bool search(node *&head, int key){
    node* temp=head;
    while (temp!=NULL)
    {
        if(temp->data==key){
            return true;
        }
        temp=temp->next;
    }
    return false;    
}

void deleteAthead(node *&head){
    node* n = head;
    head=head->next;
    delete n;
}

void deletion(node* &head, int val){
    if (head==NULL)
    {
        cout<<"Nothing can be deleted"<<endl;
    }
    
    node* temp=head;
    while (temp->next->data!=val){
        temp=temp->next;
    }
    node* todelete=temp->next;
    temp->next=temp->next->next;
    delete todelete;    
} 

node* reverse(node* &head){
    node* prevptr=NULL;
    node* current=head;
    node* nextptr;

    while(current!=NULL){
        nextptr=current->next;
        current->next=prevptr;

        prevptr=current;
        current=nextptr;
    }

    return prevptr;
}

node* reverseRecursive(node* &head){
    node* newhead=reverseRecursive(head->next);

    head->next->next=head;
    head->next-NULL;

    return newhead;
}

int main(){
    node* head=NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4); 
    
    display(head);
    // node* newhead = reverse(head);
    node* newhead = reverseRecursive(head);
    display(newhead);
    
    return 0;
} 