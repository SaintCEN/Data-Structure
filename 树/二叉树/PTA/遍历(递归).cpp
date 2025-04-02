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
void InorderTraversal(BinTree BT);
void PreorderTraversal(BinTree BT);
void PostorderTraversal(BinTree BT);
void LevelorderTraversal(BinTree BT);

int main()
{
    BinTree BT = CreatBinTree();
    printf("Inorder:");
    InorderTraversal(BT);
    printf("\n");
    printf("Preorder:");
    PreorderTraversal(BT);
    printf("\n");
    printf("Postorder:");
    PostorderTraversal(BT);
    printf("\n");
    printf("Levelorder:");
    LevelorderTraversal(BT);
    printf("\n");
    return 0;
}

void InorderTraversal(BinTree BT)
{
    if (BT == NULL)
        return;
    InorderTraversal(BT->Left);
    printf(" %c", BT->Data);
    InorderTraversal(BT->Right);
}

void PreorderTraversal(BinTree BT)
{
    if (BT == NULL)
        return;
    printf(" %c", BT->Data);
    PreorderTraversal(BT->Left);
    PreorderTraversal(BT->Right);
}

void PostorderTraversal(BinTree BT)
{
    if (BT == NULL)
        return;
    PostorderTraversal(BT->Left);
    PostorderTraversal(BT->Right);
    printf(" %c", BT->Data);
}

int TreeHeight(BinTree node)
{
    if (node == NULL)
        return 0;
    int left = TreeHeight(node->Left);
    int right = TreeHeight(node->Right);
    return (left > right ? left : right) + 1;
}

void PrintLevel(BinTree node, int level)
{
    if (node == NULL)
        return;
    if (level == 1)
    {
        printf(" %c", node->Data);
    }
    else if (level > 1)
    {
        PrintLevel(node->Left, level - 1);
        PrintLevel(node->Right, level - 1);
    }
}

void LevelorderTraversal(BinTree BT)
{
    if (BT == NULL)
        return;
    int h = TreeHeight(BT);
    for (int i = 1; i <= h; i++)
    {
        PrintLevel(BT, i);
    }
}