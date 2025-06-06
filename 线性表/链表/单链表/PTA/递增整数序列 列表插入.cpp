#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node
{
    ElementType Data;
    PtrToNode Next;
};
typedef PtrToNode List;

List Read();
void Print(List L);

List Insert(List L, ElementType X);

int main()
{
    List L;
    ElementType X;
    L = Read();
    scanf("%d", &X);
    L = Insert(L, X);
    Print(L);
    return 0;
}

List Insert(List L, ElementType X)
{
    PtrToNode p = (PtrToNode)malloc(sizeof(PtrToNode));
    p->Data = X;
    p->Next = NULL;
    PtrToNode current = L;
    if (L == NULL || (L->Next == NULL && X < L->Data))
    {
        p->Next = L;
        return p;
    }
    while (current->Next != NULL && current->Next->Data < X)
    {
        current = current->Next;
    }
    p->Next = current->Next;
    current->Next = p;
    return L;
}