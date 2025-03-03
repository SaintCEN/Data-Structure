#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); 
void Print( List L ); 

List Insert( List L, ElementType X );

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

List Insert( List L, ElementType X ){
    PtrToNode q = (PtrToNode)malloc(sizeof(PtrToNode));
    q->Data = X;
    q->Next = NULL;
    PtrToNode Current = L;

    if(L == NULL || (X < L->Data && L->Next == NULL)){
        q->Next = L;
        return q;
    }

    while(Current->Next != NULL && Current->Next->Data < X){
        Current = Current->Next;
    }

    q->Next = Current->Next;
    Current->Next = q;

    return L;
}