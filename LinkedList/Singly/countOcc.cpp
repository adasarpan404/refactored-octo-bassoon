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
    n-> next = head;
    head = n;
}

void print(node*& head){
    node* temp = head;
    while(temp!= NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

int countOcc(node*& head, int key){
    if(head==NULL){
        return 0;
    }
    if(head->data == key){
        return 1+countOcc(head->next, key);
    }
    return countOcc(head->next, key);
}

int main(){
    node* head = NULL;
    for(int i=0;i<28;i++){
        insertathead(head,i%6);
        print(head);
    }
    cout<<"The occurence of 2 is"<<countOcc(head,2);
}