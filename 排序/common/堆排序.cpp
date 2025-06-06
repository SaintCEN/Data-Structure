#include <iostream>
using namespace std;

#define MAXSIZE 100

typedef struct
{
    int data[MAXSIZE];
    int length;
} Sqlist;

void HeapAdjust(Sqlist &L, int s, int m) // s: 待调整的子树根节点下标  m：最后一个元素的下标（调整范围上限）
{
    int rc = L.data[s];
    // 沿关键字较大的子节点向下筛选
    for (int j = 2 * s + 1; j <= m; j = 2 * j + 1) // 完全二叉树 左孩子2k+1
    {
        // 比较左右孩子，j指向较大的孩子
        if (j < m && L.data[j] < L.data[j + 1])
            j++; // 右孩子更大，j指向右孩子

        // 若根节点已比最大孩子大，则调整完成
        if (rc >= L.data[j])
            break;

        L.data[s] = L.data[j]; // 将较大孩子值上移
        s = j;                 // s指向下一层待比较位置
    }
    L.data[s] = rc; // 将最初根节点值放入最终位置
}

void CreateHeap(Sqlist &L)
{
    // 从最后一个非叶子节点开始向前调整
    for (int i = L.length / 2 - 1; i >= 0; i--)
    {
        HeapAdjust(L, i, L.length - 1); // 调整以i为根的子树
    }
}

void HeapSort(Sqlist &L)
{
    CreateHeap(L); // 初始建堆

    // 依次将堆顶元素（最大值）与末尾元素交换并调整堆
    for (int i = L.length - 1; i > 0; i--)
    {
        swap(L.data[0], L.data[i]); // 堆顶最大值交换到末尾
        HeapAdjust(L, 0, i - 1);    // 调整剩余元素为新堆
    }
}