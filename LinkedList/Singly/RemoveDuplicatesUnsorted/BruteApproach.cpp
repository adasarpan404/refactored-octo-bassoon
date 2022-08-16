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

void insertattail(node*& head, int val){
    node* newnode = new node(val);
    if(head == NULL){
        head = newnode;
        return;
    }
    node *temp = head;
    while(temp -> next != NULL){
        head = temp -> next;
    }
    temp -> next = newnode;

}

void print(node*& head){
    node* temp = head;
    while(temp!= NULL){
        cout<<temp -> data<<"->";
        temp = temp -> next;
    }
    cout<<"NULL"<<endl;
}

void removeDuplicates(node*& head){
    node* ptr1;
    node* ptr2;
    node* dup;
    ptr1 = head;
    while(ptr1 != NULL && ptr1->next != NULL){

        ptr2 = ptr1;
        while(ptr2->next != NULL){
            if(ptr1->data == ptr2->next->data){
                dup = ptr2->next;
                ptr2->next = ptr2->next->next;
                free(dup);

            }else{
                ptr2= ptr2-> next;
            }
        }
        ptr1 = ptr1 ->next;
    }
}

int main(){
    node* head = NULL;
    insertathead(head, 1);
    insertathead(head, 2);
    insertathead(head, 2);
    insertathead(head, 2);
    print(head);
    removeDuplicates(head);
    print(head);
    
}