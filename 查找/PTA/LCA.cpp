#include <bits/stdc++.h>
using namespace std;

typedef struct Node
{
    int key;
    Node *left, *right;
} Node;

Node *buildBST(const vector<int> &pre, int &idx, int minv, int maxv)
{
    if (idx >= (int)pre.size())
        return nullptr;
    int val = pre[idx];
    if (val < minv || val > maxv)
        return nullptr;
    Node *root = new Node;
    root->key = val;
    root->left = root->right = nullptr;
    idx++;
    root->left = buildBST(pre, idx, minv, val);
    root->right = buildBST(pre, idx, val, maxv);
    return root;
}

bool exists(Node *root, int key)
{
    while (root)
    {
        if (key == root->key)
            return true;
        root = (key < root->key ? root->left : root->right);
    }
    return false;
}

Node *LCA(Node *root, int u, int v)
{
    while (root)
    {
        if (u < root->key && v < root->key)
            root = root->left;
        else if (u > root->key && v > root->key)
            root = root->right;
        else
            return root;
    }
    return nullptr;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int M, N;
    cin >> M >> N;
    vector<int> pre(N);
    for (int i = 0; i < N; i++)
        cin >> pre[i];

    int idx = 0;
    Node *root = buildBST(pre, idx, INT_MIN, INT_MAX);

    while (M--)
    {
        int u, v;
        cin >> u >> v;
        bool fu = exists(root, u);
        bool fv = exists(root, v);
        if (!fu && !fv)
        {
            cout << "ERROR: " << u << " and " << v << " are not found." << '\n';
        }
        else if (!fu)
        {
            cout << "ERROR: " << u << " is not found." << '\n';
        }
        else if (!fv)
        {
            cout << "ERROR: " << v << " is not found." << '\n';
        }
        else
        {
            Node *anc = LCA(root, u, v);
            if (anc->key == u)
            {
                cout << u << " is an ancestor of " << v << "." << '\n';
            }
            else if (anc->key == v)
            {
                cout << v << " is an ancestor of " << u << "." << '\n';
            }
            else
            {
                cout << "LCA of " << u << " and " << v << " is " << anc->key << "." << '\n';
            }
        }
    }
    return 0;
}
