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