

#include<iostream>

using namespace std;

// First I am going to declare a node 

class node{
    public: 
        int data;
        node* next;
        node(int value){
            data = value;
            next = NULL;
        }
}

// second step would be inserting a element
    // substep 1  would be I am going to write how to insert a new node on the start of the node 
void insert(node*& head, int val){
    node* n = new node(val);
    n -> next = head;
    head =n;
}
    // substep 2 would be I am going to write how to insert after 

    void insertafter(node* head, int val){
        node* n = new node(val);
        if(key == head -> data){
            n-> next = head -> next;
            head -> next =n;
            return;
        }
        node* temp = head;
        while(temp-> data != key){
            temp = temp -> next;
            if(temp == NULL){
                return;
            }
        }

        n -> next = temp -> next;
        temp -> next = n;
    }

    // substep 3 would be I am going to write code for how to insert the end of the list
    void insertattail(node*& head, int val){
        node* newnode = new node(val);
        if(head == NULL){
            head = newnode;
            return;
        }
        node *temp = head;
        while(temp -> next != NULL){
            temp = temp -> next;
        }
        temp -> next = newnode;
    }
//Third step would be print the linkedlist
 void print(node*& head){
    node* temp = head;
    while(temp!=NULL){
        cout<< temp -> data <<" -> ";
        temp = temp -> next;
    }
    cout<<" NULL"<<endl
 }

// Fourth step would be writng the code the deletion of linkedlist


// Fifth step would be main function 
int main(){
    node* head = NULL;
    insertathead(head, 1);
    insertathead(head, 2);
    cout<<"After insertion at head:";

    print(head);
    cout<<endl;
    insertattail(head,4);
    insertattail(head,5);
    cout<<"After insertion at tail:";
    print(head);
    cout<<endl;
    insertafter(head,1,2);
    insertafter(head,5,6);
    cout<<"After insertion at a given position:";
    print(head);
    cout<<endl;
    return 0;
}