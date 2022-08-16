#include<iostream>
using namespace std;

class node{
    public:
        int data;
        node* next;
        node(int value){
            data = value;
            next = NULL;
        }
};

void insertathead(node*& head, int val){
    node* n = new node(val);
    n->next = head;
    head = n;
}
void reverse(node*& head){
    node* prev = NULL;
    node* current = head;
    node* future;
    while(current!=NULL){
        future = current->next; 
        current->next = prev; 
        prev = current; 
        current = future; 
    }
    head = prev;
}
void print(node*& head){
    node* temp = head;
    while(temp != NULL){
        cout<<temp-> data<<"->";
        temp = temp -> next;
    }
    cout<<"NULL"<<endl;
}

int main(){
    node* head = NULL;
    insertathead(head,1);
    insertathead(head,2);
    insertathead(head,3);
    insertathead(head, 4);
    print(head);
    reverse(head);
    print(head);
}