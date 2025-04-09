#include <iostream>
#include <cstring>
using namespace std;

typedef struct
{
    int weight;
    int parent, lchild, rchild;
} HTNode, *HuffmanTree;

void Select(HTNode *HT, int n, int &s1, int &s2)
{
    int min1 = INT_MAX, min2 = INT_MAX;
    s1 = s2 = 0;
    for (int i = 1; i <= n; i++)
    {
        if (HT[i].parent == 0)
        {
            if (HT[i].weight < min1)
            {
                min2 = min1;
                s2 = s1;
                min1 = HT[i].weight;
                s1 = i;
            }
            else if (HT[i].weight < min2)
            {
                min2 = HT[i].weight;
                s2 = i;
            }
        }
    }
}

void CreateHuffmanTree(HuffmanTree &T, int n)
{
    if (n <= 1)
        return;
    int m = 2 * n - 1;
    HTNode *HT = new HTNode[m + 1];

    for (int i = 1; i <= m; i++)
    {
        HT[i].parent = 0;
        HT[i].lchild = 0;
        HT[i].rchild = 0;
    }

    for (int i = 1; i <= n; i++)
    {
        cin >> HT[i].weight; // 叶子结点
    }

    for (int i = n + 1; i <= m; i++) // 中间节点
    {
        int s1, s2;
        Select(HT, i - 1, s1, s2); // i-1 包括新创建的中间节点
        HT[s1].parent = i;
        HT[s2].parent = i;
        HT[i].lchild = s1;
        HT[i].rchild = s2;
        HT[i].weight = HT[s1].weight + HT[s2].weight;
    }
}

typedef char **HuffmanCode;
void CreateHuffmanCode(HuffmanTree HT, HuffmanCode &HC, int n)
{
    HC = new char *[n + 1];
    char *cd = new char[n];
    cd[n - 1] = '\0';

    for (int i = 1; i <= n; i++)
    {
        int start = n - 1;
        int c = i;
        int f = HT[i].parent;
        while (f != 0)
        {
            start--;
            if (HT[f].lchild == c)
            {
                cd[start] = '0';
            }
            else
            {
                cd[start] = '1';
            }
            c = f;
            f = HT[f].parent;
        }
        HC[i] = new char[n - start];
        strcpy(HC[i], &cd[start]);
    }
    delete[] cd;
}