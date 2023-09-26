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

void rightSideRecursion(Node *root, int level, vector<int> &res)
{
    if (root == NULL)
    {
        return;
    }
    if (res.size() == level)
        res.push_back(root->data);
    rightSideRecursion(root->right, level + 1, res);
    rightSideRecursion(root->left, level + 1, res);
}

void leftSideRecursion(Node *root, int level, vector<int> &res)
{
    if (root == NULL)
    {
        return;
    }
    if (res.size() == level)
        res.push_back(root->data);
    leftSideRecursion(root->left, level + 1, res);
    leftSideRecursion(root->right, level + 1, res);
}

vector<int> rightView(Node *root)
{
    vector<int> res;
    rightSideRecursion(root, 0, res);
    return res;
}

vector<int> leftView(Node *root)
{
    vector<int> res;
    leftSideRecursion(root, 0, res);
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
    vector<int> result = rightView(root);
    cout << "Right Side View of Binary Tree" << endl;
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    result = leftView(root);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }

    return 0;
}