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

vector<int> topView(Node *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;
    map<int, int> mpp;
    queue<pair<Node *, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        Node *node = it.first;
        int line = it.second;
        if (mpp.find(line) == mpp.end())
            mpp[line] = node->data;
        if (node->left)
            q.push({node->left, line - 1});
        if (node->right)
            q.push({node->right, line + 1});
    }
    for (auto it : mpp)
    {
        ans.push_back(it.second);
    }

    return ans;
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
    vector<int> result = topView(root);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    return 0;
}