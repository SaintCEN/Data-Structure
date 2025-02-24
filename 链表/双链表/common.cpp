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
        cout << "请输入第" << i + 1 << "个元素的值: ";
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
        cout << "插入位置无效" << endl;
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
        cout << "删除位置无效" << endl;
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
    cout << "正向遍历: ";
    traverseForward(head);
    cout << "反向遍历: ";
    traverseBackward(head);

    insertNode(head, 2, 99);
    cout << "插入后的正向遍历: ";
    traverseForward(head);

    deleteNode(head, 3);
    cout << "删除后的正向遍历: ";
    traverseForward(head);

    return 0;
}