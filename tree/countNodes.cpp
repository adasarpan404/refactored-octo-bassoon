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

int findHeightLeft(Node *node)
{
    int hght = 0;
    while (node)
    {
        hght++;
        node = node->left;
    }
    return hght;
}

int findHeightRight(Node *node)
{
    int hght = 0;
    while (node)
    {
        hght++;
        node = node->right;
    }
    return hght;
}

int countNodes(Node *root)
{
    if (root == NULL)
        return 0;
    int lh = findHeightLeft(root);
    int rh = findHeightRight(root);

    if (lh == rh)
        return (1 << lh) - 1;

    return 1 + countNodes(root->left) + countNodes(root->right);
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
    int result = countNodes(root);
    cout << result << endl;
    return 0;
}