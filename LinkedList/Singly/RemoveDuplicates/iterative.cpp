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
    n -> next = head;
    head = n;
}

void print(node*& head){
    node* temp = head;
    while(temp != NULL){
        cout<<temp-> data<<"->";
        temp = temp -> next;
    }

    cout<<"NULL"<<endl;
}


void removeDuplicates(node*& head){
    node* current = head;
    node* next_next;
    if(current==NULL) return;
    
    while(current->next != NULL){
        if(current->data == current->next->data){
            next_next = current -> next ->next;
            free(current->next);
            current->next = next_next;
        }else{
            current = current -> next;
        }
    }
}

int main(){
    node* head = NULL;
    insertathead(head,4);
    insertathead(head,4);
    insertathead(head,3);
    insertathead(head,3);
    insertathead(head,2);
    insertathead(head,2);
    insertathead(head,1);
    cout<<"initial linkedlist \n";
    print(head);
    removeDuplicates(head);
    print(head);
}