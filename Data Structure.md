# Data Structure

## 线性表

### 顺序表

```c++
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
```

### 单链表

```c++
#include<iostream>
using namespace std;

typedef int ElemType;
typedef struct Node {
    ElemType data;
    struct Node* next;
}Node,*LinkList;

// 初始化(带头结点)
void InitList(LinkList &L) {
    L = (Node*)malloc(sizeof(Node));
    L->next = NULL;
    //若不带头结点，直接L = NULL;
}

// 求表长
int Length(LinkList L){
    int len = 0;
    Node *p = L;
    while(p->next!=NULL){
        p = p->next;
        len++;
    }
    return len;
}

// 取值
void GetElem(LinkList L, int i, ElemType &e) {
    Node* p = L;
    int j = 0;
    while (p && j < i) {
        p = p->next;
        j++;
    }
    if (!p || j > i) return;
    e = p->data;
}

// 查找
Node* LocateNode(LinkList L, ElemType e) {
    Node* p = L->next;
    while (p && p->data != e) {
        p = p->next;
    }
    return p;
}

//插入
void insertNode(LinkList &L, int i, ElemType e) {
    Node* p = L;
    int j = 0;
    while (p && j < i - 1) {
        p = p->next;
        j++;
    }
    if (!p) return;
    Node* s = new Node;
    s->data = e;
    s->next = p->next;
    p->next = s;
}

//删除
void deleteNode(LinkList &L, int i) {
    Node* p = L;
    int j = 0;
    while (p && j < i - 1) {
        p = p->next;
        j++;
    }
    if (!p->next||!p) return;
    Node* q = p->next;
    p->next = q->next;
    delete q;
}

//头插法
void createList_H(LinkList &L, int n) {
    L = new Node; // L固定为头结点
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
    L = new Node; //L为固定头结点
    L->next = NULL;
    Node* r = L;
    for (int i = 0; i < n; i++) {
        Node* p = new Node;
        cin >> p->data;
        p->next = NULL;
        r->next = p;
        r = p;
    }
    //循环列表，p->next = L->next;
}

//遍历
void printlist(LinkList L)
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
#include<iostream>
using namespace std;

typedef int Elemtype;

// 定义双链表节点
typedef struct DNode {
    Elemtype data;
    struct DNode* prior;
    struct DNode* next;
} DNode, *DList;

// 初始化双链表
DList initList() {
    DNode* head = new DNode();
    head->prior = nullptr;
    head->next = nullptr;
    return head;
}

// 创建双链表
void createList(DList &L, int n) {
    DNode* p = L;
    for (int i = 0; i < n; i++) {
        DNode* newNode = new DNode;
        cin >> newNode->data;
        newNode->prior = p;
        newNode->next = nullptr;
        p->next = newNode;
        p = newNode;
    }
    //循环链表，newNode->next = L->next;L->next->prior = newNode;
}

// 插入操作
void insertNode(DList &L, int pos, Elemtype e) {
    DNode* p = L;
    int i = 0;
    while (p && i < pos) {
        p = p->next;
        i++;
    }
    if (!p) {
        return;
    }
    DNode* newNode = new DNode;
    newNode->data = e;
    newNode->next = p->next;
    newNode->prior = p;
    if (p->next) {
        p->next->prior = newNode;
    }
    p->next = newNode;
}

// 删除操作
void deleteNode(DList &L, int pos) {
    DNode* p = L->next;
    int i = 0;
    while (p && i < pos) {
        p = p->next;
        i++;
    }
    if (!p) {
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
void traverseForward(DList L) {
    DNode* p = L->next;
    while (p) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

// 反向遍历
void traverseBackward(DList L) {
    DNode* p = L;
    while (p->next) {
        p = p->next;
    }
    while (p != L) {
        cout << p->data << " ";
        p = p->prior;
    }
    cout << endl;
}
```

#### STL

**list**

```c++
#include <list>
#include<iostream>
using namespace std;

int main(){
    list<int> l;
    // 插入元素
    l.push_back(10);
    l.push_front(5);
    // 输出
    for (int val : l) {
        cout << val << " "; 
    }
    // 查找元素
    auto it = find(l.begin(), l.end(), 10);
    if (it != l.end()) {
        cout << "Found!" << endl;
    } 
    // 删除元素
    l.erase(l.begin());  
    // 反转链表
    l.reverse();
    // 排序链表
    l.sort();
    // 删除相邻的重复元素
    l.push_back(20);
    l.push_back(20);
    l.unique();
}
```

### 静态链表

```c++
typedef int ElemType;
#define MAXSIZE 50

typedef struct{
    ElemType data;
    int next;// 存储地址(具体数值)
}SLinkList[MAXSIZE];
```

## 栈与队列

### 栈

```c++
#include <iostream>
using namespace std;

#define MAXSIZE 100

typedef int Elemtype;

//顺序存储
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
```

#### STL

**stack**

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
cout << s1.size() << endl;
s1.pop();
s1.pop();
cout << s1.empty() << endl;
```

### 队列

```c++
#include<iostream>

using namespace std;

#define maxsize 100

typedef int ElemType;
typedef struct {
    ElemType *base;
    int front;
    int rear;
} SqQueue;// 可作为单向队列或循环队列，这里视为循环队列

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

// 队列链式存储(带头结点)
// 节点定义
typedef struct QNode{
    ElemType data;         
    struct QNode *next;    
}QNode;

// 链队列定义
typedef struct {
    QNode *front;           
    QNode *rear;           
}LinkQueue;

// 初始化队列
void InitQueue(LinkQueue &Q) {
    Q.front = new QNode;
    Q.rear = Q.front;  
    Q.front->next = NULL;
}

// 判断为空
bool IsEmpty(LinkQueue Q){
    return (Q.front == Q.rear);
}

// 入队操作
void EnQueue(LinkQueue &Q, ElemType e) {
    QNode *newNode = new QNode;
    newNode->data = e;                             
    newNode->next = NULL;                            
    Q.rear->next = newNode;  
    Q.rear = newNode;        
}

// 出队操作
void DeQueue(LinkQueue &Q, ElemType &e) {
    if (IsEmpty(Q)) {
        return; 
    }

    QNode *temp = Q.front->next;  
    e = temp->data;        
    Q.front->next = temp->next; 

    if (temp == Q.rear) {  
        Q.rear = Q.front;      
    }
    delete temp;  
}

// 获取队头元素
ElemType GetFront(LinkQueue Q) {
    if (IsEmpty(Q)) {  
        return -1; 
    }
    return Q.front->next->data;          
}
```

#### STL

**queue**

- `front()` 访问队首元素（如果队列为空，此处会出错）
- `push(x)` 向队列中插入元素 x
- `pop()` 删除队首元素
- `size()` 查询容器中的元素数量
- `empty()` 询问容器是否为空

**deque**

- `push_front(x)` 在队首插入元素 x
- `push_back(x)` 在队尾插入元素 x 
- `pop_front()` 删除队首元素  
- `pop_back()` 删除队尾元素  
- `front()` 访问队首元素  
-  `back()` 访问队尾元素  
- `size()` 查询元素数量  
-  `empty()` 判断是否为空 

```c++
#include<queue>
#include<iostream>
using namespace std;

// 单项队列
queue<int> q1;
q1.push(2);
q1.push(1);
q1.pop();
cout << q1.size() << endl;
cout << q1.front() << endl;
q1.pop();
cout << q1.empty() << endl;
// 双向队列
deque<int> dq;
dq.push_back(3);    
dq.push_front(1);    
dq.pop_front();     
dq.push_front(5);    
dq.pop_back();       
dq.pop_back();      
cout << dq.size() << endl;   
cout << dq.empty() << endl;   
```

#### 优先队列（priority_queue)

```c++
// 默认最小堆(原理其实是构建完全二叉树进行堆排序，因此初始化时有数组和比较条件)
priority_queue<int, vector<int>, greater<int>> pq
// 自定义堆
struct cmp {
    bool operator()(int a, int b) {
        return a < b; // 最大堆
    }
};
priority_queue<int, vector<int>, cmp> pq;
// 插入元素
int element = 1;
pq.push(element);
// 访问顶部元素
int top = pq.top();
// 删除顶部元素
pq.pop();
// 检查是否为空
bool isEmpty = pq.empty();
// 获取元素数量
size_t size = pq.size();
```

### 数组

以二维数组为例：
$$
LOC(i,j)=LOC(0,0)+(n*i+j)*L
$$

其中$L$为每个数组元素所占的单元。

**特殊矩阵的压缩存储**

1.对称矩阵

对于n阶矩阵A，若$a_{i,j}=a_{j,i}$，则为对称矩阵。假设我们要压缩成一维数组，求解下标$k$有以下公式：
$$
i>=j,k = \frac{i(i-1)}{2}+j-1\\i<j,k = \frac{j(j-1)}{2}+i-1\\
$$

2.三角矩阵
$$
上三角：i>j,k = \frac{n(n+1)}{2},i<=j,\frac{(2n-i+2)(i-1)}{2}+j-i\\
下三角：i>j,k = \frac{i(i-1)}{2}+j-1,i<=j,\frac{n(n+1)}{2}
$$
3.带状矩阵

第1行和第n行有两个元，其余行均有三个元，（形成三条对角线），对$a_{i,j}$若压缩成一维矩阵有：
$$
k = 2i+j-3
$$
4.稀疏矩阵

将稀疏分布的矩阵转为三元组（行标$i$，列标$j$，值$a_{i,j}$）

```c++
typedef struct{
    int col;
    int row;
    int data;
}Matrix;
```

#### STL

**vector**

* `push_back(x)` 在尾部插入元素 x  

- `pop_back()` 删除尾部元素  
- `front()` 访问首元素  
- `back()` 访问尾元素  
- `size()` 查询元素数量  
- `empty()` 判断是否为空  
- `clear()` 清空所有元素 

```c++
#include<vector>
#include<iostream>
using namespace std;

vector<int> vec;
vec.push_back(1);   
vec.push_back(2);   
vec.pop_back();      
vec.push_back(3);    

cout << vec.size() << endl;     
cout << vec.front() << endl;    
cout << vec.back() << endl;     
cout << vec[1] << endl;         

vec.clear();                   
cout << vec.empty() << endl;   

vector<vector<int>> matrix(3, vector<int>(2, 0));// 3列，2行，每行填充0 
matrix[0][0] = 1;   
matrix[1].push_back(3);  
vector<int> new_row = {5, 7, 9};
matrix.push_back(new_row); 
for (int i = 0; i < matrix.size(); i++) {
    for (int j = 0; j < matrix[i].size(); j++) {
          cout << matrix[i][j] << " ";
    }
    cout << endl;
}
```

## 串

```c++
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define maxlen 255

// 顺序存储
typedef struct{
    char ch[maxlen];
    int length;
}SString;

// 堆分配存储
typedef struct{
    char *ch;
    int length;
}HString;

// 链式存储
typedef struct CharNode {
    char ch;                
    struct CharNode *next;  
} CharNode, *CharPtr;

typedef struct {
    CharPtr head; 
    int length;   
} LString;

// 字串定位算法
// Brute-Force
int BF(SString s,SSting t,int pos){
    int i = pos;
    int j = 1;
    while(i<=s.length && j<=t.length()){
        if(s.ch[i]==t.ch[j]){
            i++;
            j++;
        }
            else{
                i = i - j + 2;
                j = 1;
        }
    }
   if(j>t.length) return i-t.length;
   else return 0;
}

// KMP
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
    return;
}
```

#### STL

**string**

长度：``s.size()``/``s.length()``

查找字符（串）第一次出现的位置：``s.find(u)``/``s.find(t,pos)``     **注：不是KMP**

截取子串：``substr(pos,len)``

插入：``insert(index,str)``

替换字符串：``replace(first,second,str)``

```c++
#include <iostream>
#include <string>

using namespace std;

string s = "hello, world";
cout << s.size() << endl;
size_t pos1 = s.find('o');
size_t pos2 = s.find("world", 0);
string sub = s.substr(7, 5);
string s2 = s;
s2.insert(5, " C++");
string s3 = s;
s3.replace(0, 5, "Hi");
```

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

## 树 

#### 二叉树

```c++
#include <iostream>
#include <stack>
#include <queue>

using namespace std;

#define MAXSIZE 100

typedef int TElemType;

// 顺序存储结构（即层序遍历，空结点值可以为0）
typedef struct{
    TElemType data[MAXSIZE];
}SqBiTree;

// 链式定义结点结构
typedef struct BiTNode {
    TElemType data;
    BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

// 中序遍历（递归）
void InOrderTraverse(BiTree T) {
    if (T) {
        InOrderTraverse(T->lchild);
        cout << T->data;
        InOrderTraverse(T->rchild);
    }
}

// 先序遍历（递归）
void PreOrderTraverse(BiTree T) {
    if (T) {
        cout << T->data;
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);
    }
}

// 后序遍历（递归）
void PostOrderTraverse(BiTree T) {
    if (T) {
        PostOrderTraverse(T->lchild);
        PostOrderTraverse(T->rchild);
        cout << T->data;
    }
}

// 中序遍历（非递归）
void InOrderTraverse_NonRecursive(BiTree T) {
    stack<BiTree> s;
    BiTree p = T;
    while (p || !s.empty()) {
        if (p) {
            s.push(p);
            p = p->lchild;
        } else {
            BiTree q = s.top();
            s.pop();
            cout << q->data;
            p = q->rchild;
        }
    }
}

// 先序遍历（非递归）
void PreOrderTraverse_NonRecursive(BiTree T) {
    if (!T) return;
    stack<BiTree> s;
    s.push(T);
    while (!s.empty()) {
        BiTree q = s.top();
        s.pop();
        cout << q->data;
        if (q->rchild) s.push(q->rchild);
        if (q->lchild) s.push(q->lchild);
    }
}

// 后序遍历（非递归）
void PostOrderTraverse_NonRecursive(BiTree T) {
    stack<BiTree> s;
    BiTree p = T;
    BiTree lastVisited = nullptr;
    while (p || !s.empty()) {
        if (p) {
            s.push(p);
            p = p->lchild;
        } else {
            BiTree q = s.top();
            if (q->rchild && lastVisited != q->rchild) {
                p = q->rchild;
            } else {
                cout << q->data;
                lastVisited = q;
                s.pop();
            }
        }
    }
}

// 层次遍历二叉树
void LevelOrderTraverse(BiTree T) {
    if (!T) return;            
    queue<BiTree> q;            
    q.push(T);                   
    while (!q.empty()) {
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
void CreateBiTree(BiTree &T) {
    char ch;
    cin >> ch;
    if (ch == '#') {
        T = nullptr;
    } else {
        T = new BiTNode;
        T->data = ch;
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
    }
}

// 根据中序输入创建二叉树，'#'表示空节点
void CreateBiTree(BiTree &T) {
    char ch;
    cin >> ch;
    if (ch == '#') {
        T = nullptr;
    } else {
        CreateBiTree(T->lchild);
        T = new BiTNode;
        T->data = ch;
        CreateBiTree(T->rchild);
    }

// 根据后序输入创建二叉树，'#'表示空节点
void CreateBiTree(BiTree &T) {
    char ch;
    cin >> ch;
    if (ch == '#') {
        T = nullptr;
    } else {
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
        T = new BiTNode;
        T->data = ch;
    }
   
// 计算二叉树的高度
int Depth(BiTree T) {
    if (!T) return 0;
    int m = Depth(T->lchild);
    int n = Depth(T->rchild);
    return (m > n ? m + 1 : n + 1);
}

// 统计二叉树的节点个数
int NodeCount(BiTree T) {
    if (!T) return 0;
    return NodeCount(T->lchild) + NodeCount(T->rchild) + 1;
}

// 线索二叉树的结点结构
typedef struct BiThrNode {
    TElemType data;
    BiThrNode *lchild, *rchild;
    int LTag, RTag; // 0 表示指针，1 表示线索
} BiThrNode, *BiThrTree;

// 全局变量，用于中序线索化过程中的前驱节点
BiThrNode *pre = nullptr;

// 中序线索化（递归）
void InThreading(BiThrTree p) {
    if (p) {
        InThreading(p->lchild);
        if (!p->lchild) {
            p->LTag = 1;
            p->lchild = pre;
        } else {
            p->LTag = 0;
        }
        if (pre && !pre->rchild) {
            pre->RTag = 1;
            pre->rchild = p;
        } else if (pre) {
            pre->RTag = 0;
        }
        pre = p;
        InThreading(p->rchild);
    }
}

// 构建中序线索二叉树（带头结点）
void CreateInOrderThread(BiThrTree &T) {
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
void InOrderTraverse_Thr(BiThrTree T) {
    BiThrTree p = T->lchild;
    while (p != T) {
        while (p->LTag == 0) p = p->lchild;
        cout << p->data;
        while (p->RTag == 1 && p->rchild != T) {
            p = p->rchild;
            cout << p->data;
        }
        p = p->rchild;
    }
}
```

#### 树与森林

```c++
#define MAXSIZE 100

// 双亲表示法
typedef struct{
    char data;
    int parent;
}PTNode;
typedef struct{
    PTNode nodes[MAXSIZE];
    int n;
}PTree;

// 孩子表示法
typedef struct CSNode{
    char data;
    struct CSNode* firstchild,*nextsibling;
}CSNode,*CSTree;
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

## 图

**邻接矩阵**

```c++
#include <bits/stdc++.h>
using namespace std;

#define MaxInt 32767     // 极大值
#define MVNum 100        // 顶点最大值
typedef char VerTexType; // 顶点类型定义
typedef int ArcType;     // 边类型定义

// 邻接矩阵表示法
typedef struct
{
    VerTexType vexs[MVNum];     // 顶点表
    ArcType arcs[MVNum][MVNum]; // 邻接矩阵
    int vexnum, arcnum; // 顶点数目 边数目
} AMGraph;

// 为AMGraph定位顶点
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

// 初始化邻接矩阵
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
```

**邻接表**

```c++
#include<bits/stdc++.h>
using namespace std;

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

// 为 ALGraph 定位顶点
int LocateVex(const ALGraph &G, VerTexType v) 
{
    for (int i = 0; i < G.vexnum; i++)
    {
        if (G.vertices[i].data == v)
        {
            return i;
        }
    }
    return -1;
}

// 初始化邻接表
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
        int i = LocateVex(G, v1); 
        int j = LocateVex(G, v2);

        // 添加边 v1 -> v2
        ArcNode *p1 = new ArcNode;
        p1->adjvex = j;
        p1->weight = weight;
        p1->nextarc = G.vertices[i].firstarc;
        G.vertices[i].firstarc = p1;
        
        /* 添加边 v2 -> v1（无向图必须对称）
        ArcNode *p2 = new ArcNode;
        p2->adjvex = i;
        p2->weight = weight;
        p2->nextarc = G.vertices[j].firstarc;
        G.vertices[j].firstarc = p2;
        */
    }
}
```

**十字链表**

```c++
// 十字链表表示法（有向图）
typedef struct ArcNode_OL {
    int tailvex;             // 弧尾顶点位置
    int headvex;             // 弧头顶点位置
    struct ArcNode_OL *hlink; // 指向同一弧头的下一条弧
    struct ArcNode_OL *tlink; // 指向同一弧尾的下一条弧
    int weight;              // 弧的权值
    InfoType info;        // 其他信息
} ArcNode_OL;

typedef struct VexNode_OL {
    VerTexType data;         // 顶点数据
    ArcNode_OL *firstin;     // 指向以该顶点为弧头的第一条弧
    ArcNode_OL *firstout;    // 指向以该顶点为弧尾的第一条弧
} VexNode_OL;

typedef struct {
    VexNode_OL xlist[MVNum]; // 顶点表
    int vexnum, arcnum;      // 顶点数和弧数
} OLGraph;
```

**邻接多重表**

```c++
// 邻接多重表表示法（无向图）
typedef struct EBox {
    int ivex, jvex;          // 该边依附的两个顶点位置
    struct EBox *ilink;      // 指向依附于顶点ivex的下一条边
    struct EBox *jlink;      // 指向依附于顶点jvex的下一条边
    int weight;              // 边的权值
    bool mark;             // 访问标记
    InfoType info;         // 其他信息
} EBox;

typedef struct VexBox {
    VerTexType data;         // 顶点数据
    EBox *firstedge;         // 指向第一条依附于该顶点的边
} VexBox;

typedef struct {
    VexBox adjmulist[MVNum]; // 顶点表
    int vexnum, edgenum;     // 顶点数和边数
} AMLGraph;
```

**DFS**

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

**BFS**

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

**最小生成树（MST）**

**Kruskal**

```c++
#include <iostream>
#include <queue>
#include <vector>
#include <climits>

using namespace std;

#define MVNum 100

struct AMGraph
{
    char vexs[MVNum];       // 结点
    int arcs[MVNum][MVNum]; // 边
    int vexnum, arcnum;     // 结点总数 边总数
};

struct Edge
{
    int u, v;   // 边的两个顶点索引
    int weight; // 边的权值
};

struct Compare // 优先队列排序定义 取最小
{
    bool operator()(const struct Edge &e1, const struct Edge &e2)
    {
        return e1.weight > e2.weight;
    }
};

// 并查集
int parent[MVNum];

void InitParent(int n)
{
    for (int i = 0; i < n; ++i)
    {
        parent[i] = i;
    }
}

int Find(int x)
{
    if (parent[x] != x)
    {
        parent[x] = Find(parent[x]); // Path compression
    }
    return parent[x];
}

void Union(int x, int y)
{
    int rootX = Find(x);
    int rootY = Find(y);
    if (rootX != rootY)
    {
        parent[rootX] = rootY;
    }
}

// Kruskal算法
void Kruskal(AMGraph &G)
{
    // 初始化并查集
    InitParent(G.vexnum);

    priority_queue<struct Edge, vector<struct Edge>, Compare> pq;

    // 遍历邻接矩阵，将所有有效边加入优先队列
    for (int i = 0; i < G.vexnum; ++i)
    {
        for (int j = i + 1; j < G.vexnum; ++j)
        { // 从 i+1 开始，避免重复边（如 (i,j) 和 (j,i)）
            if (G.arcs[i][j] != INT_MAX && G.arcs[i][j] > 0)
            {                            // 检查是否存在有效边（权重非无穷且大于0）
                struct Edge e;           // 创建边结构体对象
                e.u = i;                 // 设置边的起点顶点索引
                e.v = j;                 // 设置边的终点顶点索引
                e.weight = G.arcs[i][j]; // 设置边的权重
                pq.push(e);              // 将边压入优先队列
            }
        }
    }

    int edgeCount = 0; // 记录已加入最小生成树的边数
    while (!pq.empty() && edgeCount < G.vexnum - 1)
    {                             // 循环直到队列为空或边数达到顶点数-1
        struct Edge e = pq.top(); // 取出权重最小的边
        pq.pop();                 // 从优先队列中移除该边

        int rootU = Find(e.u); // 查找起点顶点所在集合的根
        int rootV = Find(e.v); // 查找终点顶点所在集合的根

        if (rootU != rootV)
        { // 若两顶点不在同一集合，加入该边不会形成环
            cout << G.vexs[e.u] << " -> " << G.vexs[e.v] << " : " << e.weight << endl;
            Union(e.u, e.v); // 合并两顶点的集合
            edgeCount++;
        }
    }

    if (edgeCount < G.vexnum - 1)
    { // 如果边数不足顶点数-1，说明图不连通
        return;
    }
}
```

**Prim**

```c++
#include <iostream>
#include <climits>

using namespace std;

#define MVNum 100

typedef char VerTexType;
typedef int ArcType;

struct AMGraph
{
    VerTexType vexs[MVNum];
    ArcType arcs[MVNum][MVNum];
    int vexnum, arcnum;
};

struct CloseEdge
{
    VerTexType adjvex; // 该顶点在生成树中的邻接顶点
    ArcType lowcost;   // 最小权值，0表示已加入生成树
} closedge[MVNum];

// 查找顶点u在G.vexs中的下标
int LocateVex(const AMGraph &G, VerTexType u)
{
    for (int i = 0; i < G.vexnum; ++i)
    {
        if (G.vexs[i] == u)
            return i;
    }
    return -1;
}

void Prim(AMGraph G, VerTexType u)
{
    int k = LocateVex(G, u);

    if (k == -1)
    {
        return;
    }

    // 初始化closedge数组
    for (int i = 0; i < G.vexnum; ++i)
    {
        if (i != k)
        {                                       // 如果不是起始顶点u
            closedge[i].adjvex = u;             // 初始时，所有顶点的最近邻接顶点都是u
            closedge[i].lowcost = G.arcs[k][i]; // 初始时，最小权值就是u到该顶点的权值
        }
        else
        {
            closedge[i].lowcost = 0; // u自身已加入生成树，lowcost设为0
        }
    }

    // 构建生成树的n-1条边
    for (int i = 1; i < G.vexnum; ++i)
    {
        // 寻找当前最小的边
        int min_cost = INT_MAX;
        int min_index = -1;
        for (int j = 0; j < G.vexnum; ++j)
        {
            if (closedge[j].lowcost > 0 && closedge[j].lowcost < min_cost)
            {
                min_cost = closedge[j].lowcost;
                min_index = j;
            }
        }

        if (min_index == -1)
        { // 图不连通，无法生成树
            return;
        }

        // 输出最小生成树的边
        cout << closedge[min_index].adjvex << " -> "
             << G.vexs[min_index] << " : " << min_cost << endl;

        // 将顶点min_index加入生成树
        closedge[min_index].lowcost = 0;

        // 更新closedge数组
        for (int j = 0; j < G.vexnum; ++j)
        {
            if (closedge[j].lowcost != 0 && G.arcs[min_index][j] < closedge[j].lowcost) // 更新到最小生成树的最短权值
            {
                closedge[j].adjvex = G.vexs[min_index];
                closedge[j].lowcost = G.arcs[min_index][j];
            }
        }
    }
}
```

**最短路径**

**Dijkstra**

```c++
#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
using namespace std;

#define MVNum 100

typedef struct
{
    char vexs[MVNum];       // 顶点表
    int arcs[MVNum][MVNum]; // 邻接矩阵
    int vexNum, arcNum;     // 节点数 边数
} AMGraph;

// 定位节点
int LocateVex(const AMGraph &G, char v)
{
    for (int i = 0; i < G.vexNum; ++i)
    {
        if (G.vexs[i] == v)
            return i;
    }
    return -1;
}

// 初始化邻接矩阵图
void CreateAMGraph(AMGraph &G)
{
    cin >> G.vexNum >> G.arcNum;
    // 输入顶点字符
    for (int i = 0; i < G.vexNum; ++i)
    {
        cin >> G.vexs[i];
    }
    // 初始化邻接矩阵
    for (int i = 0; i < MVNum; ++i)
    {
        fill(G.arcs[i], G.arcs[i] + MVNum, INT_MAX);
        G.arcs[i][i] = 0;
    }
    // 输入边信息
    for (int k = 0; k < G.arcNum; ++k)
    {
        char v1, v2;
        int w;
        cin >> v1 >> v2 >> w;
        int i = LocateVex(G, v1);
        int j = LocateVex(G, v2);
        if (i != -1 && j != -1)
        {
            G.arcs[i][j] = w;
        }
    }
}

void ShortestPath_DIJ(const AMGraph &G, char start)
{
    int v0 = LocateVex(G, start); // 将字符顶点转化为索引
    if (v0 == -1)
    {
        return;
    }

    int n = G.vexNum;        // 顶点总数
    int dist[MVNum];         // 存储源点到各点的最短距离
    int path[MVNum];         // 存储路径前驱节点
    bool S[MVNum] = {false}; // 标记顶点是否已处理

    // 初始化数组
    for (int i = 0; i < n; ++i)
    {
        dist[i] = G.arcs[v0][i]; // 初始化为源点到各点的直接距离
        if (dist[i] != INT_MAX)
        { // 可到达则设前驱为源点
            path[i] = v0;
        }
        else
        {
            path[i] = -1;
        }
    }
    dist[v0] = 0;  // 自身距离为0
    S[v0] = true;  // 标记为已处理
    path[v0] = -1; // 源点无前驱

    // 主循环：进行n-1次迭代（每次确定一个顶点的最短路径）
    for (int i = 1; i < n; i++)
    {
        int minDist = INT_MAX; // 当前未处理顶点中的最小距离
        int u = -1;            // 最小距离顶点索引（初始-1表示未找到）

        // 遍历所有顶点寻找最小值
        for (int j = 0; j < n; ++j)
        {
            // 仅处理未确定最短路径的顶点
            // 且当前顶点的距离比已记录的最小值更小
            if (!S[j] && dist[j] < minDist)
            {
                minDist = dist[j]; // 更新最小距离值
                u = j;             // 记录当前最小顶点的索引
            }
        }

        // 如果没有找到有效顶点
        if (u == -1)
            break;

        S[u] = true; // 将顶点u标记为已处理

        // 遍历所有顶点v，检查通过u到达v是否更优
        for (int v = 0; v < n; ++v)
        {
            // 仅处理未确定最短路径的顶点
            // 且存在u到v的边
            // 且新的路径距离比原有记录更短
            if (!S[v] && G.arcs[u][v] != INT_MAX && dist[u] + G.arcs[u][v] < dist[v])
            {
                dist[v] = dist[u] + G.arcs[u][v]; // 更新最短距离
                path[v] = u;                      // 记录前驱顶点为u
            }
        }
    }

    // 输出结果
    for (int i = 0; i < n; ++i)
    {
        if (dist[i] == INT_MAX)
        {
            cout << G.vexs[i] << " unreachable" << endl;
            continue;
        }

        vector<int> pathTrace;
        int cur = i;
        while (cur != -1)
        {
            pathTrace.push_back(cur);
            cur = path[cur];
        }
        reverse(pathTrace.begin(), pathTrace.end());

        cout << G.vexs[i] << " " << dist[i] << " ";
        for (size_t j = 0; j < pathTrace.size(); ++j)
        {
            if (j > 0)
                cout << "->";
            cout << G.vexs[pathTrace[j]];
        }
        cout << endl;
    }
}

int main()
{
    AMGraph G;
    CreateAMGraph(G);
    char start;
    cin >> start;
    ShortestPath_DIJ(G, start);
    return 0;
}
```

**Floyd**

```c++
#include <iostream>
#include <climits>
using namespace std;

#define MVNum 100 // 假设最大顶点数为100

const int INF = INT_MAX;

typedef struct
{
    char vexs[MVNum];       // 顶点表
    int arcs[MVNum][MVNum]; // 邻接矩阵
    int vexNum, arcNum;     // 顶点数和边数
} AMGraph;

// 定位顶点
int LocateVex(const AMGraph &G, char v)
{
    for (int i = 0; i < G.vexNum; ++i)
    {
        if (G.vexs[i] == v)
            return i;
    }
    return -1;
}

void Floyd(const AMGraph &G, int dist[][MVNum])
{
    // 初始化距离矩阵
    for (int i = 0; i < G.vexNum; ++i)
    {
        for (int j = 0; j < G.vexNum; ++j)
        {
            dist[i][j] = G.arcs[i][j];
        }
    }

    // 三重循环更新最短路径
    for (int k = 0; k < G.vexNum; ++k)
    {
        for (int i = 0; i < G.vexNum; ++i)
        {
            for (int j = 0; j < G.vexNum; ++j)
            {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][j] > dist[i][k] + dist[k][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}

void CreateAMGraph(AMGraph &G)
{
    cin >> G.vexNum >> G.arcNum;

    for (int i = 0; i < G.vexNum; ++i)
        cin >> G.vexs[i];

    for (int i = 0; i < G.vexNum; ++i)
        for (int j = 0; j < G.vexNum; ++j)
            G.arcs[i][j] = (i == j) ? 0 : INF;

    for (int k = 0; k < G.arcNum; ++k)
    {
        char v1, v2;
        int weight;
        cin >> v1 >> v2 >> weight;
        int i = LocateVex(G, v1);
        int j = LocateVex(G, v2);
        G.arcs[i][j] = weight;
    }
}

int main()
{
    AMGraph G;
    CreateAMGraph(G);

    int dist[MVNum][MVNum];
    Floyd(G, dist);

    for (int j = 0; j < G.vexNum; ++j)
    {
        if (dist[0][j] != INF)
            cout << "Distance from " << G.vexs[0] << " to " << G.vexs[j] << ": " << dist[0][j] << endl;
        else
            cout << "No path from " << G.vexs[0] << " to " << G.vexs[j] << endl;
    }
    return 0;
}
```

**拓扑排序**

```c++
#include <iostream>
#include <stack>
using namespace std;

#define MAX_VERTEX_NUM 100

// 边表结点
typedef struct ArcNode
{
    int adjvex;              // 该弧所指向的顶点的位置
    struct ArcNode *nextarc; // 指向下一条弧的指针
} ArcNode;

// 顶点表结点
typedef struct VNode
{
    int in;            // 顶点入度
    ArcNode *firstarc; // 指向第一条依附该顶点的弧的指针
} VNode, AdjList[MAX_VERTEX_NUM];

// 图结构
typedef struct
{
    AdjList vertices;   // 邻接表
    int vexnum, arcnum; // 顶点数和弧数
} ALGraph;

void TopologicalSort(ALGraph G, int topo[])
{
    int indegree[MAX_VERTEX_NUM]; // 入度数组
    stack<int> s;

    // 初始化入度数组
    for (int i = 0; i < G.vexnum; ++i)
    {
        indegree[i] = G.vertices[i].in;
        if (indegree[i] == 0)
        {
            s.push(i); // 入度为0的顶点入栈
        }
    }

    int count = 0;
    while (!s.empty())
    {                    // 判断栈是否为空
        int u = s.top(); // 获取栈顶元素
        s.pop();         // 弹出栈顶
        topo[count] = u; // 存储拓扑序列
        count++;

        // 遍历u的所有邻接点
        for (ArcNode *p = G.vertices[u].firstarc; p != nullptr; p = p->nextarc)
        {
            int v = p->adjvex;
            if (--indegree[v] == 0) // 减少入度
            {
                s.push(v); // 入栈
            }
        }
    }

    // 存在环则无法完成拓扑排序
    if (count != G.vexnum)
    {
        return;
    }
}

int main()
{
    ALGraph G;
    G.vexnum = 4;
    G.arcnum = 4;

    // 邻接表初始化
    for (int i = 0; i < G.vexnum; ++i)
    {
        G.vertices[i].in = 0;
        G.vertices[i].firstarc = nullptr;
    }

    ArcNode *arc;

    // 添加边 0->1
    arc = new ArcNode{1, nullptr};
    arc->nextarc = G.vertices[0].firstarc;
    G.vertices[0].firstarc = arc;
    G.vertices[1].in++;

    // 添加边 0->2
    arc = new ArcNode{2, nullptr};
    arc->nextarc = G.vertices[0].firstarc;
    G.vertices[0].firstarc = arc;
    G.vertices[2].in++;

    // 添加边 1->3
    arc = new ArcNode{3, nullptr};
    arc->nextarc = G.vertices[1].firstarc;
    G.vertices[1].firstarc = arc;
    G.vertices[3].in++;

    // 添加边 2->3
    arc = new ArcNode{3, nullptr};
    arc->nextarc = G.vertices[2].firstarc;
    G.vertices[2].firstarc = arc;
    G.vertices[3].in++;

    int topo[MAX_VERTEX_NUM];
    TopologicalSort(G, topo);

    for (int i = 0; i < G.vexnum; ++i)
    {
        cout << topo[i] << " ";
    }
    cout << endl;

    return 0;
}
```

**关键路径**

```c++
#include <stdio.h>
#include <stdlib.h>

#define MVNum 100 // 最大顶点数
#define OK 1
#define ERROR 0

typedef char VerTexType; // 顶点类型
typedef int ArcType;     // 边的权值类型

typedef struct
{
    VerTexType vexs[MVNum];     // 顶点表
    ArcType arcs[MVNum][MVNum]; // 邻接矩阵
    int vexnum, arcnum;         // 图的当前顶点数和边数
} AMGraph;

int LocateVex(AMGraph *G, VerTexType v)
{
    for (int i = 0; i < G->vexnum; i++)
    {
        if (G->vexs[i] == v)
        {
            return i;
        }
    }
    return -1;
}

int CreateAOEGraph(AMGraph *G)
{
    scanf("%d", &G->vexnum);
    scanf("%d", &G->arcnum);

    for (int i = 0; i < G->vexnum; i++)
    {
        scanf(" %c", &G->vexs[i]);
    }

    // 初始化邻接矩阵
    for (int i = 0; i < G->vexnum; i++)
    {
        for (int j = 0; j < G->vexnum; j++)
        {
            G->arcs[i][j] = 0;
        }
    }

    for (int k = 0; k < G->arcnum; k++)
    {
        char v1, v2;
        int weight;
        scanf(" %c %c %d", &v1, &v2, &weight);
        int i = LocateVex(G, v1);
        int j = LocateVex(G, v2);
        if (i == -1 || j == -1)
        {
            return ERROR;
        }
        G->arcs[i][j] = weight;
    }
    return OK;
}

int TopologicalOrder(AMGraph G, int *topoOrder)
{
    int inDegree[MVNum] = {0};

    // 计算入度
    for (int j = 0; j < G.vexnum; j++)
    {
        for (int i = 0; i < G.vexnum; i++)
        {
            if (G.arcs[i][j] != 0)
            {
                inDegree[j]++;
            }
        }
    }

    int queue[MVNum];
    int front = 0, rear = 0;
    for (int i = 0; i < G.vexnum; i++)
    {
        if (inDegree[i] == 0)
        {
            queue[rear++] = i;
        }
    }

    int count = 0;
    while (front != rear)
    {
        int u = queue[front++];
        topoOrder[count++] = u;

        for (int v = 0; v < G.vexnum; v++)
        {
            if (G.arcs[u][v] != 0)
            {
                if (--inDegree[v] == 0)
                {
                    queue[rear++] = v;
                }
            }
        }
    }

    if (count != G.vexnum)
    {
        return ERROR; // 存在环
    }
    return OK;
}

void CalculateVE(AMGraph G, int *topoOrder, int *ve)
{
    for (int i = 0; i < G.vexnum; i++)
    {
        ve[i] = 0;
    }

    for (int i = 0; i < G.vexnum; i++)
    {
        int u = topoOrder[i];
        for (int v = 0; v < G.vexnum; v++)
        {
            if (G.arcs[u][v] != 0 && ve[v] < ve[u] + G.arcs[u][v])
            {
                ve[v] = ve[u] + G.arcs[u][v];
            }
        }
    }
}

void CalculateVL(AMGraph G, int *topoOrder, int *ve, int *vl)
{
    int maxVE = 0;
    // 找到所有汇点的最大ve值
    for (int i = 0; i < G.vexnum; i++)
    {
        int isSink = 1;
        for (int j = 0; j < G.vexnum; j++)
        {
            if (G.arcs[i][j] != 0)
            {
                isSink = 0;
                break;
            }
        }
        if (isSink && ve[i] > maxVE)
        {
            maxVE = ve[i];
        }
    }

    // 初始化vl
    for (int i = 0; i < G.vexnum; i++)
    {
        vl[i] = maxVE;
    }

    // 逆拓扑处理
    for (int i = G.vexnum - 1; i >= 0; i--)
    {
        int u = topoOrder[i];
        for (int v = 0; v < G.vexnum; v++)
        {
            if (G.arcs[u][v] != 0)
            {
                if (vl[u] > vl[v] - G.arcs[u][v])
                {
                    vl[u] = vl[v] - G.arcs[u][v];
                }
            }
        }
    }
}

void FindCriticalPath(AMGraph G, int *ve, int *vl)
{
    for (int i = 0; i < G.vexnum; i++)
    {
        for (int j = 0; j < G.vexnum; j++)
        {
            if (G.arcs[i][j] != 0)
            {
                int e = ve[i];
                int l = vl[j] - G.arcs[i][j];
                if (e == l)
                {
                    printf("%c -> %c, 权值: %d\n", G.vexs[i], G.vexs[j], G.arcs[i][j]);
                }
            }
        }
    }
}

int main()
{
    AMGraph G;
    int topoOrder[MVNum];

    if (TopologicalOrder(G, topoOrder) == ERROR)
    {
        return 1;
    }

    int ve[MVNum], vl[MVNum];
    CalculateVE(G, topoOrder, ve);
    CalculateVL(G, topoOrder, ve, vl);

    FindCriticalPath(G, ve, vl);

    return 0;
}
```

### 查找

#### 线性表

**顺序查找**

```c++
typedef struct{
    KeyType key;
    InfoType otherinfo;
}ElemType;

typedef struct{
    ElemType *R;
    int length;
}SSTable;

int Search_Seq(SSTable ST,KeyType key){
    for(int i=ST.length;i>=1;i--){
        if(ST.R[i],key==key){
            return i;
        }
    }
    return 0;
}
```

**二分查找**

```c++
typedef struct{
    KeyType key;
    InfoType otherinfo;
}ElemType;

typedef struct{
    ElemType *R;
    int length;
}SSTable;

int Search_Bin(SSTable ST,KeyType key){
    int low = 1;
    int high = ST.length;
    while(low<=high){
        int mid = (low+high) << 1;
        if(key==ST.R[mid].key){
            return mid;
        }
        else if(key<ST.R[mid].key){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return 0;
}
```

**分块查找**

```c++
typedef struct{
    KeyType key;
    InfoType otherinfo;
}ElemType;

typedef struct{
    ElemType *R;
    int length;
}SSTable;

typedef struct {
    KeyType max_key; // 块内最大关键字
    int start;       // 块起始位置
    int end;         // 块结束位置
} IndexBlock;

int BlockSearch(SSTable ST, IndexBlock index[], int index_len, KeyType key) {
    int low = 0, high = index_len - 1;
    int block_idx = -1;

    // 二分查找确定所在块
    while (low <= high) {
        int mid = (low + high) / 2;
        if (key <= index[mid].max_key) {
            block_idx = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    if (block_idx == -1) 
        return -1;

    // 在块内顺序查找
    for (int i = index[block_idx].start; i <= index[block_idx].end; ++i) {
        if (ST.R[i].key == key)
            return i; 
    }

    return -1; 
}
```

#### 树表

**二叉排序树**

```c++
typedef struct{
    KeyType key;
    InfoType otherinfo;
}ElemType;

typedef struct BSTNode{
    ElemType data;
    struct BSTNode *lchild,*rchild;
}BSTNode,*BSTree;

BSTree SearchBST(BSTree T,KeyType key){
    if(!T || key==T->data.key){
        return T;
    }
    else if(key<T->data.key){
        return SearchBST(T->lchild,key);
    }
    else{
        return SearchBST(T->rchild,key);
    }
}

void InsertBST(BSTree &T,ElemType e){
    if(!T){
        BSTNode S = new BSTNode;
        S->data = e;
        S->lchild = NULL;
        S->rchild = NULL;
        T = S;
    }
    else if(e.key<T->data.key){
        InsertBST(T->lchild,e);
    }
    else if(e.key>T->data.key){
        InsertBST(T->rchild,e);
    }
}

void CreateBST(BSTree &T){
    int e;
    T = NULL;
    cin >> e;
    while(e.key!=-1){
        InsertBST(T,e);
        cin >> e;
    }
}

void DeleteBST(BSTree &T, KeyType key) {
    BSTree p = T;      // 当前节点指针
    BSTree f = NULL;   // 父节点指针

    // 查找删除节点
    while (p) {
        if (p->data.key == key) break;
        f = p;
        if (p->data.key > key) p = p->lchild;
        else p = p->rchild;
    }
    if (!p) return;    

    BSTree q = p;      // 辅助指针 q 指向待删除节点

    // Case 1: 节点 p 是叶子节点或仅有一个子树
    if (!p->lchild) {        // 左子树为空，用右子树替换
        if (!f) T = p->rchild;              // p 是根节点
        else if (f->lchild == p) f->lchild = p->rchild;
        else f->rchild = p->rchild;
        free(q);
    } else if (!p->rchild) { // 右子树为空，用左子树替换
        if (!f) T = p->lchild;              // p 是根节点
        else if (f->lchild == p) f->lchild = p->lchild;
        else f->rchild = p->lchild;
        free(q);
    } else {
        // Case 2: 节点 p 有两个子树，找左子树的最右节点（前驱）
        BSTree s = p->lchild;
        BSTree parent_s = p; // s 的父节点
        while (s->rchild) {
            parent_s = s;
            s = s->rchild;
        }

        // 用前驱 s 替换 p 的值
        p->data = s->data;

        // 删除前驱节点 s（此时 s 至多有一个左子树）
        if (parent_s == p) parent_s->lchild = s->lchild;
        else parent_s->rchild = s->lchild;
        free(s);
    }
}
```

#### 哈希表

```c++
#include <iostream>
#include <vector>
#include <list>
#include <string>
using namespace std;

// 拉链法
static const int tableSize = 10;

// 哈希表数组，包含链表来处理冲突
vector<list<pair<int, string>>> chainTable(tableSize);

// 哈希函数
int hashFunction(int key)
{
    return key % tableSize;
}

// 插入操作（拉链法）
void insertChaining(int key, string value)
{
    int index = hashFunction(key);
    chainTable[index].push_back(make_pair(key, value));
}

// 查找操作（拉链法）
string searchChaining(int key)
{
    int index = hashFunction(key);
    for (auto &p : chainTable[index])
    {
        if (p.first == key)
            return p.second;
    }
    return "";
}

// 删除操作（拉链法）
void removeChaining(int key)
{
    int index = hashFunction(key);
    auto &chain = chainTable[index];
    for (auto it = chain.begin(); it != chain.end(); ++it)
    {
        if (it->first == key)
        {
            chain.erase(it);
            return;
        }
    }
}

// 开放定址法（以线性探测为例）
enum EntryState { EMPTY, OCCUPIED, DELETED };

struct HashEntry {
    int key;
    string value;
    EntryState state;
};

// 哈希表数组
vector<HashEntry> openTable(tableSize, {0, "", EMPTY});

// 哈希函数（同前）
int hashFunctionLP(int key)
{
    return key % tableSize;
}

// 插入操作（线性探测）
void insertLinear(int key, string value)
{
    int idx = hashFunctionLP(key);
    for (int i = 0; i < tableSize; ++i)
    {
        int probe = (idx + i) % tableSize;
        if (openTable[probe].state == EMPTY || openTable[probe].state == DELETED)
        {
            openTable[probe].key = key;
            openTable[probe].value = value;
            openTable[probe].state = OCCUPIED;
            return;
        }
    }
}

// 查找操作
string searchLinear(int key)
{
    int idx = hashFunctionLP(key);
    for (int i = 0; i < tableSize; ++i)
    {
        int probe = (idx + i) % tableSize;
        if (openTable[probe].state == EMPTY)
            return "";
        if (openTable[probe].state == OCCUPIED && openTable[probe].key == key)
            return openTable[probe].value;
    }
    return "";
}

// 删除操作
void removeLinear(int key)
{
    int idx = hashFunctionLP(key);
    for (int i = 0; i < tableSize; ++i)
    {
        int probe = (idx + i) % tableSize;
        if (openTable[probe].state == EMPTY)
            return;
        if (openTable[probe].state == OCCUPIED && openTable[probe].key == key)
        {
            openTable[probe].state = DELETED;
            return;
        }
    }
}
```

#### STL

**unordered_set**

- `insert(x)` 向集合中插入元素 x（若已存在，则不插入）
- `erase(x)` 从集合中删除元素 x
- `find(x)` 查找元素 x，返回迭代器；若未找到，返回 `end()`
- `count(x)` 统计元素 x 在集合中出现的次数（要么 0，要么 1）
- `size()` 查询集合中元素数量
- `empty()` 判断集合是否为空
- `clear()` 清空集合中的所有元素

```c++
#include <iostream>
#include <unordered_set>
using namespace std;

    unordered_set<int> us;
    us.insert(3);
    us.insert(1);
    us.insert(4)
    us.insert(1);  
    cout << us.size() << endl; 
    cout << (us.find(2) != us.end()) << endl;
    cout << us.count(1) << endl;  
    us.erase(3);
    us.clear();
    cout << us.empty() << endl; 
```

**unordered_map**

- `insert({k, v})` 向映射中插入键值对 `(k, v)`（若键已存在，不插入）
- `erase(k)` 删除键为 k 的元素
- `find(k)` 查找键为 k 的元素，返回指向该元素的迭代器；若未找到，返回 `end()`
- `count(k)` 统计键 k 在映射中出现的次数（要么 0，要么 1）
- `operator[](k)` 如果键 k 存在，返回对应的值；否则插入一个键为 k、值为默认构造的元素并返回其引用
- `size()` 查询映射中元素数量
- `empty()` 判断映射是否为空
- `clear()` 清空映射中的所有元素

```c++
#include <iostream>
#include <unordered_map>
using namespace std;

    unordered_map<string, int> um;
    um.insert({"apple", 3});
    um.insert(make_pair("banana", 5));
    um["cherry"] = 2;  
    cout << um.size() << endl; 
    cout << um["cherry"] << endl; 
    auto it = um.find("banana");
    if (it != um.end()) {
        cout << it->second << endl;  
    }
    um.erase("apple");
    um.clear();
    cout << um.empty() << endl; 
```

### 排序

**插入排序**

```c++
#include <iostream>
using namespace std;

typedef struct
{
    int *r;
    int length;
} SqList;

void InsertSort(SqList &L)
{
    for (int i = 1; i < L.length; i++)
    {
        int temp = L.r[i]; // 暂存待排序元素
        int j = i - 1;     // 指向已排序部分的最后一个元素
        // 从后向前查找插入位置，并后移元素
        while (j >= 0 && L.r[j] > temp)
        {
            L.r[j + 1] = L.r[j];
            j--;
        }
        L.r[j + 1] = temp; // 插入到正确位置
    }
}

void BinaryInsertSort(SqList &L)
{
    for (int i = 1; i < L.length; i++)
    {
        int temp = L.r[i];
        int start = 0;
        int end = i - 1;
        // 二分查找mid
        while (start <= end)
        {
            int mid = (start + end) / 2;
            if (L.r[mid] > temp)
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }

        // 将插入位置后的元素后移
        for (int j = i - 1; j >= start; j--)
        {
            L.r[j + 1] = L.r[j];
        }

        // 插入元素到正确位置
        L.r[start] = temp;
    }
}
```

**希尔排序**

```c++
#include <iostream>
using namespace std;

#define MAXSIZE 100

typedef struct
{
    int data[MAXSIZE];
    int length;
} Sqlist;

void ShellSort(Sqlist &L)
{
    // 初始间隔（gap）为长度的一半，逐步缩小间隔直到1
    for (int gap = L.length / 2; gap > 0; gap /= 2)
    {
        // 对每个子序列进行插入排序
        for (int i = gap; i < L.length; i++)
        {
            int temp = L.data[i]; // 当前待插入元素
            int j;
            // 插入排序逻辑：将元素插入到对应子序列的正确位置
            for (j = i; j >= gap && L.data[j - gap] > temp; j -= gap)
            {
                L.data[j] = L.data[j - gap]; // 将前一个元素后移
            }
            L.data[j] = temp; // 插入到正确位置
        }
    }
}
```

**冒泡排序**

```c++
#include <iostream>
using namespace std;

#define MAXSIZE 100

typedef struct
{
    int data[MAXSIZE];
    int length;
} Sqlist;

void bubble(Sqlist &L)
{
    for (int i = L.length - 1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (L.data[j] > L.data[j + 1])
            {
                swap(L.data[j], L.data[j + 1]);
            }
        }
    }
}
```

**快速排序**

```c++
#include <iostream>

using namespace std;

void QuickSort(int a[], int m, int n)
{
    if (m >= n)
        return;

    int low = m;
    int high = n;
    int pivot = a[(m + n) / 2];
    while (low <= high)
    {
        while (a[low] < pivot)
            low++;
        while (a[high] > pivot)
            high--;
        if (low <= high)
        {
            swap(a[low], a[high]);
            low++;
            high--;
        }
    }
    QuickSort(a, m, high);
    QuickSort(a, low, n);
}
```

**选择排序**

```c++
#include <iostream>
using namespace std;

#define MAXSIZE 100
typedef struct
{
    int data[MAXSIZE];
    int length;
} Sqlist;

void Select(Sqlist &L)
{
    for (int i = 0; i < L.length - 1; i++)
    {
        int k = i;
        for (int j = i + 1; j < L.length; j++)
        {
            if (L.data[j] < L.data[k])
            {
                k = j;
            }
        }
        if (k != i)
        {
            swap(L.data[i], L.data[k]);
        }
    }
}
```

**堆排序**

```c++
#include <iostream>
using namespace std;

#define MAXSIZE 100

typedef struct
{
    int data[MAXSIZE];
    int length;
} Sqlist;

void HeapAdjust(Sqlist &L, int s, int m) // s: 待调整的子树根节点下标  m：最后一个元素的下标（调整范围上限）
{
    int rc = L.data[s];
    // 沿关键字较大的子节点向下筛选
    for (int j = 2 * s + 1; j <= m; j = 2 * j + 1) // 完全二叉树 左孩子2k+1
    {
        // 比较左右孩子，j指向较大的孩子
        if (j < m && L.data[j] < L.data[j + 1])
            j++; // 右孩子更大，j指向右孩子

        // 若根节点已比最大孩子大，则调整完成
        if (rc >= L.data[j])
            break;

        L.data[s] = L.data[j]; // 将较大孩子值上移
        s = j;                 // s指向下一层待比较位置
    }
    L.data[s] = rc; // 将最初根节点值放入最终位置
}

void CreateHeap(Sqlist &L)
{
    // 从最后一个非叶子节点开始向前调整
    for (int i = L.length / 2 - 1; i >= 0; i--)
    {
        HeapAdjust(L, i, L.length - 1); // 调整以i为根的子树
    }
}

void HeapSort(Sqlist &L)
{
    CreateHeap(L); // 初始建堆

    // 依次将堆顶元素（最大值）与末尾元素交换并调整堆
    for (int i = L.length - 1; i > 0; i--)
    {
        swap(L.data[0], L.data[i]); // 堆顶最大值交换到末尾
        HeapAdjust(L, 0, i - 1);    // 调整剩余元素为新堆
    }
}
```

**归并排序**

```c++
#include <iostream>
using namespace std;
#define MAXSIZE 100

typedef struct
{
    int data[MAXSIZE];
    int length;
} Sqlist;

void Merge(Sqlist &L, int low, int mid, int high)
{
    int *temp = new int[high - low + 1];
    int i = low;     // 左半部分起始索引
    int j = mid + 1; // 右半部分起始索引
    int k = 0;       // 临时数组索引

    // 合并元素到临时数组
    while (i <= mid && j <= high)
    {
        if (L.data[i] <= L.data[j])
            temp[k++] = L.data[i++];
        else
            temp[k++] = L.data[j++];
    }

    // 处理剩余元素
    while (i <= mid)
        temp[k++] = L.data[i++];
    while (j <= high)
        temp[k++] = L.data[j++];

    // 将排序好的数据拷贝回原数组
    for (i = low, k = 0; i <= high; i++, k++)
        L.data[i] = temp[k];

    delete[] temp; // 释放临时数组
}

// 递归分治函数
void MSort(Sqlist &L, int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2; // 计算中间位置
        MSort(L, low, mid);         // 递归左半部分
        MSort(L, mid + 1, high);    // 递归右半部分
        Merge(L, low, mid, high);   // 合并已排序部分
    }
}

// 归并排序入口函数
void MergeSort(Sqlist &L)
{
    if (L.length <= 0)
        return;
    MSort(L, 0, L.length - 1); // 调用递归排序
}
```

**基数排序**

```c++
#include <iostream>

using namespace std;

#define MAXSIZE 100

typedef struct
{
    int data[MAXSIZE];
    int length;
} Sqlist;

void RadixSort(Sqlist &L)
{
    if (L->length <= 1)
        return;

    // 获取最大值以确定最高位数
    int max_num = L->data[0];
    for (int i = 1; i < L->length; ++i)
    {
        if (L->data[i] > max_num)
            max_num = L->data[i];
    }

    // 从低位到高位依次进行排序
    for (int exp = 1; max_num / exp > 0; exp *= 10)
    {
        int count[10] = {0}; // 统计每个桶的元素个数
        int output[MAXSIZE]; // 临时存放排序结果

        // 统计当前位的出现次数
        for (int i = 0; i < L->length; ++i)
        {
            int digit = (L->data[i] / exp) % 10;
            count[digit]++;
        }

        // 计算前缀和，确定各桶的右边界
        for (int j = 1; j < 10; ++j)
        {
            count[j] += count[j - 1];
        }

        // 逆序遍历，保证稳定性
        for (int i = L->length - 1; i >= 0; --i)
        {
            int digit = (L->data[i] / exp) % 10;
            output[count[digit] - 1] = L->data[i];
            count[digit]--;
        }

        // 将排序结果复制回原数组
        for (int i = 0; i < L->length; ++i)
        {
            L->data[i] = output[i];
        }
    }
}
```

