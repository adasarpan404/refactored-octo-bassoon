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
    Node *current = head;
    Node *next_next;
    if (current == NULL)
        return;

    while (current->next != NULL)
    {
        if (current->data == current->next->data)
        {
            next_next = current->next->next;
            free(current->next);
            current->next = next_next;
        }
        else
        {
            current = current->next;
        }
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