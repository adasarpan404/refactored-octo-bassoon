// This program is for finding the nth element in linkedlist.

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

void insertathead(Node *&head, int value)
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

int getNth(Node *&head, int position)
{
    Node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        if (count == position)
        {
            return temp->data;
        }
        count++;
        temp = temp->next;
    }
    return -1;
}

int main()
{
    Node *head = NULL;
    int values[] = {5, 4, 3, 2, 1};
    int numValues = sizeof(values) / sizeof(values[0]);

    for (int i = 0; i < numValues; i++)
    {
        insertathead(head, values[i]);
    }
    cout << getNth(head, 1) << endl;
    cout << getNth(head, 3) << endl;
    return 0;
}