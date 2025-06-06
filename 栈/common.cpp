#include <iostream>
using namespace std;

#define MAXSIZE 100

typedef int Elemtype;

// 顺序存储
typedef struct
{
    Elemtype *top;
    Elemtype *base;
    int size;
} SqStack;

void Init(SqStack &s)
{
    s.base = new Elemtype[MAXSIZE];
    s.top = s.base;
    s.size = MAXSIZE;
}

bool IsEmpty(SqStack s)
{
    return s.base == s.top;
}

bool IsFull(SqStack s)
{
    return (s.top - s.base) == s.size;
}

void Push(SqStack &s, Elemtype e)
{
    if (IsFull(s))
    {
        return;
    }
    *s.top = e;
    s.top++;
}

Elemtype Pop(SqStack &s, Elemtype &e)
{
    if (IsEmpty(s))
    {
        return;
    }
    s.top--;
    e = *s.top;
}

void Print(SqStack &s)
{
    if (IsEmpty(s))
    {
        return;
    }
    for (Elemtype *p = s.base; p != s.top; p++)
    {
        cout << *p << " ";
    }
    cout << endl;
}

Elemtype GetTop(SqStack s)
{
    if (IsEmpty(s))
    {
        return;
    }
    Elemtype e = *s.top;
    return e;
}

// 链式存储
typedef struct Linknode
{
    Elemtype data;
    struct Linknode *next;
} Linknode, *LiStack;

void Init(LiStack &s)
{
    s = NULL;
}

void Push(LiStack &s, Elemtype e)
{
    LiStack p = new Linknode;
    p->data = e;
    p->next = s;
    s = p;
}

void Pop(LiStack &s, Elemtype &e)
{
    if (s == NULL)
        return;
    e = s->data;
    LiStack p = s;
    s = s->next;
    delete p;
}

Elemtype GetTop(LiStack s)
{
    if (s != NULL)
        return s->data;
    return -1;
}

// 共享存储
typedef struct
{
    Elemtype *base;
    Elemtype *top1;
    Elemtype *top2;
    int capacity;
} SharedStack;