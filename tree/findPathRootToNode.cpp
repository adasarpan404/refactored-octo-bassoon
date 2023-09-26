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

bool getPath(Node *root, vector<int> &arr, int path)
{
    if (!root)
        return false;
    arr.push_back(root->data);
    if (root->data == path)
        return true;
    if (getPath(root->left, arr, path) || getPath(root->right, arr, path))
    {
        return true;
    }
    arr.pop_back();
    return false;
}

vector<int> findPathToNode(Node *root, int path)
{
    vector<int> arr;
    if (root == NULL)
        return arr;
    getPath(root, arr, path);
    return arr;
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
    vector<int> result = findPathToNode(root, 8);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    return 0;
}