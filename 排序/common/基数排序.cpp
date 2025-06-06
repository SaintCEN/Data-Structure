#include <iostream>

using namespace std;

#define MAXSIZE 100

typedef struct
{
    int data[MAXSIZE];
    int length;
} Sqlist;

void RadixSort(Sqlist &L)
{
    if (L->length <= 1)
        return;

    // 获取最大值以确定最高位数
    int max_num = L->data[0];
    for (int i = 1; i < L->length; ++i)
    {
        if (L->data[i] > max_num)
            max_num = L->data[i];
    }

    // 从低位到高位依次进行排序
    for (int exp = 1; max_num / exp > 0; exp *= 10)
    {
        int count[10] = {0}; // 统计每个桶的元素个数
        int output[MAXSIZE]; // 临时存放排序结果

        // 统计当前位的出现次数
        for (int i = 0; i < L->length; ++i)
        {
            int digit = (L->data[i] / exp) % 10;
            count[digit]++;
        }

        // 计算前缀和，确定各桶的右边界
        for (int j = 1; j < 10; ++j)
        {
            count[j] += count[j - 1];
        }

        // 逆序遍历，保证稳定性
        for (int i = L->length - 1; i >= 0; --i)
        {
            int digit = (L->data[i] / exp) % 10;
            output[count[digit] - 1] = L->data[i];
            count[digit]--;
        }

        // 将排序结果复制回原数组
        for (int i = 0; i < L->length; ++i)
        {
            L->data[i] = output[i];
        }
    }
}