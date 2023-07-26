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
}