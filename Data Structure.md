# Data Structure

### 线性表

```c++
#include<bits/stdc++.h>
using namespace std;

#define MAXSIZE 100

typedef int ElemType;
typedef struct {
    ElemType *elem;
    int length;
} Sqlist;

//初始化
void InitList(Sqlist &L) {
    L.elem = new ElemType[MAXSIZE];
    if (!L.elem) return;
    L.length = 0;
}
//取值
void GetElem(Sqlist L, int i, ElemType &e) {
    if (i < 1 || i > L.length) return;
    e = L.elem[i - 1];
}
//定位
int LocateElem(Sqlist L, ElemType e) {
    for (int i = 0; i < L.length; i++) {
        if (L.elem[i] == e) return i + 1;
    }
    return 0;
}
//插入
void InsertElem(Sqlist &L, int i, ElemType e) {
    if (i < 1 || i > L.length + 1) return;
    if (L.length == MAXSIZE) return;
    for (int j = L.length - 1; j >= i - 1; j--) {
        L.elem[j + 1] = L.elem[j];
    }
    L.elem[i - 1] = e;
    L.length++;
}
//删除
void DeleteElem(Sqlist &L, int i) {
    if (i < 1 || i > L.length) return;
    for (int j = i; j < L.length; j++) {
        L.elem[j - 1] = L.elem[j];
    }
    L.length--;
}
//删除k个
void DeleteKElem(Sqlist &L,int i,int k){
    if(i<1||k<0||i+k>a.length+1){
        return;
    }
    else{
        if(k==0) return;
        for(j=i+k;j<=a.length;j++){
            a.elem[j-k] = a.elem[j];
        }
        a.length -= k;
    }
}
```

### 单链表

```c++
#include<bits/stdc++.h>
using namespace std;

typedef int ElemType;
typedef struct Node {
    int data;
    struct Node* next;
} Node;

//初始化
void InitList(Node* &L) {
    L = new Node;
    L->next = NULL;
}

//取值
void GetElem(Node* L, int i, ElemType &e) {
    Node* p = L->next;
    int j = 1;
    while (p && j < i) {
        p = p->next;
        j++;
    }
    if (!p || j > i) return;
    e = p->data;
}

//查找
Node* LocateNode(Node* L, ElemType e) {
    Node* p = L->next;
    while (p && p->data != e) {
        p = p->next;
    }
    return p;
}

//插入
void insertNode(Node* &L, int i, ElemType e) {
    Node* p = L;
    int j = 0;
    while (p && j < i - 1) {
        p = p->next;
        j++;
    }
    if (!p || j > i - 1) return;
    Node* s = new Node;
    s->data = e;
    s->next = p->next;
    p->next = s;
}

//删除
void deleteNode(Node* &L, int i) {
    Node* p = L;
    int j = 0;
    while (p->next && j < i - 1) {
        p = p->next;
        j++;
    }
    if (!p->next || j > i - 1) return;
    Node* q = p->next;
    p->next = q->next;
    delete q;
}

//头插法
void createList_H(Node* &L, int n) {
    L = new Node;
    L->next = NULL;
    for (int i = 0; i < n; i++) {
        Node* p = new Node;
        cin >> p->data;
        p->next = L->next;
        L->next = p;
    }
}

//尾插法
void createList_R(Node* &L, int n) {
    L = new Node;
    L->next = NULL;
    Node* r = L;
    for (int i = 0; i < n; i++) {
        Node* p = new Node;
        cin >> p->data;
        p->next = NULL;
        r->next = p;
        r = p;
    }
}

//遍历
void printlist(Node* L)
{
     Node *p = L;
     while (p) {
           printf("%d ", p->data);
           p = p->next;
     }
     printf("\n");
}
```

### 双链表

```c++
#include <iostream>
using namespace std;

typedef int Elemtype;

// 定义双链表节点
typedef struct DulNode {
    Elemtype data;
    struct DulNode* prior;
    struct DulNode* next;
} DulNode;

// 初始化双链表
DulNode* initList() {
    DulNode* head = new DulNode();
    head->prior = nullptr;
    head->next = nullptr;
    return head;
}

// 创建双链表
DulNode* createList(int n) {
    DulNode* head = initList();
    DulNode* p = head;
    for (int i = 0; i < n; i++) {
        DulNode* newNode = new DulNode();
        cin >> newNode->data;
        newNode->prior = p;
        newNode->next = nullptr;
        p->next = newNode;
        p = newNode;
    }
    return head;
}
// 插入操作
void insertNode(DulNode* head, int pos, Elemtype value) {
    DulNode* p = head;
    int i = 0;
    while (p && i < pos) {
        p = p->next;
        i++;
    }
    if (!p || i > pos) {
        return;
    }
    DulNode* newNode = new DulNode();
    newNode->data = value;
    newNode->next = p->next;
    newNode->prior = p;
    if (p->next) {
        p->next->prior = newNode;
    }
    p->next = newNode;
}

// 删除操作
void deleteNode(DulNode* head, int pos) {
    DulNode* p = head->next;
    int i = 0;
    while (p && i < pos) {
        p = p->next;
        i++;
    }
    if (!p || i > pos) {
        return;
    }
    if (p->prior) {
        p->prior->next = p->next;
    }
    if (p->next) {
        p->next->prior = p->prior;
    }
    delete p;
}

// 正向遍历
void traverseForward(DulNode* head) {
    DulNode* p = head->next;
    while (p) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

// 反向遍历
void traverseBackward(DulNode* head) {
    DulNode* p = head;
    while (p->next) {
        p = p->next;
    }
    while (p != head) {
        cout << p->data << " ";
        p = p->prior;
    }
    cout << endl;
}
```

#### STL（list双向链表）

```c++
#include <list>

    list<int> l;

    // 插入元素
    l.push_back(10);
    l.push_front(5);

    // 输出当前链表
    for (int val : l) {
        cout << val << " "; 
    }

    // 查找元素
    auto it = find(l.begin(), l.end(), 10);
    if (it != l.end()) {
        cout << "Found!" << endl;
    } 

    // 删除元素
    l.erase(l.begin());  // 删除第一个元素（5）

    // 输出链表
    for (int val : l) {
        cout << val << " ";  // 输出: 10 20 30
    }

    // 反转链表
    l.reverse();

    // 排序链表
    l.sort();

    // 删除相邻的重复元素
    l.push_back(20);
    l.push_back(20);
    l.unique();
```

### 栈

```c++
#include<bits/stdc++.h>
using namespace std;

#define maxsize 100

typedef int ElemType;
typedef struct{
    ElemType *base;
    ElemType *top;
    int stacksize;
}SqStack;

//初始化
void InitStack(SqStack &s){
    s.base = new ElemType[maxsize];
    if(!s.base) exit(OVERFLOW);
    s.top = s.base;
    s.stacksize = maxsize;
}

//是否为空
bool IsEmpty(SqStack s){
    return s.top == s.base;
}

//是否已满
bool IsFull(SqStack s){
    return s.top - s.base == s.stacksize;
}

//进栈
void Push(SqStack &s, ElemType e){
    if(IsFull(s)){
        return;
    }
    *s.top = e;
    s.top++;
}

//出栈
void Pop(SqStack &s, ElemType &e){
    if(IsEmpty(s)){
        cout << "Stack is empty. Cannot pop element." << endl;
        return;
    }
    s.top--;
    e = *s.top;
}

// 获取栈顶元素
ElemType GetTop(SqStack s){
    if(IsEmpty(s)){
        return -1; 
    }
    return *(s.top - 1);
}

// 打印栈中的所有元素
void PrintStack(SqStack s){
    if(IsEmpty(s)){
        return;
    }
    for(ElemType *p = s.base; p != s.top; p++){
        cout << *p << " ";
    }
    cout << endl;
}

// 销毁栈
void DestroyStack(SqStack &s){
    delete[] s.base;
    s.base = s.top = nullptr;
    s.stacksize = 0;
}

// 链栈节点定义
typedef struct StackNode {
    ElemType data;
    struct StackNode *next;
} StackNode;

// 初始化栈
void Init(StackNode* &s) {
    s = NULL; 
}

// 入栈操作
void Push(StackNode* &s, ElemType e) {
    StackNode* p = new StackNode;  
    p->data = e;  
    p->next = s;  
    s = p;  
}

// 出栈操作
void Pop(StackNode* &s, ElemType &e) {
    if (s == NULL) {
        return;  
    }
    e = s->data;  
    StackNode* p = s; 
    s = s->next; 
    delete p; 
}

// 取栈顶元素
ElemType GetTop(StackNode* s) {
    if (s != NULL) {
        return s->data; 
    }
    return -1;  
}
```

#### STL

**成员函数**

- `top()` 访问栈顶元素（如果栈为空，此处会出错）
- `push(x)` 向栈中插入元素 x
- `pop()` 删除栈顶元素
- `size()` 查询容器中的元素数量
- `empty()` 询问容器是否为空

```c++
#include<stack>
stack<int> s1;
s1.push(2);
s1.push(1);
stack<int> s2(s1);
s1.pop();
cout << s1.size() << " " << s2.size() << endl;  // 1 2
cout << s1.top() << " " << s2.top() << endl;    // 2 1
s1.pop();
cout << s1.empty() << " " << s2.empty() << endl;  // 1 0
```

### 队列

```c++
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
        exit(OVERFLOW);
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

// 链队列节点定义
typedef struct QNode {
    ElemType data;         
    struct QNode *next;    
} QNode;

// 链队列定义
typedef struct {
    QNode *front;           
    QNode *rear;           
} Queue;

// 初始化队列
void InitQueue(Queue *Q) {
    Q->front = Q->rear = NULL;  
}

// 入队操作
void EnQueue(Queue *Q, ElemType e) {
    QNode *newNode = new QNode;
    newNode->data = e;                             
    newNode->next = NULL;                            
    if (Q->rear == NULL) {
        Q->front = Q->rear = newNode;  
    } else {
        Q->rear->next = newNode;  
        Q->rear = newNode;        
    }
}

// 出队操作
bool DeQueue(Queue *Q, ElemType *e) {
    if (Q->front == NULL) {  
        return false; 
    }

    QNode *temp = Q->front;  
    *e = temp->data;        
    Q->front = Q->front->next; 

    if (Q->front == NULL) {  
        Q->rear = NULL;      
    }
    delete temp;  
    return true;  
}

// 获取队头元素
ElemType GetFront(Queue *Q) {
    if (Q->front == NULL) {  
        return -1; 
    }
    return Q->front->data;          
}

//带头结点的循环队列
typedef struct QNode {
    int data;          
    struct QNode* next;     
} QNode;
typedef struct {
    QNode* rear;            
} LinkQueue;

bool initQueue(LinkQueue& Q) {
            Q.rear = (QNode *)malloc(sizeof(QNode));
             if  (Q.rear == NULL)
                   return false;
             Q.rear->next = Q.rear;
             return true;
}
bool inQueue(LinkQueue& Q, int value) {
    QNode* newNode = (QNode*)malloc(sizeof(QNode));
    if (newNode == NULL) {
        return false; 
    }
    newNode->data = value;
    newNode->next = Q.rear->next; 
    Q.rear->next = newNode;     
    Q.rear = newNode;            
    return true;
}

bool outQueue(LinkQueue& Q, int& value) {
    if (Q.rear->next == Q.rear) {
        return false; 
    }
    QNode* frontNode = Q.rear->next->next; 
    value = frontNode->data;               
    Q.rear->next->next = frontNode->next;  
    if (frontNode == Q.rear) {            
        Q.rear = Q.rear->next;          
    }
    free(frontNode);                  
    return true;
}
```

#### STL

- `front()` 访问队首元素（如果队列为空，此处会出错）
- `push(x)` 向队列中插入元素 x
- `pop()` 删除队首元素
- `size()` 查询容器中的元素数量
- `empty()` 询问容器是否为空

```c++
#include<queue>
queue<int> q1;
q1.push(2);
q1.push(1);
queue<int> q2(q1);
q1.pop();
cout << q1.size() << " " << q2.size() << endl;    // 1 2
cout << q1.front() << " " << q2.front() << endl;  // 1 2
q1.pop();
cout << q1.empty() << " " << q2.empty() << endl;  // 1 0
```

#### 优先队列（priority_queue)

```c++
// 最小堆
priority_queue<int, vector<int>, greater<int>> pq
// 自定义堆
struct MyCompare {
    bool operator()(int a, int b) {
        return a < b; // 最大堆
    }
};
priority_queue<int, vector<int>, MyCompare> pq;
// 插入元素
pq.push(element);
// 访问顶部元素（不删除）
int top = pq.top();
// 删除顶部元素
pq.pop();
// 检查是否为空
bool isEmpty = pq.empty();
// 获取元素数量
size_t size = pq.size();
```

### 串

```c++
#include<iostream>

using namespace std;

#define maxlen 255
#define chunksize 80

//顺序存储
typedef struct{
    char ch[maxlen+1];
    int length;
}SString;

//链式存储
typedef struct chunk{
    char ch[chunksize];
    struct chunk *next;
}chunk;

typedef struct{
    chunk *head,*tail;
    int length;
}LString;
 
//字串定位
//Brute-Force
int BF(SString s,SSting t,int pos){
    int i = pos;
    int j = 1;
    while(i<=s.length && j<=t.length()){
        if(s.ch[i]==t.ch[j]){
            i++;
            j++;
        }
            else{
                i = i-j+2;//指针回退
                j = 1;
        }
    }
   if(j>t.length) return i-t.length //匹配成功
   else return 0;//匹配失败
}

//KMP
#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<int> Next(const string &j) {
    int m = j.length();
    vector<int> next(m + 1, 0);
    int k = 0;
    next[0] = -1;
    for (int i = 1; i < m; i++) {
        while (k >= 0 && j[i] != j[k]) {
            k = next[k];
        }
        k++;
        next[i + 1] = k;
    }
    return next;
}
void KMP(const string &t, const string &j) {
    int n = t.length();
    int m = j.length();
    if (m == 0) {
        cout << "Not Found" << endl;
        return;
    }
    vector<int> next = Next(j);
    int i = 0;
    int k = 0;

    while (i < n) {
        if (k == -1 || t[i] == j[k]) {
            i++;
            k++;
            if (k == m) {
                cout << t.substr(i - m) << endl;
                return;
            }
        } else {
            k = next[k];
        }
    }
    cout << "Not Found" << endl;
}
int main() {
    string t;
    int n;
    getline(cin, t);
    cin >> n;
    cin.ignore();
    while (n--) {
        string j;
        getline(cin, j);
        KMP(t, j);
    }
    return 0;
}
```

#### STL

长度：``s.size()``/``s.length()``

查找字符（串）第一次出现的位置：``s.find(u)``/``s.find(t,pos)``     **注：不是KMP**

截取子串：``substr(pos,len)``

插入：``insert(index,str)``

替换字符串：``replace(first,second,str)``

### 数组

$$
LOC(i,j)=LOC(0,0)+(n*i+j)*L\\
其中L为一个内存存储单元
$$

#### 特殊矩阵的压缩存储

$$
对称矩阵：a_{ij} = a_{ji}，若一维数组压缩：\\i>=j,k = \frac{i(i-1)}{2}+j-1\\i<j,k = \frac{j(j-1)}{2}+i-1\\
三角矩阵：\\
上三角：i>j,k = \frac{n(n+1)}{2},i<=j,\frac{i(i-1)}{2}+j-1\\
下三角：i>j,k = \frac{i(i-1)}{2}+j-1,i<=j,\frac{n(n+1)}{2}\\
多对角线矩阵：根据非零元的分布确定通项公式
$$

### 广义表

```c++
typedef enum(ATOM,LIST) ElemTag;//ATOM==0,原子；LIST==1，子表
typedef struct GLNode
{
    ElemTag tag;//区分原子结点or表结点
    union{
        AtomType atom;//原子值域
        struct{
            struct GNode* hp,*tp;
        }ptr;
    };
}*GList;
GetHead(LS);//取表头
GetTail(LS);//取表尾，仍为广义表
```

### 树 

#### 二叉树

* 每个节点至多只有两个子树
* 满二叉树：每个节点均有两个子树
* 完全二叉树：叶子节点只在最深的两层出现

```c++
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
{
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
    return (m > n) ? (m + 1) : (n + 1);
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
    struct BiThrNode *lchild, *rchild;
    int LTag, RTag;
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
        if (pre && !pre->rchild)
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
    BiThrTree p = T->lchild;
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
```

#### 哈夫曼树

```c++
#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

typedef struct
{
    int weight;
    int parent, lchild, rchild;
} HTNode, *HuffmanTree;

typedef char **HuffmanCode;

void CreateHuffmanTree(HuffmanTree &T, int n)
{
    if (n <= 1)
        return;
    int m = 2 * n - 1;
    T = new HTNode[m + 1];

    // 初始化所有节点
    for (int i = 1; i <= m; i++)
    {
        T[i].parent = 0;
        T[i].lchild = 0;
        T[i].rchild = 0;
        T[i].weight = 0;
    }

    // 输入叶子节点权重
    for (int i = 1; i <= n; i++)
    {
        cin >> T[i].weight;
    }

    // 使用优先队列存储
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (int i = 1; i <= n; i++)
    {
        pq.push(make_pair(T[i].weight, i));
    }

    int current = n + 1; // 当前中间节点索引
    for (int i = 1; i <= n - 1; i++)
    {
        // 获取两个最小节点
        int s1 = -1, s2 = -1;

        // 寻找第一个有效节点
        while (!pq.empty() && s1 == -1)
        {
            auto top = pq.top();
            pq.pop();
            if (T[top.second].parent == 0)
            {
                s1 = top.second;
            }
        }

        // 寻找第二个有效节点
        while (!pq.empty() && s2 == -1)
        {
            auto top = pq.top();
            pq.pop();
            if (T[top.second].parent == 0)
            {
                s2 = top.second;
            }
        }

        if (s1 == -1 || s2 == -1)
        {
            cerr << "Error: Insufficient nodes to build Huffman tree." << endl;
            return;
        }

        // 创建新节点
        T[current].weight = T[s1].weight + T[s2].weight;
        T[current].lchild = s1;
        T[current].rchild = s2;
        T[s1].parent = current;
        T[s2].parent = current;

        // 将新节点加入优先队列
        pq.push(make_pair(T[current].weight, current));
        current++;
    }
}

void CreateHuffmanCode(HuffmanTree HT, HuffmanCode &HC, int n)
{
    HC = new char *[n + 1];
    char *cd = new char[n];
    cd[n - 1] = '\0';

    for (int i = 1; i <= n; i++)
    {
        int start = n - 1;
        int c = i;
        int f = HT[i].parent;

        while (f != 0)
        {
            start--;
            if (HT[f].lchild == c)
            {
                cd[start] = '0';
            }
            else
            {
                cd[start] = '1';
            }
            c = f;
            f = HT[f].parent;
        }

        HC[i] = new char[n - start];
        strcpy(HC[i], &cd[start]);
    }
    delete[] cd;
}
```

#### 并查集

```c++
#include <iostream>

using namespace std;

const int MAXN = 1000;
int father[MAXN];
int Rank[MAXN];

void init()
{
    for (int i = 0; i < MAXN; i++)
    {
        father[i] = i;
        Rank[i] = 1;
    }
}

int find_set(int x)
{
    if (x != father[x])
    {
        father[x] = find_set(father[x]);
    }
    return father[x];
}

void Union(int x, int y)
{
    int root_x = find_set(x);
    int root_y = find_set(y);
    if (root_x == root_y)
        return;
    if (Rank[root_x] > Rank[root_y])
    {
        father[root_y] = root_x;
        Rank[root_x] += Rank[root_y];
    }
    else
    {
        father[root_x] = root_y;
        Rank[root_y] += Rank[root_x];
    }
}
```

### 哈希表

```c++
#include <iostream>
#include <vector>
#include <list>

using namespace std;

static const int tableSize = 10;

// 哈希表数组，包含链表来处理冲突
vector<list<pair<int, string>>> table(tableSize);

// 哈希函数
int hashFunction(int key)
{
    return key % tableSize;
}

// 插入操作
void insert(int key, string value)
{
    int index = hashFunction(key);
    // 通过链表的方式处理哈希冲突
    table[index].push_back(make_pair(key, value));
}

// 查找操作
string search(int key)
{
    int index = hashFunction(key);
    for (auto &pair : table[index])
    {
        if (pair.first == key)
        {
            return pair.second;
        }
    }
    return;
}

// 删除操作
void remove(int key)
{
    int index = hashFunction(key);
    auto &chain = table[index];
    for (auto it = chain.begin(); it != chain.end(); ++it)
    {
        if (it->first == key)
        {
            chain.erase(it);
            return;
        }
    }
}
```

#### STL（set&map）

```c++
#include <set>
#include <map>

    set<int> s;
    // 插入元素
    s.insert(5);
    s.insert(10);
    s.insert(10);  // 插入重复元素，不会插入
    // 查找元素
    if (s.find(10) != s.end()) {
      cout << "10 is in the set!" << endl;
    }
    // 删除元素
    s.erase(10);  
    // 遍历集合
    cout << "Elements in set: ";
    for (auto it = s.begin(); it != s.end(); ++it) {
       cout << *it << " ";
    }
    // 获取大小
    cout << "Set size: " << s.size() << endl;
    // 使用 lower_bound 和 upper_bound
    auto it = s.lower_bound(5);  // 返回不小于 5 的元素
    if (it != s.end()) {
      cout << *it << endl;
    }

    map<int, string> m;
    // 插入键值对
    m.insert({1, "One"});
    m.insert({2, "Two"});
    m[3] = "Three"; 
    // 查找元素
    auto it = m.find(2);
    if (it != m.end())
    {
        cout << it->second << endl;
    }
    // 删除元素
    m.erase(1); 
    // 遍历 map
    cout << "Elements in map: ";
    for (auto &pair : m)
    {
        cout << pair.first << " => " << pair.second << " | ";
    }
    // 获取大小
    cout << m.size() << endl;
    // 使用 lower_bound 和 upper_bound
    auto lb = m.lower_bound(2); // 查找不小于 2 的元素
    if (lb != m.end())
    {
        cout << lb->first << " => " << lb->second << endl;
    }
```

### 图

```c++
#include <iostream>

using namespace std;

#define MaxInt 32767     // 极大值
#define MVNum 100        // 顶点最大值
typedef char VerTexType; // 顶点
typedef int ArcType;     // 边

// 邻接矩阵表示法
typedef struct
{
    VerTexType vexs[MVNum];     // 顶点表
    ArcType arcs[MVNum][MVNum]; // 邻接矩阵
    int vexnum, arcnum;
} AMGraph;

int LocateVex(AMGraph G, VerTexType v)
{
    for (int i = 0; i < G.vexnum; i++)
    {
        if (G.vexs[i] == v)
        {
            return i;
        }
    }
    return -1;
}

void CreateAM(AMGraph &G)
{
    cin >> G.vexnum >> G.arcnum;
    for (int i = 0; i < G.vexnum; i++)
    {
        cin >> G.vexs[i];
    }
    for (int i = 0; i < G.vexnum; i++)
    {
        for (int j = 0; j < G.vexnum; j++)
        {
            if (i == j)
            {
                G.arcs[i][j] = 0;
            }
            else
            {
                G.arcs[i][j] = MaxInt;
            }
        }
    }
    for (int k = 0; k < G.arcnum; k++)
    {
        VerTexType v1, v2;
        ArcType w;
        cin >> v1 >> v2 >> w;
        int i = LocateVex(G, v1);
        int j = LocateVex(G, v2);
        G.arcs[i][j] = w;
        G.arcs[j][i] = w;
    }
}

// 邻接表表示法
typedef struct ArcNode
{
    int adjvex; // 该边指向的顶点位置
    int weight; // 边的权重
    struct ArcNode *nextarc;
} ArcNode;

typedef struct VNode
{
    VerTexType data;   // 顶点信息
    ArcNode *firstarc; // 指向第一条边的指针
} VNode, AdjList[MVNum];

typedef struct
{
    AdjList vertices;   // 邻接表
    int vexnum, arcnum; // 顶点数和边数
} ALGraph;

void CreateAL(ALGraph &G)
{
    cin >> G.vexnum >> G.arcnum;
    for (int i = 0; i < G.vexnum; i++)
    {
        cin >> G.vertices[i].data;
        G.vertices[i].firstarc = NULL;
    }
    for (int k = 0; k < G.arcnum; k++)
    {
        VerTexType v1, v2;
        ArcType weight;
        cin >> v1 >> v2 >> weight;
        int i = LocateVex(*(AMGraph *)&G, v1);
        int j = LocateVex(*(AMGraph *)&G, v2);
        ArcNode *p1 = new ArcNode;
        p1->adjvex = j;
        p1->weight = weight;
        p1->nextarc = G.vertices[i].firstarc;
        G.vertices[i].firstarc = p1;
        /*
        // 无向图需要对称添加（v2->v1）
        ArcNode *p2 = new ArcNode;
        p2->adjvex = i;
        p2->weight = weight;
        p2->nextarc = G.vertices[j].firstarc;
        G.vertices[j].firstarc = p2;
        */
    }
}
```

#### 搜索（DFS&BFS）

##### DFS

```c++
#include <iostream>
using namespace std;

const int MVNum = 100;
bool visited[MVNum];

struct Graph
{
    int arcs[MVNum][MVNum];
    int vexnum, arcnum;
};

struct ArcNode
{
    int adjvex;
    ArcNode *nextarc;
};

struct VNode
{
    ArcNode *firstarc;
};

struct ALGraph
{
    VNode vertices[MVNum];
    int vexnum, arcnum;
};

int FirstAdjVex(Graph G, int v)
{
    for (int i = 0; i < G.vexnum; ++i)
        if (G.arcs[v][i])
            return i;
    return -1;
}

int NextAdjVex(Graph G, int v, int w)
{
    for (int i = w + 1; i < G.vexnum; ++i)
        if (G.arcs[v][i])
            return i;
    return -1;
}

void DFS(Graph G, int v)
{
    cout << v;
    visited[v] = true;
    for (int w = FirstAdjVex(G, v); w >= 0; w = NextAdjVex(G, v, w))
        if (!visited[w])
            DFS(G, w);
}

void DFSTraverse(Graph G)
{
    for (int i = 0; i < G.vexnum; ++i)
        visited[i] = false;
    for (int i = 0; i < G.vexnum; ++i)
        if (!visited[i])
            DFS(G, i);
}

void DFS_AM(Graph G, int v)
{
    cout << v;
    visited[v] = true;
    for (int w = 0; w < G.vexnum; w++)
        if (G.arcs[v][w] && !visited[w])
            DFS_AM(G, w);
}

void DFS_AL(ALGraph G, int v)
{
    cout << v;
    visited[v] = true;
    ArcNode *p = G.vertices[v].firstarc;
    while (p)
    {
        int w = p->adjvex;
        if (!visited[w])
            DFS_AL(G, w);
        p = p->nextarc;
    }
}
```

##### BFS

```c++
#include <iostream>
#include <queue>
using namespace std;

const int MVNum = 100;
bool visited[MVNum];

struct Graph
{
    int arcs[MVNum][MVNum];
    int vexnum, arcnum;
};

struct ArcNode
{
    int adjvex;
    ArcNode *nextarc;
};

struct VNode
{
    ArcNode *firstarc;
};

struct ALGraph
{
    VNode vertices[MVNum];
    int vexnum, arcnum;
};

int FirstAdjVex(Graph G, int v)
{
    for (int i = 0; i < G.vexnum; ++i)
        if (G.arcs[v][i])
            return i;
    return -1;
}

int NextAdjVex(Graph G, int v, int w)
{
    for (int i = w + 1; i < G.vexnum; ++i)
        if (G.arcs[v][i])
            return i;
    return -1;
}

void BFS(Graph G, int v)
{
    queue<int> Q;
    cout << v;
    visited[v] = true;
    Q.push(v);
    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        for (int w = FirstAdjVex(G, u); w >= 0; w = NextAdjVex(G, u, w))
        {
            if (!visited[w])
            {
                cout << w;
                visited[w] = true;
                Q.push(w);
            }
        }
    }
}

void BFS_AM(Graph G, int v)
{
    queue<int> Q;
    cout << v;
    visited[v] = true;
    Q.push(v);
    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        for (int w = 0; w < G.vexnum; w++)
        {
            if (G.arcs[u][w] && !visited[w])
            {
                cout << w;
                visited[w] = true;
                Q.push(w);
            }
        }
    }
}

void BFS_AL(ALGraph G, int v)
{
    queue<int> Q;
    cout << v;
    visited[v] = true;
    Q.push(v);
    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        ArcNode *p = G.vertices[u].firstarc;
        while (p)
        {
            int w = p->adjvex;
            if (!visited[w])
            {
                cout << w;
                visited[w] = true;
                Q.push(w);
            }
            p = p->nextarc;
        }
    }
}

void BFSTraverse(Graph G)
{
    for (int i = 0; i < G.vexnum; ++i)
        visited[i] = false;
    for (int i = 0; i < G.vexnum; ++i)
        if (!visited[i])
            BFS_AM(G, i);
}

void BFSTraverse(ALGraph G)
{
    for (int i = 0; i < G.vexnum; ++i)
        visited[i] = false;
    for (int i = 0; i < G.vexnum; ++i)
        if (!visited[i])
            BFS_AL(G, i);
}
```

