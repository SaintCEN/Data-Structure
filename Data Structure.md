# Data Structure

### 线性表

#### C++

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
//主函数
int main() {
    Sqlist L;
    int n;
    cin >> n;
    InitList(L);
    for (int i = 0; i < n; i++) {
        int s;
        cin >> s;
        L.elem[i] = s;
        L.length++;
    }

    int element;
    GetElem(L, 2, element);
    cout << "2nd element: " << element << endl;

    int pos = LocateElem(L, 5);
    if (pos) {
        cout << pos << endl;
    } else {
        cout << "not found" << endl;
    }

    InsertElem(L, 3, 10);
    for (int i = 0; i < L.length; i++) {
        cout << L.elem[i] << " ";
    }
    cout << endl;

    DeleteElem(L, 2);
    for (int i = 0; i < L.length; i++) {
        cout << L.elem[i] << " ";
    }
    cout << endl;

    return 0;
}
```

#### python

```python
class Sqlist:
    MAXSIZE = 100

    def __init__(self):
        self.elem = [0] * Sqlist.MAXSIZE  
        self.length = 0              

    def get_element(self, i):
        if i < 1 or i > self.length:
            return None 
        return self.elem[i - 1]

    def find_element(self, e):
        for idx in range(self.length):
            if self.elem[idx] == e:
                return idx + 1  
        return 0

    def insert_element(self, i, e):
        if i < 1 or i > self.length + 1:
            return  
        if self.length >= Sqlist.MAXSIZE:
            return  
        self.elem.insert(i - 1, e)
        self.length += 1

    def delete_element(self, i):
        if i < 1 or i > self.length:
            return 
        del self.elem[i - 1]
        self.length -= 1


def main():
    sqlist = Sqlist()
    while True:
        print("1. 获取元素")
        print("2. 查找元素")
        print("3. 插入元素")
        print("4. 删除元素")
        print("5. 退出程序")
        choice = input()
        if choice == '1':
            i = int(input())
            result = sqlist.get_element(i)
            if result is not None:
                print(result)
            else:
                print("Invalid")
        elif choice == '2':
            e = int(input())
            pos = sqlist.find_element(e)
            if pos != 0:
                print(pos)
            else:
                print("Invalid.")
        elif choice == '3':
            insert_pos = int(input())
            value = int(input())
            sqlist.insert_element(insert_pos, value)
        elif choice == '4':
            delete_pos = int(input())
            sqlist.delete_element(delete_pos)
        elif choice == '5':
            break
        else:
            print("Invalid.")

if __name__ == "__main__":
    main()

```

### 单链表

#### c++

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

//主函数
int main() {
    Node* L;
    InitList(L);

    createList_R(L, 5); 
    insertNode(L, 3, 10); 
    deleteNode(L, 2);

    ElemType e;
    GetElem(L, 2, e); 
    cout << e << endl;

    Node* found = LocateNode(L, 10); 
    if (found) {
        cout << "found" << endl;
    } else {
        cout << "not found" << endl;
    }
    return 0;
}
```

#### python

```python
class Node:
    def __init__(self, data):
        self.next = None
        self.data = data

class LinkedList:
    def __init__(self):
        self.head = None

    def GetElem(self, i):
        p = self.head
        j = 0
        while p and j < i:
            p = p.next
            j += 1
        if not p or j > i:
            return None
        return p.data

    def insert(self, i, e):
        p = self.head
        j = 0
        while p and j < i - 1:
            p = p.next
            j += 1
        if not p or j > i - 1:
            return
        s = Node(e)
        s.next = p.next
        p.next = s

    def delete(self, i):
        p = self.head
        j = 0
        while p and j < i - 1:
            p = p.next
            j += 1
        if not p or not p.next or j > i - 1:
            return
        q = p.next
        p.next = q.next
        del q

    def create_H(self, n):
        self.head = Node(None)
        for _ in range(n):
            data = int(input("Enter data: "))
            p = Node(data)
            p.next = self.head.next
            self.head.next = p

    def create_R(self, n):
        self.head = Node(None)
        r = self.head
        for _ in range(n):
            data = int(input())
            p = Node(data)
            p.next = None
            r.next = p
            r = p

    def print_list(self):
        p = self.head.next
        while p:
            print(p.data, end=" -> ")
            p = p.next
        print("None")

def main():
    ll = LinkedList()
    n = int(input())
    ll.create_R(n)
    ll.print_list()

    ll.insert(2, 10)
    ll.print_list()

    ll.delete(1)
    ll.print_list()

    elem = ll.GetElem(1)
    print(elem)

if __name__ == "__main__":
    main()
```

### 双链表

#### c++

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

int main() {
    DulNode* head = createList(5);
    traverseForward(head);
    traverseBackward(head);
    insertNode(head, 2, 99);
    deleteNode(head, 3);
    return 0;
}
```

#### python

```python
class DulNode:
    def __init__(self, data=None):
        self.data = data
        self.prior = None
        self.next = None

# 初始化双链表
def init_list():
    head = DulNode()
    return head

# 创建双链表
def create_list(n):
    head = init_list()
    p = head
    for i in range(n):
        new_node = DulNode()
        new_node.data = int(input())
        new_node.prior = p
        new_node.next = None
        p.next = new_node
        p = new_node
    return head

# 插入操作
def insert_node(head, pos, value):
    p = head
    i = 0
    while p and i < pos:
        p = p.next
        i += 1
    if not p or i > pos:
        print("Invalid.")
        return
    new_node = DulNode(value)
    new_node.next = p.next
    new_node.prior = p
    if p.next:
        p.next.prior = new_node
    p.next = new_node

# 删除操作
def delete_node(head, pos):
    p = head.next
    i = 0
    while p and i < pos:
        p = p.next
        i += 1
    if not p or i > pos:
        print("Invalid.")
        return
    if p.prior:
        p.prior.next = p.next
    if p.next:
        p.next.prior = p.prior
    del p

# 正向遍历
def traverse_forward(head):
    p = head.next
    while p:
        print(p.data, end=" ")
        p = p.next
    print()

# 反向遍历
def traverse_backward(head):
    p = head
    while p.next:
        p = p.next
    while p != head:
        print(p.data, end=" ")
        p = p.prior
    print()

if __name__ == "__main__":
    head = create_list(5)
    traverse_forward(head)
    traverse_backward(head)
    insert_node(head, 2, 99)
    delete_node(head, 3)
```

### 栈

