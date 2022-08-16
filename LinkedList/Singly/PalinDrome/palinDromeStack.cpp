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
    n-> next = head;
    head = n;
}

bool isPalin(node*& head){
    node* slow = head;
    stack<int> s;
    while(slow!=NULL){
        s.push(slow->data);
        slow = slow-> next;
    }

    while(head!=NULL){
        int val = s.top();
        s.pop();
        if(head-> data !=val){
            return false;
        }
        head = head->next;
    }
    return true;
}
void print(node*& head){
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp = temp -> next;
    }
    cout<<"NULL"<<endl;
}

int main(){
    node* head = NULL;
    insertathead(head, 1);
    insertathead(head,2);
    insertathead(head, 2);
    insertathead(head, 1);

    print(head);
    cout<<isPalin(head);
}