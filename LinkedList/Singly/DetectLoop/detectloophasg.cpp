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

void print(node*& head){

    node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp = temp -> next;
    }
    cout<<"NULL"<<endl;
}

bool detectloop(node*& head){
    
    unordered_set<node*> s;
    while (head != NULL) {
        if (s.find(head) != s.end())
        {

            return true;
        }
        
        s.insert(head);
 
        head = head->next;
    }

    return false;
}

int main(){
    node* head = NULL;
    insertathead(head,1);
    insertathead(head,2);
    insertathead(head,3);
    insertathead(head,4);
    cout<<detectloop(head);
}