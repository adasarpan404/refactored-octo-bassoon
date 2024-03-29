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

bool isSymmetricHelp(Node *left, Node *right)
{
    if (left == NULL || right == NULL)
    {
        return left == right;
    }
    if (left->data != right->data)
        return false;
    return isSymmetricHelp(left->left, right->right) && isSymmetricHelp(left->right, right->left);
}

bool isSymmetric(Node *root)
{
    return root == NULL || isSymmetricHelp(root->left, root->right);
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
    root->left->left->right->right = new Node(10);
    root->right->right->left = new Node(9);
    root->left->right->left = new Node(11);
    bool result = isSymmetric(root);
    cout << (result ? "Tree is Symmetric" : "Tree is not symmetric");
    return 0;
}