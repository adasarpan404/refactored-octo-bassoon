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

bool checkTreeIsIdenticalOrNot(Node *root1, Node *root2)
{
    if (root1 == NULL && root2 == NULL)
    {
        return true;
    }
    return (root1->data == root2->data) && checkTreeIsIdenticalOrNot(root1->left, root2->left) && checkTreeIsIdenticalOrNot(root2->right, root2->right);
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

    Node *root1 = new Node(0);
    root1->left = new Node(1);
    root1->right = new Node(2);
    root1->left->left = new Node(3);
    root1->left->right = new Node(4);
    root1->right->left = new Node(5);
    root1->right->right = new Node(6);
    root1->left->left->right = new Node(7);
    root1->left->left->right->left = new Node(8);
    root1->right->right->left = new Node(9);
    int isIdentical = checkTreeIsIdenticalOrNot(root, root1);
    cout << (isIdentical ? "The tree is identical" : "The tree is not identical");
    return 0;
}