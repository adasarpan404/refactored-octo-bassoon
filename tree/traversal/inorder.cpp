#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;
    Node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};

vector<int> inOrderTraversal(Node *root)
{
    vector<int> inorder;
    stack<Node *> s;
    while (true)
    {
        if (root != NULL)
        {
            s.push(root);
            root = root->left;
        }
        else
        {
            if (s.empty())
                break;
            root = s.top();
            inorder.push_back(root->data);
            s.pop();
            root = root->right;
        }
    }
    return inorder;
}

int main()
{
    Node *root = new Node(0);
    root->left = new Node(1);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->left->left->right = new Node(7);
    root->left->left->right->left = new Node(8);
    root->right->right->left = new Node(9);
    vector<int> inorder = inOrderTraversal(root);
    cout << "The InOrder Traversal is : ";
    for (int i = 0; i < inorder.size(); i++)
    {
        cout << inorder[i] << " ";
    }

    return 0;
}