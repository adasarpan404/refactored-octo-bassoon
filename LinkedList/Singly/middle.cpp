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
        cout<<temp -> data <<"->";
        temp = temp -> next;
    }
    cout<<"NULL"<<endl;
}

void printMiddle(node*& head){
    node* fastPtr = head;
    node* slowPtr = head;

     if (head!=NULL)
        {
            while (fastPtr != NULL && fastPtr->next != NULL)
            {
                fastPtr = fastPtr->next->next;
                slowPtr = slowPtr->next;
            }
            cout << "The middle element is [" << slowPtr->data << "]" << endl;
        }
}

int main(){
    node* head = NULL;
    for(int i=0;i<15;i++){
        insertathead(head,i);
        print(head);
        printMiddle(head);
    }
}