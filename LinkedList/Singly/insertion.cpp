// Alternate method to declare the class in order to minimize the memory allocation work

#include <iostream>
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

void insertafter(node* head, int key, int val)
{
    node* n = new node(val);
    if (key == head->data) {
        n->next = head->next;
        head->next = n;
        return;
    }
  
    node* temp = head;
    while (temp->data != key) {
        temp = temp->next;
        if (temp == NULL) {
            return;
        }
    }
    n->next = temp->next;
    temp->next = n;
}

void insertattail(node*& head, int val){
    node* newnode = new node(val);
    if(head == NULL){
        head = newnode;
        return;
    }

    node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newnode;
}
void print(node*& head)
{
	node* temp = head;

	while (temp != NULL) {
		cout << temp->data << " -> ";
		temp = temp->next;
	}
	cout << "NULL" << endl;
}




// main function
int main()
{
	node* head = NULL;	 //declaring an empty linked list

	// insertathead(head, 1);
	// insertathead(head, 2);
	cout << "After insertion at head: ";
	print(head);
	cout << endl;
	insertattail(head, 4);
	insertattail(head, 5);
	cout << "After insertion at tail: ";
	print(head);
	cout << endl;

	insertafter(head, 1, 2);
	insertafter(head, 5, 6);
	cout << "After insertion at a given position: ";
	print(head);
	cout << endl;

	return 0;
}

