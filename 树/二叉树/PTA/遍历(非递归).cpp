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
    int flag;
};

/*------堆栈的定义-------*/
typedef Position SElementType;
typedef struct SNode *PtrToSNode;
struct SNode
{
    SElementType Data;
    PtrToSNode Next;
};
typedef PtrToSNode Stack;

/* 裁判实现，细节不表 */
Stack CreateStack();
bool IsEmpty(Stack S);
bool Push(Stack S, SElementType X);
SElementType Pop(Stack S);  /* 删除并仅返回S的栈顶元素 */
SElementType Peek(Stack S); /* 仅返回S的栈顶元素 */
/*----堆栈的定义结束-----*/

BinTree CreateBinTree(); /* 裁判实现，细节不表 */
void InorderTraversal(BinTree BT);
void PreorderTraversal(BinTree BT);
void PostorderTraversal(BinTree BT);

int main()
{
    BinTree BT = CreateBinTree();
    printf("Inorder:");
    InorderTraversal(BT);
    printf("\n");
    printf("Preorder:");
    PreorderTraversal(BT);
    printf("\n");
    printf("Postorder:");
    PostorderTraversal(BT);
    printf("\n");
    return 0;
}

void InorderTraversal(BinTree BT)
{
    Stack S = CreateStack();
    BinTree T = BT;
    while (T || !IsEmpty(S))
    {
        while (T)
        {
            Push(S, T);
            T = T->Left;
        }
        T = Pop(S);
        printf(" %c", T->Data);
        T = T->Right;
    }
}

void PreorderTraversal(BinTree BT)
{
    if (BT == NULL)
        return;
    Stack S = CreateStack();
    Push(S, BT);
    while (!IsEmpty(S))
    {
        BinTree T = Pop(S);
        printf(" %c", T->Data);
        if (T->Right)
            Push(S, T->Right);
        if (T->Left)
            Push(S, T->Left);
    }
}

void PostorderTraversal(BinTree BT)
{
    if (BT == NULL)
        return;
    Stack S = CreateStack();
    BinTree T = BT;
    while (T || !IsEmpty(S))
    {
        while (T)
        {
            Push(S, T);
            T->flag = 0;
            T = T->Left;
        }
        T = Peek(S);
        if (T->flag == 0)
        {
            T->flag = 1;
            T = T->Right;
        }
        else
        {
            printf(" %c", T->Data);
            Pop(S);
            T = NULL;
        }
    }
}