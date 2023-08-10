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
    unordered_set<int> seen;
    Node *current = head;
    Node *prev = NULL;
    while (current)
    {
        if (seen.find(current->data) != seen.end())
        {
            prev->next = current->next;
            free(current);
        }
        else
        {
            seen.insert(current->data);
            prev = current;
        }
        current = current->next;
    }
}

int main()
{
    Node *head = NULL;
    int values[] = {5, 4, 4, 5, 3, 6, 2, 9, 1, 2};
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
    return 0;
}