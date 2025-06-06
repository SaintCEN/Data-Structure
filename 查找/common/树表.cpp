#include <iostream>
using namespace std;

typedef int KeyType;
typedef char InfoType;

typedef struct
{
    KeyType key;
    InfoType otherinfo;
} ElemType;

typedef struct BSTNode
{
    ElemType data;
    struct BSTNode *lchild, *rchild;
} BSTNode, *BSTree;

BSTree SearchBST(BSTree T, KeyType key)
{
    if (!T || key == T->data.key)
    {
        return T;
    }
    else if (key < T->data.key)
    {
        return SearchBST(T->lchild, key);
    }
    else
    {
        return SearchBST(T->rchild, key);
    }
}

void InsertBST(BSTree &T, ElemType e)
{
    if (!T)
    {
        BSTNode *S = new BSTNode;
        S->data = e;
        S->lchild = S->rchild = nullptr;
        T = S;
    }
    else if (e.key < T->data.key)
    {
        InsertBST(T->lchild, e);
    }
    else if (e.key > T->data.key)
    {
        InsertBST(T->rchild, e);
    }
}

void CreateBST(BSTree &T)
{
    ElemType e;
    T = nullptr;
    cin >> e.key;
    while (e.key != -1)
    {
        InsertBST(T, e);
        cin >> e.key;
    }
}

void DeleteBST(BSTree &T, KeyType key)
{
    BSTree p = T;    // 当前节点指针
    BSTree f = NULL; // 父节点指针

    // 查找删除节点
    while (p)
    {
        if (p->data.key == key)
            break;
        f = p;
        if (p->data.key > key)
            p = p->lchild;
        else
            p = p->rchild;
    }
    if (!p)
        return;

    BSTree q = p; // 辅助指针 q 指向待删除节点

    // Case 1: 节点 p 是叶子节点或仅有一个子树
    if (!p->lchild)
    { // 左子树为空，用右子树替换
        if (!f)
            T = p->rchild; // p 是根节点
        else if (f->lchild == p)
            f->lchild = p->rchild;
        else
            f->rchild = p->rchild;
        free(q);
    }
    else if (!p->rchild)
    { // 右子树为空，用左子树替换
        if (!f)
            T = p->lchild; // p 是根节点
        else if (f->lchild == p)
            f->lchild = p->lchild;
        else
            f->rchild = p->lchild;
        free(q);
    }
    else
    {
        // Case 2: 节点 p 有两个子树，找左子树的最右节点（前驱）
        BSTree s = p->lchild;
        BSTree parent_s = p; // s 的父节点
        while (s->rchild)
        {
            parent_s = s;
            s = s->rchild;
        }

        // 用前驱 s 替换 p 的值
        p->data = s->data;

        // 删除前驱节点 s（此时 s 至多有一个左子树）
        if (parent_s == p)
            parent_s->lchild = s->lchild;
        else
            parent_s->rchild = s->lchild;
        free(s);
    }
}


