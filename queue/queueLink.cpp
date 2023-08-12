#include <bits/stdc++.h>

using namespace std;

class Queue
{
public:
    int data;
    Queue *next;
    Queue(int value)
    {
        data = value;
        next = NULL;
    }
};

void enqueue(Queue *&head, int value)
{
    Queue *q = new Queue(value);
    if (head == NULL)
    {
        head = q;
        return;
    }

    Queue *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = q;
}

void dequeue(Queue *&head)
{
    if (isEmpty(head))
    {
        cout << "Underflow";
    }
    Queue *q = head;
    head = head->next;
    delete q;
}

int front(Queue *&head)
{
    return head->data;
}

bool isEmpty(Queue *&head)
{
    return !head;
}

int main()
{
    Queue *head = NULL;
    enqueue(head, 1);
    enqueue(head, 2);
    enqueue(head, 3);
    cout << front(head) << endl;
    dequeue(head);
    cout << front(head) << endl;
}