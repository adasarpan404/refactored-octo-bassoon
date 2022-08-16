#include<iostream>

using namespace std;

class node{
    public:
        int data;
        node* next;
        node(int value){
            data = value;
        }
};

void insertathead(node*& head, int val){
    node* n = new node(val);
    n -> next = head;
    head = n;
}

void print(node*& head){
    node* temp = head;
    while(temp!= NULL){
        cout<<temp->data<<"->";
        temp = temp -> next;
    }
    cout<<"NULL"<<endl;
}

bool detectloop(node*& head){
    node* fastPtr = head;
    node* slowPtr = head;
    while (slowPtr && fastPtr && fastPtr->next){
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;
        if (slowPtr == fastPtr) {
            return true;
        }
    }
    return false;
}

int main(){
    node* head = NULL;
    insertathead(head,1);
    insertathead(head,2);
    insertathead(head,3);
    insertathead(head,4);
    head -> next -> next -> next -> next = head;
    cout<<detectloop(head);
}