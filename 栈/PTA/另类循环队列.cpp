#include <stdio.h>
#include <stdlib.h>

#define ERROR -1
typedef int ElementType;
typedef enum { addq, delq, end } Operation;
typedef enum { false, true } bool;
typedef int Position;
typedef struct QNode *PtrToQNode;
struct QNode {
    ElementType *Data;  /* 存储元素的数组   */
    Position Front;     /* 队列的头、尾指针 */
    int Count;          /* 队列中元素个数   */
    int MaxSize;        /* 队列最大容量     */
};
typedef PtrToQNode Queue; 

Queue CreateQueue( int MaxSize )
{
    Queue Q = (Queue)malloc(sizeof(struct QNode));
    Q->Data = (ElementType *)malloc(MaxSize * sizeof(ElementType));
    Q->Front = 0;
    Q->Count = 0;
    Q->MaxSize = MaxSize;
    return Q;
}

bool AddQ( Queue Q, ElementType X );
ElementType DeleteQ( Queue Q );

Operation GetOp();  /* 裁判实现，细节不表 */

int main()
{
    ElementType X;
    Queue Q;
    int N, done = 0;

    scanf("%d", &N);
    Q = CreateQueue(N);
    while ( !done ) {
        switch( GetOp() ) {
        case addq: 
            scanf("%d", &X);
            AddQ(Q, X);
            break;
        case delq:
            X = DeleteQ(Q);
            if ( X!=ERROR ) printf("%d is out\n", X);
            break;
        case end:
            while (Q->Count) printf("%d ", DeleteQ(Q));
            done = 1;
            break;
        }
    }
    return 0;
}

bool AddQ(Queue Q, ElementType X) {
    if (Q->Count == Q->MaxSize) { 
        printf("Queue Full\n");
        return false;
    } else {
        Position rear = (Q->Front + Q->Count) % Q->MaxSize;
        Q->Data[rear] = X;
        Q->Count++;
        return true;
    }
}

ElementType DeleteQ(Queue Q) {
    if (Q->Count == 0) {
        printf("Queue Empty\n");
        return ERROR;
    } else {
        ElementType X = Q->Data[Q->Front];
        Q->Front = (Q->Front + 1) % Q->MaxSize;
        Q->Count--; 
        return X;
    }
}
