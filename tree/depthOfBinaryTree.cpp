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

int maxDepth(Node *root)
{
    if (root == NULL)
        return 0;
    int lh = maxDepth(root->left);
    int rh = maxDepth(root->right);
    return 1 + max(lh, rh);
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
    int depth = maxDepth(root);
    cout << "The depth is " << depth;
    return 0;
}