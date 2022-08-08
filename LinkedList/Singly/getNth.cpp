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
        cout<<temp->data<<"->";
        temp = temp-> next;
    }

    cout<<"NULL"<<endl;
}

int getNth(node*& head, int index){
    node* current = head;
    int count = 0;
    while(current!=NULL){
        if(count==index){
            return current->data;
        }
        count++;
        current = current -> next;
    }
    return -1;
}

int main(){
    node* head = NULL;
    insertathead(head, 1);
    insertathead(head, 2);
    insertathead(head, 3);
    print(head);
    cout<<"Element at 3rd position is"<<getNth(head, 3);
}