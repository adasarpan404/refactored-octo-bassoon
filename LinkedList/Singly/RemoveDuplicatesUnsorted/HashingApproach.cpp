#include<iostream>
#include<bits/stdc++.h>
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
void removeDuplicates(node*& head){
    unordered_set<int> seen;
    node* current = head;
    node* prev = NULL;
    while(current!=NULL){
        if(seen.find(current->data)!=seen.end()){
            prev->next = current ->next;
            free(current);
        }else{
            seen.insert(current->data);
            prev = current;
        }

        current = prev->next;
    }
}
void print(node*& head){
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" -> ";
        temp = temp -> next;
    }
    cout<<"NULL"<<endl;
}

int main(){
    node* head = NULL;
    insertathead(head,1);
    insertathead(head,2);
    insertathead(head,3);
    insertathead(head,4);
    insertathead(head,4);
    insertathead(head,2);
    insertathead(head,1);
    insertathead(head,4);
    insertathead(head,1);
    print(head);
    removeDuplicates(head);
    print(head);
}