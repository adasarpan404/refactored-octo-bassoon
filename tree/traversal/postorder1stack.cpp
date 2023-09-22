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
vector<int> postOrderTraversal(Node *root)
{
    vector<int> postOrder;
    stack<Node *> st;
    Node *curr = root;
    Node *lastVisited = NULL;
    while (curr || !st.empty())
    {
        if (curr)
        {
            st.push(curr);
            curr = curr->right;
        }
        else
        {
            Node *peeknode = st.top();
            if (peeknode->right && lastVisited != peeknode->right)
            {
                curr = peeknode->right;
            }
            else
            {
                postOrder.push_back(peeknode->data);
                lastVisited = peeknode;
                st.pop();
            }
        }
    }
    return postOrder;
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
    vector<int> postOrder = postOrderTraversal(root);
    cout << "The Post Order Traversal is : ";
    for (int i = 0; i < postOrder.size(); i++)
    {
        cout << postOrder[i] << " ";
    }
    return 0;
}