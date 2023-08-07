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
    while (temp != NULL)
    {
        cout << temp->data << " ->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

bool detectLoop(Node *&head)
{
    Node *fastPtr = head;
    Node *slowPtr = head;
    while (slowPtr && fastPtr && fastPtr->next)
    {
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;
        if (slowPtr == fastPtr)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    Node *head = NULL;
    int values[] = {5, 4, 3, 2, 1};
    int numValues = sizeof(values) / sizeof(values[0]);

    for (int i = 0; i < numValues; i++)
    {
        insertAtHead(head, values[i]);
    }
    print(head);
    head->next->next->next->next->next = head->next->next;
    cout << (detectLoop(head) ? "Loop exists" : "Loop does not exist");
    return 0;
}
