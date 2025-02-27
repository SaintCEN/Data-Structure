/*
//递归
#include <stdio.h>
int josephus(int n, int m, int k) {
    if (n == 1) {
        return m;
    } else {
        return (josephus(n - 1, m, k) + k) % n;
    }
}
int main() {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    int result = josephus(n, m - 1, k) + 1;
    printf("%d\n", result);
    return 0;
}
*/
/*
//队列
#include <iostream>
#include <queue>
using namespace std;

int josephus(int n, int m, int k) {
    queue<int> q;
    for (int i = m; i <= n; i++) {
        q.push(i);
    }
    for (int i = 1; i < m; i++) {
        q.push(i);
    }
    while (q.size() > 1) {
        for (int i = 1; i < k; i++) {
            int front = q.front();
            q.pop();
            q.push(front);  
        }
        q.pop();  
    }
    return q.front();
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    int result = josephus(n, m, k);
    cout << result << endl;
    return 0;
}
*/
//链表
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

Node* createList(int n) {
    Node* head = createNode(1);
    Node* prev = head;
    for (int i = 2; i <= n; i++) {
        Node* newNode = createNode(i);
        prev->next = newNode;
        prev = newNode;
    }
    prev->next = head; 
    return head;
}

int josephus(int n, int k) {
    if (n == 1) {
        return 1;
    }

    Node* head = createList(n);
    Node* current = head;
    Node* prev = nullptr;

    while (n > 1) {
        for (int i = 1; i < k; i++) {
            prev = current;
            current = current->next;
        }

        prev->next = current->next;
        delete current;
        current = prev->next;
        n--;
    }

    int result = current->data;
    delete current;
    return result;
}

int main() {
    int n, k;
    cin >> n;
    cin >> k;

    int survivor = josephus(n, k);
    cout << survivor << endl;

    return 0;
}
