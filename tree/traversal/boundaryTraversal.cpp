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

bool isLeaf(Node *root)
{
    return !root->left && !root->right;
}

void addLeftBounday(Node *root, vector<int> &res)
{
    Node *curr = root->left;
    while (curr)
    {
        if (!isLeaf(curr))
            res.push_back(curr->data);
        if (curr->left)
            curr = curr->left;
        else
            curr = curr->right;
    }
}

void addRightBoundary(Node *root, vector<int> &res)
{
    Node *curr = root->right;
    vector<int> tmp;
    while (curr)
    {
        if (!isLeaf(curr))
            tmp.push_back(curr->data);
        if (curr->right)
            curr = curr->right;
        else
            curr = curr->left;
    }
    for (int i = tmp.size() - 1; i >= 0; --i)
    {
        res.push_back(tmp[i]);
    }
}

void addLeaves(Node *root, vector<int> &res)
{
    if (isLeaf(root))
    {
        res.push_back(root->data);
        return;
    }
    if (root->left)
        addLeaves(root->left, res);
    if (root->right)
        addLeaves(root->right, res);
}

vector<int> boundaryTraversal(Node *root)
{
    vector<int> res;
    if (!root)
        return res;
    if (!isLeaf(root))
        res.push_back(root->data);
    addLeftBounday(root, res);
    addLeaves(root, res);
    addRightBoundary(root, res);
    return res;
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
    vector<int> result = boundaryTraversal(root);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    return 0;
}