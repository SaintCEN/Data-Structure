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