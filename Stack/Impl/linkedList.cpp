// implementation of queue using linkedList

#include <iostream>

using namespace std;
// defining a structure for linked list node
class stackNode
{
public:
    int data;
    stackNode *next;
    // constructor is used for initialising the node in linkedlist
    stackNode(int value)
    {
        data = value;
        next = NULL;
    }
};

// Push function is being used for inserting the element in stack.
// Push function will be similiar to insert at head in linkedlist.
void push(stackNode*& head, int val)
{
    stackNode *n = new stackNode(val);
    n->next = head;
    head = n;
}

void pop(stackNode*& head)
{
    /*
        @desc: Pop function is being used for deletion of element in stack
        @working: Pop function will work similiar to delete head in linked list
    */
    stackNode *temp = head;
    cout << temp->data << endl;
    head = head->next;
    delete temp;
}

int isEmptY(stackNode*& head)
{
    /*
        @desc: isEmpty Function is being used for check the stack is empty or not.
        @working: this checks head is a null or not
    */
    return !head;
}

int peek(stackNode*& head)
{
    /*
        @desc: Peek function will be used for getting the top element of stack
        @working: This function will just return the data of head node.
    */
    if (isEmptY(head))
    {
        return -1;
    }
    return head->data;
}





int main(){
    stackNode* head = NULL;
    push(head, 1);
    push(head, 2);
    cout<<peek(head);
    pop(head);
    return 0;
}
