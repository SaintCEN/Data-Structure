#include<bits/stdc++.h>
using namespace std;

#define maxsize 100
typedef int ElemType;

typedef struct {
    ElemType *base;
    int front;
    int rear;
} SqQueue;

// 初始化
void InitQueue(SqQueue &q) {
    q.base = new ElemType[maxsize];
    if (!q.base) {
        return;
    }
    q.front = 0;
    q.rear = 0;
}

// 长度
int QueueLength(SqQueue q) {
    return (q.rear - q.front + maxsize) % maxsize;
}

// 判断是否为空
bool IsEmpty(SqQueue q) {
    return q.front == q.rear;
}

// 判断是否已满
bool IsFull(SqQueue q) {
    return (q.rear + 1) % maxsize == q.front;
}

// 入队
void EnQueue(SqQueue &q, ElemType e) {
    if (IsFull(q)) {
        return;
    }
    q.base[q.rear] = e;
    q.rear = (q.rear + 1) % maxsize;
}

// 出队
void DeQueue(SqQueue &q, ElemType &e) {
    if (IsEmpty(q)) {
        return;
    }
    e = q.base[q.front];
    q.front = (q.front + 1) % maxsize;
}

// 获取队头元素
ElemType GetHead(SqQueue q) {
    if (!IsEmpty(q)) {
        return q.base[q.front];
    }
    return -1; 
}

// 打印
void PrintQueue(SqQueue q) {
    if (IsEmpty(q)) {
        return;
    }
    int i = q.front;
    while (i != q.rear) {
        cout << q.base[i] << " ";
        i = (i + 1) % maxsize;
    }
    cout << endl;
}

// 销毁
void DestroyQueue(SqQueue &q) {
    delete[] q.base;
    q.base = nullptr;
    q.front = q.rear = 0;
}

int main() {
    SqQueue q;
    InitQueue(q);
    EnQueue(q, 10);
    EnQueue(q, 20);
    EnQueue(q, 30);
    ElemType headElement = GetHead(q);
    cout << headElement << endl;
    ElemType dequeuedElement;
    DeQueue(q, dequeuedElement);
    cout << dequeuedElement << endl; 
    PrintQueue(q); 
    DestroyQueue(q);
    return 0;
}
/*
#include<queue>
queue<int> q1;
q1.push(2);
q1.push(1);
queue<int> q2(q1);
q1.pop();
cout << q1.size() << " " << q2.size() << std::endl;    // 1 2
cout << q1.front() << " " << q2.front() << std::endl;  // 1 2
q1.pop();
cout << q1.empty() << " " << q2.empty() << std::endl;  // 1 0
*/