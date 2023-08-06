// this program is for practicing insertion in linkedlist
#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int value)
    {
        data = value;
        next = NULL;
    }
};

void insertAtHead(Node *&Head, int val)
{
    Node *node = new Node(val);
    node->next = Head;
    Head = node;
}

void insertAtTail(Node *&Head, int val)
{
    Node *node = new Node(val);
    if (Head == NULL)
    {
        Head = node;
        return;
    }
    Node *temp = Head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = node;
}

void insertAfter(Node *&Head, int val, int key)
{
    Node *node = new Node(val);
    if (key == Head->data)
    {
        node->next = Head->next;
        Head->next = node;
        return;
    }
    Node *temp = Head;
    while (temp->data != key)
    {
        temp = temp->next;
        if (temp == NULL)
        {
            return;
        }
    }
    node->next = temp->next;
    temp->next = node;
}

void print(Node *&Head)
{
    Node *temp = Head;
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    Node *Head = NULL;
    cout << "After insertion at head: ";
    print(Head);
    cout << endl;
    insertAtTail(Head, 4);
    insertAtTail(Head, 5);
    print(Head);
    cout << endl;
    insertAtHead(Head, 6);
    insertAtHead(Head, 7);
    print(Head);
    cout << endl;
    insertAfter(Head, 8, 4);
    insertAfter(Head, 9, 7);
    print(Head);
    cout << endl;
    return 0;
}
