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
    while (temp)
    {
        cout << temp->data << " ->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

bool isPalindrome(Node *&head)
{
    Node *temp = head;
    // this will be used to put value in stack.
    stack<int> st;
    while (temp)
    {
        st.push(temp->data);
        temp = temp->next;
    }
    while (head)
    {
        int val = st.top();
        st.pop();
        if (head->data != val)
        {
            return false;
        }
        head = head->next;
    }
    return true;
}
int main()
{
    Node *head = NULL;
    insertathead(head, 1);
    insertathead(head, 2);
    insertathead(head, 2);
    insertathead(head, 1);
    print(head);
    cout << (isPalindrome(head) ? "It is palindrome" : "It is not palindrome");
}