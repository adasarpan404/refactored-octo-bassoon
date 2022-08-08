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
    while(temp!= NULL){
        cout<<temp-> data <<"->";
        temp = temp -> next;
    }
    cout<<"NULL"<<endl;
}

int getCount(node*& head){
    node* temp = head;
    int count=0;
    while(temp!= NULL){
        count++;
        temp = temp -> next;
    }
    return count;
}

int main(){
    node* head = NULL;
    insertathead(head, 1);
    insertathead(head, 3);
    insertathead(head, 5);
    insertathead(head, 7);
    insertathead(head, 7);
    insertathead(head, 7);
    insertathead(head, 7);
    print(head);
    cout<<"Number of elemets in a linkedlist = "<<getCount(head)<<endl;
    return 0;
}