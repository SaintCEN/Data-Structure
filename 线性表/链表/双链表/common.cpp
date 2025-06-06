#include <iostream>
using namespace std;

typedef int Elemtype;

// 定义双链表节点
typedef struct DNode
{
    Elemtype data;
    struct DNode *prior;
    struct DNode *next;
} DNode, *DList;

// 初始化双链表
DList initList()
{
    DNode *head = new DNode();
    head->prior = nullptr;
    head->next = nullptr;
    return head;
}

// 创建双链表
void createList(DList &L, int n)
{
    DNode *p = L;
    for (int i = 0; i < n; i++)
    {
        DNode *newNode = new DNode;
        cin >> newNode->data;
        newNode->prior = p;
        newNode->next = nullptr;
        p->next = newNode;
        p = newNode;
    }
}

// 插入操作
void insertNode(DList &L, int pos, Elemtype e)
{
    DNode *p = L;
    int i = 0;
    while (p && i < pos)
    {
        p = p->next;
        i++;
    }
    if (!p)
    {
        return;
    }
    DNode *newNode = new DNode;
    newNode->data = e;
    newNode->next = p->next;
    newNode->prior = p;
    if (p->next)
    {
        p->next->prior = newNode;
    }
    p->next = newNode;
}

// 删除操作
void deleteNode(DList &L, int pos)
{
    DNode *p = L->next;
    int i = 0;
    while (p && i < pos)
    {
        p = p->next;
        i++;
    }
    if (!p)
    {
        return;
    }
    if (p->prior)
    {
        p->prior->next = p->next;
    }
    if (p->next)
    {
        p->next->prior = p->prior;
    }
    delete p;
}

// 正向遍历
void traverseForward(DList L)
{
    DNode *p = L->next;
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

// 反向遍历
void traverseBackward(DList L)
{
    DNode *p = L;
    while (p->next)
    {
        p = p->next;
    }
    while (p != L)
    {
        cout << p->data << " ";
        p = p->prior;
    }
    cout << endl;
}