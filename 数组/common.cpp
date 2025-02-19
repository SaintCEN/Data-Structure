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
        cout << "Element 5 found at position: " << pos << endl;
    } else {
        cout << "Element 5 not found" << endl;
    }

    InsertElem(L, 3, 10);
    cout << "After insertion: ";
    for (int i = 0; i < L.length; i++) {
        cout << L.elem[i] << " ";
    }
    cout << endl;

    DeleteElem(L, 2);
    cout << "After deletion: ";
    for (int i = 0; i < L.length; i++) {
        cout << L.elem[i] << " ";
    }
    cout << endl;

    return 0;
}