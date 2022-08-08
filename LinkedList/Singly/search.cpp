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
        cout<< temp -> data <<" -> ";
        temp = temp -> next;
    }

    cout<<"NULL"<<endl;
}

bool search(node*& head, int search){
    node* current = head;
   while (current != NULL)
    {
        if (current->data == search)
            return true;
        current = current->next;
    }
    return false;
}

int main(){
    node* head = NULL;
    insertathead(head, 1);
    insertathead(head, 2);
    insertathead(head, 3);
    insertathead(head, 4);
    print(head);
    search(head, 21)? cout<<"Yes \n" : cout<<"No \n";
    search(head, 2)? cout<<"Yes \n" : cout<<"No \n";
    }