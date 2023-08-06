// This program is to practice the reversal of linkedlist
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

void insertathead(Node *&head, int data)
{
    Node *node = new Node(data);
    node->next = head;
    head = node;
}

void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void reverse(Node *&head)
{
    Node *future = NULL, *prev = NULL, *current = head;
    while (current != NULL)
    {
        future = current->next;
        current->next = prev;
        prev = current;
        current = future;
    }
    head = prev;
}

int main()
{
    Node *head = NULL;
    insertathead(head, 1);
    insertathead(head, 2);
    insertathead(head, 3);
    insertathead(head, 4);
    insertathead(head, 5);
    cout << "Before reversing" << endl;
    print(head);
    cout << "After reversing" << endl;
    reverse(head);
    print(head);
}