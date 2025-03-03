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