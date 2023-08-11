#include <iostream>

using namespace std;

// defining a structure for linked list node
class StackNode
{
public:
    int data;
    StackNode *next;
    // constructor is used for initialising the node in linkedlist
    StackNode(int value)
    {
        data = value;
        next = NULL;
    }
};

// Push function is being used for inserting the element in stack.
// Push function will be similiar to insert at head in linkedlist.
void push(StackNode *&head, int value)
{
    StackNode *node = new StackNode(value);
    node->next = head;
    head = node;
}

void pop(StackNode *&head)
{
    /*
        @desc: Pop function is being used for deletion of element in stack
        @working: Pop function will work similiar to delete head in linked list
    */

    StackNode *temp = head;
    cout << temp->data << endl;
    head = head->next;
    delete temp;
}

bool isEmpty(StackNode *&head)
{
    /*
        @desc: isEmpty Function is being used for check the stack is empty or not.
        @working: this checks head is a null or not
    */
    return !head;
}

int peek(StackNode *&head)
{
    /*
        @desc: Peek function will be used for getting the top element of stack
        @working: This function will just return the data of head node.
    */
    if (isEmpty(head))
    {
        return -1;
    }
    return head->data;
}

int main()
{
    StackNode *head = NULL;
    push(head, 1);
    push(head, 2);
    cout << peek(head);
    pop(head);
    return 0;
}