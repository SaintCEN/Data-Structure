#include <stdio.h>
#include <stdlib.h>
#define ERROR -1
typedef int ElementType;
typedef struct LNode *PtrToLNode;
struct LNode {
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode List;

List Read(); /* 细节在此不表 */

ElementType FindKth( List L, int K );

int main()
{
    int N, K;
    ElementType X;
    List L = Read();
    scanf("%d", &N);
    while ( N-- ) {
        scanf("%d", &K);
        X = FindKth(L, K);
        if ( X!= ERROR )
            printf("%d ", X);
        else
            printf("NA ");
    }
    return 0;
}
ElementType FindKth( List L, int K ){
    PtrToLNode p = L;
    int count = 0;
    while(p!=NULL){
        count++;
        if(count==K){
            return p->Data;
        }
        else{
            p = p->Next;
        }
    }
    return ERROR;
}