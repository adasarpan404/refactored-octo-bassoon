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

void insertathead(Node *&head, int val)
{
    Node *node = new Node(val);
    node->next = head;
    head = node;
}

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

void deleteathead(Node *&head)
{
    Node *temp = head;
    head = head->next;
    delete temp;
}

void deleteatend(Node *&head)
{
    Node *p = head;
    Node *temp;
    while (p->next->next != NULL)
    {
        p = p->next;
    }
    temp = p->next;
    p->next = NULL;
    delete temp;
}
int main()
{
    Node *Head = NULL;
    cout << "After insertion at head: " << endl;
    insertattail(Head, 56);
    insertathead(Head, 44);
    insertathead(Head, 42);
    insertathead(Head, 40);
    insertattail(Head, 50);
    print(Head);
    cout << "Deletion at the head" << endl;
    deleteathead(Head);
    print(Head);
    cout << "Deletion at the end" << endl;
    deleteatend(Head);
    print(Head);
}