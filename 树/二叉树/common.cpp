#include <iostream>
#include <stack>
#include <queue>

using namespace std;

#define MAXSIZE 100

typedef int TElemType;

// 顺序存储结构（即层序遍历，空结点值可以为0）
typedef struct
{
    TElemType data[MAXSIZE];
} SqBiTree;

// 链式定义结点结构
typedef struct BiTNode
{
    TElemType data;
    BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

// 中序遍历（递归）
void InOrderTraverse(BiTree T)
{
    if (T)
    {
        InOrderTraverse(T->lchild);
        cout << T->data;
        InOrderTraverse(T->rchild);
    }
}

// 先序遍历（递归）
void PreOrderTraverse(BiTree T)
{
    if (T)
    {
        cout << T->data;
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);
    }
}

// 后序遍历（递归）
void PostOrderTraverse(BiTree T)
{
    if (T)
    {
        PostOrderTraverse(T->lchild);
        PostOrderTraverse(T->rchild);
        cout << T->data;
    }
}

// 中序遍历（非递归）
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

// 先序遍历（非递归）
void PreOrderTraverse_NonRecursive(BiTree T)
{
    if (!T)
        return;
    stack<BiTree> s;
    s.push(T);
    while (!s.empty())
    {
        BiTree q = s.top();
        s.pop();
        cout << q->data;
        if (q->rchild)
            s.push(q->rchild);
        if (q->lchild)
            s.push(q->lchild);
    }
}

// 后序遍历（非递归）
void PostOrderTraverse_NonRecursive(BiTree T)
{
    stack<BiTree> s;
    BiTree p = T;
    BiTree lastVisited = nullptr;
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
            if (q->rchild && lastVisited != q->rchild)
            {
                p = q->rchild;
            }
            else
            {
                cout << q->data;
                lastVisited = q;
                s.pop();
            }
        }
    }
}

// 层次遍历二叉树
void LevelOrderTraverse(BiTree T)
{
    if (!T)
        return;
    queue<BiTree> q;
    q.push(T);
    while (!q.empty())
    {
        BiTree node = q.front();
        q.pop();
        cout << node->data << ' ';
        if (node->lchild)
            q.push(node->lchild);
        if (node->rchild)
            q.push(node->rchild);
    }
}

// 根据前序输入创建二叉树，'#'表示空节点
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

// 根据中序输入创建二叉树，'#'表示空节点
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
        CreateBiTree(T->lchild);
        T = new BiTNode;
        T->data = ch;
        CreateBiTree(T->rchild);
    }
}
    // 根据后序输入创建二叉树，'#'表示空节点
    void CreateBiTree(BiTree & T)
    {
        char ch;
        cin >> ch;
        if (ch == '#')
        {
            T = nullptr;
        }
        else
        {
            CreateBiTree(T->lchild);
            CreateBiTree(T->rchild);
            T = new BiTNode;
            T->data = ch;
        }
    }
        // 计算二叉树的高度
        int Depth(BiTree T)
        {
            if (!T)
                return 0;
            int m = Depth(T->lchild);
            int n = Depth(T->rchild);
            return (m > n ? m + 1 : n + 1);
        }

        // 统计二叉树的节点个数
        int NodeCount(BiTree T)
        {
            if (!T)
                return 0;
            return NodeCount(T->lchild) + NodeCount(T->rchild) + 1;
        }

        // 线索二叉树的结点结构
        typedef struct BiThrNode
        {
            TElemType data;
            BiThrNode *lchild, *rchild;
            int LTag, RTag; // 0 表示指针，1 表示线索
        } BiThrNode, *BiThrTree;

        // 全局变量，用于中序线索化过程中的前驱节点
        BiThrNode *pre = nullptr;

        // 中序线索化（递归）
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
                if (pre && !pre->rchild)
                {
                    pre->RTag = 1;
                    pre->rchild = p;
                }
                else if (pre)
                {
                    pre->RTag = 0;
                }
                pre = p;
                InThreading(p->rchild);
            }
        }

        // 构建中序线索二叉树（带头结点）
        void CreateInOrderThread(BiThrTree & T)
        {
            BiThrTree head = new BiThrNode;
            head->LTag = 0;
            head->RTag = 1;
            head->rchild = head;
            pre = head;
            head->lchild = T;
            InThreading(T);
            pre->rchild = head;
            pre->RTag = 1;
            T = head;
        }

        // 遍历中序线索二叉树（非递归）
        void InOrderTraverse_Thr(BiThrTree T)
        {
            BiThrTree p = T->lchild;
            while (p != T)
            {
                while (p->LTag == 0)
                    p = p->lchild;
                cout << p->data;
                while (p->RTag == 1 && p->rchild != T)
                {
                    p = p->rchild;
                    cout << p->data;
                }
                p = p->rchild;
            }
        }