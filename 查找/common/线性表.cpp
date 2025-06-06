#include <bits/stdc++.h>
using namespace std;

typedef int KeyType;
typedef char InfoType;

typedef struct
{
    KeyType key;
    InfoType otherinfo;
} ElemType;

typedef struct
{
    ElemType *R;
    int length;
} SSTable;

int Search_Seq(SSTable ST, KeyType key)
{
    for (int i = ST.length; i >= 1; i--)
    {
        if (ST.R[i], key == key)
        {
            return i;
        }
    }
    return 0;
}

int Search_Bin(SSTable ST, KeyType key)
{
    int low = 1;
    int high = ST.length;
    while (low <= high)
    {
        int mid = (low + high) << 1;
        if (key == ST.R[mid].key)
        {
            return mid;
        }
        else if (key < ST.R[mid].key)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return 0;
}

typedef struct
{
    KeyType max_key; // 块内最大关键字
    int start;       // 块起始位置
    int end;         // 块结束位置
} IndexBlock;

int BlockSearch(SSTable ST, IndexBlock index[], int index_len, KeyType key)
{
    int low = 0, high = index_len - 1;
    int block_idx = -1;

    // 二分查找确定所在块
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (key <= index[mid].max_key)
        {
            block_idx = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    if (block_idx == -1)
        return -1;

    // 在块内顺序查找
    for (int i = index[block_idx].start; i <= index[block_idx].end; ++i)
    {
        if (ST.R[i].key == key)
            return i;
    }

    return -1;
}