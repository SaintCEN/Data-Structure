#include <iostream>
using namespace std;

typedef int ElemType;
typedef struct Node
{
    ElemType data;
    struct Node *next;
} Node, *LinkList;

// 初始化(带头结点)
void InitList(LinkList &L)
{
    L = (Node *)malloc(sizeof(Node));
    L->next = NULL;
    // 若不带头结点，直接L = NULL;
}

// 求表长
int Length(LinkList L)
{
    int len = 0;
    Node *p = L;
    while (p->next != NULL)
    {
        p = p->next;
        len++;
    }
    return len;
}

// 取值
void GetElem(LinkList L, int i, ElemType &e)
{
    Node *p = L;
    int j = 0;
    while (p && j < i)
    {
        p = p->next;
        j++;
    }
    if (!p || j > i)
        return;
    e = p->data;
}

// 查找
Node *LocateNode(LinkList L, ElemType e)
{
    Node *p = L->next;
    while (p && p->data != e)
    {
        p = p->next;
    }
    return p;
}

// 插入
void insertNode(LinkList &L, int i, ElemType e)
{
    Node *p = L;
    int j = 0;
    while (p && j < i - 1)
    {
        p = p->next;
        j++;
    }
    if (!p)
        return;
    Node *s = new Node;
    s->data = e;
    s->next = p->next;
    p->next = s;
}

// 删除
void deleteNode(LinkList &L, int i)
{
    Node *p = L;
    int j = 0;
    while (p && j < i - 1)
    {
        p = p->next;
        j++;
    }
    if (!p->next || !p)
        return;
    Node *q = p->next;
    p->next = q->next;
    delete q;
}

// 头插法
void createList_H(LinkList &L, int n)
{
    L = new Node; // L固定为头结点
    L->next = NULL;
    for (int i = 0; i < n; i++)
    {
        Node *p = new Node;
        cin >> p->data;
        p->next = L->next;
        L->next = p;
    }
}

// 尾插法
void createList_R(Node *&L, int n)
{
    L = new Node; // L为固定头结点
    L->next = NULL;
    Node *r = L;
    for (int i = 0; i < n; i++)
    {
        Node *p = new Node;
        cin >> p->data;
        p->next = NULL;
        r->next = p;
        r = p;
    }
}

// 遍历
void printlist(LinkList L)
{
    Node *p = L;
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}