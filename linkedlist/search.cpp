// This program is for searching the element in linkedlist
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

void insertattail(Node *&head, int val)
{
    Node *node = new Node(val);
    if (head == NULL)
    {
        head = node;
        return;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = node;
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

bool search(Node *&head, int value)
{
    Node *current = head;
    while (current != NULL)
    {
        if (current->data == value)
        {
            return true;
        }
        current = current->next;
    }
    return false;
}
int main()
{
    Node *Head = NULL;
    for (int i = 0; i < 10; i++)
    {
        insertattail(Head, i);
        insertattail(Head, (21 - i));
    }
    print(Head);
    search(Head, 23) ? cout << "Yes \n" : cout << "No \n";
    search(Head, 2) ? cout << "Yes \n" : cout << "No \n";
}