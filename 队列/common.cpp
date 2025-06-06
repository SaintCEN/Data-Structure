#include <iostream>

using namespace std;

#define maxsize 100

typedef int ElemType;
typedef struct
{
    ElemType *base;
    int front;
    int rear;
} SqQueue; // 可作为单向队列或循环队列，这里视为循环队列

// 初始化
void InitQueue(SqQueue &q)
{
    q.base = new ElemType[maxsize];
    if (!q.base)
    {
        return;
    }
    q.front = 0;
    q.rear = 0;
}

// 长度
int QueueLength(SqQueue q)
{
    return (q.rear - q.front + maxsize) % maxsize;
}

// 判断是否为空
bool IsEmpty(SqQueue q)
{
    return q.front == q.rear;
}

// 判断是否已满
bool IsFull(SqQueue q)
{
    return (q.rear + 1) % maxsize == q.front;
}

// 入队
void EnQueue(SqQueue &q, ElemType e)
{
    if (IsFull(q))
    {
        return;
    }
    q.base[q.rear] = e;
    q.rear = (q.rear + 1) % maxsize;
}

// 出队
void DeQueue(SqQueue &q, ElemType &e)
{
    if (IsEmpty(q))
    {
        return;
    }
    e = q.base[q.front];
    q.front = (q.front + 1) % maxsize;
}

// 获取队头元素
ElemType GetHead(SqQueue q)
{
    if (!IsEmpty(q))
    {
        return q.base[q.front];
    }
    return -1;
}

// 打印
void PrintQueue(SqQueue q)
{
    if (IsEmpty(q))
    {
        return;
    }
    int i = q.front;
    while (i != q.rear)
    {
        cout << q.base[i] << " ";
        i = (i + 1) % maxsize;
    }
    cout << endl;
}

// 队列链式存储(带头结点)
// 节点定义
typedef struct QNode
{
    ElemType data;
    struct QNode *next;
} QNode;

// 链队列定义
typedef struct
{
    QNode *front;
    QNode *rear;
} LinkQueue;

// 初始化队列
void InitQueue(LinkQueue &Q)
{
    Q.front = new QNode;
    Q.rear = Q.front;
    Q.front->next = NULL;
}

// 判断为空
bool IsEmpty(LinkQueue Q)
{
    return (Q.front == Q.rear);
}

// 入队操作
void EnQueue(LinkQueue &Q, ElemType e)
{
    QNode *newNode = new QNode;
    newNode->data = e;
    newNode->next = NULL;
    Q.rear->next = newNode;
    Q.rear = newNode;
}

// 出队操作
void DeQueue(LinkQueue &Q, ElemType &e)
{
    if (IsEmpty(Q))
    {
        return;
    }

    QNode *temp = Q.front->next;
    e = temp->data;
    Q.front->next = temp->next;

    if (temp == Q.rear)
    {
        Q.rear = Q.front;
    }
    delete temp;
}

// 获取队头元素
ElemType GetFront(LinkQueue Q)
{
    if (IsEmpty(Q))
    {
        return -1;
    }
    return Q.front->next->data;
}