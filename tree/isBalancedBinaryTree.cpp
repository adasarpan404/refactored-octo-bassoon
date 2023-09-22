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
int dfsHeight(Node *root)
{
    if (root == NULL)
        return 0;

    int lh = dfsHeight(root->left);
    if (lh == -1)
        return -1;
    int rh = dfsHeight(root->right);
    if (rh == -1)
        return -1;
    if (abs(lh - rh) > 1)
        return 1;
    return 1 + max(lh, rh);
}

bool checkBalanced(Node *root)
{
    return dfsHeight(root) != -1;
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
    bool isBalanced = checkBalanced(root);
    cout << (isBalanced ? "The Binary Tree is Balanced" : "The Binary Tree is not balanced");
    return 0;
}