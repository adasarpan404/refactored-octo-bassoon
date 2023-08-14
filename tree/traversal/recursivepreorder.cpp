#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};

void preOrderTraversal(Node *root, vector<int> &preOrder)
{
    if (root == NULL)
        return;

    preOrder.push_back(root->data);
    preOrderTraversal(root->left, preOrder);
    preOrderTraversal(root->right, preOrder);
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
    vector<int> preOrder;
    preOrderTraversal(root, preOrder);
    cout << "The PreOrder Traversal is : ";
    for (int i = 0; i < preOrder.size(); i++)
    {
        cout << preOrder[i] << " ";
    }
    return 0;
}