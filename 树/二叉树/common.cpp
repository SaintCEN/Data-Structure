#include <iostream>
#include <stack>
using namespace std;
#define MAXSIZE 100
typedef char TElemType;

// 顺序存储结构
typedef TElemType SqBiTree[MAXSIZE];
SqBiTree bt;
// 链式存储结构
typedef struct BiTNode
{
    TElemType data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

// 中序遍历递归算法
void InOrderTraverse(BiTree T)
{
    if (T)
    {
        InOrderTraverse(T->lchild);
        cout << T->data;
        InOrderTraverse(T->rchild);
    }
}

// 先序遍历递归算法
void PreOrderTraverse(BiTree T)
{
    if (T)
    {
        cout << T->data;
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);
    }
}
// 后序遍历递归算法
void PostOrderTraverse(BiTree T)
{
    if (T)
    {
        PostOrderTraverse(T->lchild);
        PostOrderTraverse(T->rchild);
        cout << T->data;
    }
}
// 中序遍历非递归算法
void InOrderTraverse_NonRecursive(BiTree T)
{
    stack<BiTree> s;
    BiTree p = T;
    while (p || !s.empty())
    {
        if (p)
        {
            s.push(p);
            p = p->lchild;
        }
        else
        {
            BiTree q = s.top();
            s.pop();
            cout << q->data;
            p = q->rchild;
        }
    }
}

// 创建二叉树（前序）
void CreateBiTree(BiTree &T)
{
    char ch;
    cin >> ch;
    if (ch == '#')
    {
        T = nullptr;
    }
    else
    {
        T = new BiTNode;
        T->data = ch;
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
    }
}

// 复制二叉树
void CopyBiTree(BiTree T, BiTree &NewT)
{ // 修正参数语法
    if (!T)
    {
        NewT = nullptr;
        return;
    }
    NewT = new BiTNode;
    NewT->data = T->data;
    CopyBiTree(T->lchild, NewT->lchild);
    CopyBiTree(T->rchild, NewT->rchild);
}

// 求二叉树高度
int Depth(BiTree T)
{
    if (!T)
        return 0;
    int m = Depth(T->lchild);
    int n = Depth(T->rchild);
    if (m > n)
    {
        return (m + 1);
    }
    else
    {
        return (n + 1);
    }
}

// 统计二叉树节点个数
int NodeCount(BiTree T)
{
    if (!T)
        return 0;
    return NodeCount(T->lchild) + NodeCount(T->rchild) + 1;
}

// 线索二叉树存储结构
typedef struct BiThrNode
{
    TElemType data;
    struct BiThrNode *lchild, *rchild; // 左右孩子指针
    int LTag, RTag;                    // 左右标签，0表示孩子，1表示前驱/后继
} BiThrNode, *BiThrTree;

// 构造中序线索二叉树
BiThrNode *pre = NULL;
void InThreading(BiThrTree p)
{
    if (p)
    {
        InThreading(p->lchild);
        if (!p->lchild)
        {
            p->LTag = 1;
            p->lchild = pre;
        }
        else
        {
            p->LTag = 0;
        }
        if (!pre->rchild)
        {
            pre->RTag = 1;
            pre->rchild = p;
        }
        else
        {
            pre->RTag = 0;
        }
        pre = p;
        InThreading(p->rchild);
    }
}

// 遍历中序线索二叉树
void InOrderTraverse_Thr(BiThrTree T)
{
    BiThrTree p = T->lchild; // 带头结点
    while (p != T)
    {
        while (p->LTag == 0)
        {
            p = p->lchild;
        }
        cout << p->data;
        while (p->RTag == 1 && p->rchild != T)
        {
            p = p->rchild;
            cout << p->data;
        }
        p = p->rchild;
    }
}