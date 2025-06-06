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