#include <iostream>
#include <string>

using namespace std;

typedef struct TreeNode
{
    char val;
    TreeNode *lchild, *rchild;
} TreeNode;

int GetHeight(TreeNode *T)
{
    if (!T)
    {
        return 0;
    }
    int LHeight = GetHeight(T->lchild);
    int RHeight = GetHeight(T->rchild);
    return max(LHeight, RHeight) + 1;
}

TreeNode *Build(string preorder, string inorder, int pre_begin, int pre_end, int in_begin, int in_end)
{
    if (pre_begin > pre_end || in_begin > in_end)
    {
        return NULL;
    }

    TreeNode *Tree = new TreeNode;
    Tree->val = preorder[pre_begin];
    Tree->lchild = NULL;
    Tree->rchild = NULL;

    int pos = inorder.find(Tree->val);
    int LSize = pos - in_begin;

    Tree->lchild = Build(preorder, inorder, pre_begin + 1, pre_begin + LSize, in_begin, pos - 1);
    Tree->rchild = Build(preorder, inorder, pre_begin + LSize + 1, pre_end, pos + 1, in_end);

    return Tree;
}

int main()
{
    int n;
    cin >> n;
    cin.ignore();
    string T1, T2;
    getline(cin, T1);
    getline(cin, T2);

    TreeNode *Tree = Build(T1, T2, 0, T1.length() - 1, 0, T2.length() - 1);
    cout << GetHeight(Tree) << endl;

    return 0;
}