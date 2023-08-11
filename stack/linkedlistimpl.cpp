#include <iostream>

using namespace std;

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

void push(StackNode *&head, int value)
{
    StackNode *node = new StackNode(value);
    node->next = head;
    head = node;
}

void pop(StackNode *&head)
{
    StackNode *temp = head;
    cout << temp->data << endl;
    head = head->next;
    delete temp;
}

bool isEmpty(StackNode *&head)
{
    return !head;
}

int peek(StackNode *&head)
{
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