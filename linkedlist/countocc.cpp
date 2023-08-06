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
int countOcc(Node *&head, int value)
{
    if (head == NULL)
    {
        return 0;
    }
    if (head->data == value)
    {
        return 1 + countOcc(head->next, value);
    }
    return countOcc(head->next, value);
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
    cout << "The occurence of 2 is" << countOcc(head, 2);
}