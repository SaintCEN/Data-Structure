#include<bits/stdc++.h>
using namespace std;

typedef struct Node {
    int data;
    Node* next;
} Node;

void InitList(Node* &L) {
    L = new Node;
    L->next = NULL;
}

void CreateList(Node* &L) {
    int s;
    Node* p = L;
    cin >> s;
    while (s != -1) {
        p->next = new Node;
        p = p->next;
        p->data = s;
        p->next = NULL;
        cin >> s;
    }
}

void MergeList(Node* &La, Node* &Lb, Node* &Lc) {
    Node* pa = La->next;
    Node* pb = Lb->next;
    Lc = La;
    Node* pc = Lc;
    while (pa && pb) {
        if (pa->data <= pb->data) {
            pc->next = pa;
            pc = pa;
            pa = pa->next;
        } else {
            pc->next = pb;
            pc = pb;
            pb = pb->next;
        }
    }
    pc->next = pa ? pa : pb;
    delete Lb;
}

void PrintList(Node* L) {
    Node* p = L->next;
    if (!p) {
        cout << "NULL";
    } else {
        while (p) {
            cout << p->data;
            if (p->next) cout << " ";
            p = p->next;
        }
    }
    cout << endl;
}

int main() {
    Node* L1 = NULL;
    Node* L2 = NULL;
    InitList(L1);
    InitList(L2);
    CreateList(L1);
    CreateList(L2);
    Node* L3 = NULL;
    MergeList(L1, L2, L3);
    PrintList(L3);
    return 0;
}