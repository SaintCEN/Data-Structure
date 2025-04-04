#include <stdio.h>
#include <stdlib.h>

typedef char ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode
{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

BinTree CreatBinTree(); /* 实现细节忽略 */
int GetHeight(BinTree BT);

int main()
{
    BinTree BT = CreatBinTree();
    printf("%d\n", GetHeight(BT));
    return 0;
}

int GetHeight(BinTree BT)
{
    if (!BT)
    {
        return 0;
    }
    else
    {
        int m = GetHeight(BT->Left);
        int n = GetHeight(BT->Right);
        return (m > n) ? (m + 1) : (n + 1);
    }
}