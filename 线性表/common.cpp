#include <bits/stdc++.h>
using namespace std;

#define MAXSIZE 100
typedef int ElemType;
typedef struct
{
    ElemType *elem;
    int length;
} Sqlist;

// 初始化
void InitList(Sqlist &L)
{
    L.elem = new ElemType[MAXSIZE];
    if (!L.elem)
        return;
    L.length = 0;
}

// 取值
void GetElem(Sqlist L, int i, ElemType &e)
{
    if (i < 1 || i > L.length)
        return;
    e = L.elem[i - 1];
}

// 定位
int LocateElem(Sqlist L, ElemType e)
{
    for (int i = 0; i < L.length; i++)
    {
        if (L.elem[i] == e)
            return i + 1;
    }
    return 0;
}

// 插入
void InsertElem(Sqlist &L, int i, ElemType e)
{
    if (i < 1 || i > L.length + 1)
        return;
    if (L.length == MAXSIZE)
        return;
    for (int j = L.length - 1; j >= i - 1; j--)
    {
        L.elem[j + 1] = L.elem[j];
    }
    L.elem[i - 1] = e;
    L.length++;
}

// 删除
void DeleteElem(Sqlist &L, int i)
{
    if (i < 1 || i > L.length)
        return;
    for (int j = i; j < L.length; j++)
    {
        L.elem[j - 1] = L.elem[j];
    }
    L.length--;
}

// 删除k个
void DeleteKElem(Sqlist &L, int i, int k)
{
    if (i < 1 || k < 0 || i + k > L.length + 1)
    {
        return;
    }
    else
    {
        if (k == 0)
            return;
        for (int j = i + k; j <= L.length; j++)
        {
            L.elem[j - k] = L.elem[j];
        }
        L.length -= k;
    }
}