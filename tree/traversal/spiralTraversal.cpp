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

vector<vector<int>> spiralTraversal(Node *root)
{
    vector<vector<int>> ans;
    if (!root)
        return ans;
    queue<Node *> q;
    q.push(root);
    bool leftToRight = true;
    while (!q.empty())
    {
        int size = q.size();
        vector<int> level(size);
        for (int i = 0; i < size; i++)
        {
            Node *node = q.front();
            q.pop();
            int index = leftToRight ? i : size - i - 1;

            level[index] = node->data;
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
        leftToRight = !leftToRight;
        ans.push_back(level);
    }
    return ans;
}

void print(vector<vector<int>> result)
{
    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
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
    vector<vector<int>> result = spiralTraversal(root);
    print(result);
    return 0;
}