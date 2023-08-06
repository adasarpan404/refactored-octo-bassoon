// this program is for practicing to find the middle of the element
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

void insertAtHead(Node *&head, int data)
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

void findMiddle(Node *&head)
{
    Node *slowPtr = head;
    Node *fastPtr = head;
    if (head != NULL)
    {
        while (fastPtr != NULL && fastPtr->next != NULL)
        {
            fastPtr = fastPtr->next->next;
            slowPtr = slowPtr->next;
        }
        cout << "Middle of the linkedlist [" << slowPtr->data << "]" << endl;
    }
}

int main()
{
    Node *head = NULL;
    insertAtHead(head, 1);
    insertAtHead(head, 2);
    insertAtHead(head, 3);
    insertAtHead(head, 4);
    insertAtHead(head, 5);
    findMiddle(head);
}