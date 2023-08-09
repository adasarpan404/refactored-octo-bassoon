// This program is for removing duplicates in a sorted linkedlist using recursive approach
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

void insertAtHead(Node *&head, int value)
{
    Node *node = new Node(value);
    node->next = head;
    head = node;
}

void print(Node *&head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " ->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void removeDuplicates(Node *&head)
{
    if (head == NULL || head->next == NULL)
    {
        return;
    }
    if (head->data == head->next->data)
    {
        Node *nextNext = head->next->next;
        delete head->next;
        head->next = nextNext;
        removeDuplicates(head); // Check the current node again
    }
    else
    {
        removeDuplicates(head->next); // Move to the next node
    }
}

int main()
{
    Node *head = NULL;
    int values[] = {5, 5, 4, 4, 3, 3, 2, 2, 1, 1};
    int numValues = sizeof(values) / sizeof(values[0]);

    for (int i = 0; i < numValues; i++)
    {
        insertAtHead(head, values[i]);
    }
    cout << "Initial LinkedList" << endl;
    print(head);
    removeDuplicates(head);
    cout << "Final LinkedList" << endl;
    print(head);
}