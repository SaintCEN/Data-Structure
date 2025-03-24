#include <stdio.h>
#include<malloc.h>
#define OK 1
#define ERROR 0
typedef int Status;
typedef int ElemType; 
typedef struct LNode
{
    ElemType data;
    struct LNode * next;
}LNode,*LinkList;

typedef struct
 {
   LinkList front,rear; 
 }LinkQueue;

 Status InitQueue(LinkQueue *Q)
 {
     LinkList p;
   p=(LNode*)malloc(sizeof(LNode)); 
   p->next=NULL;
   (*Q).rear=(*Q).front=p;
   return OK;
 }
Status List(LinkList L)
{
    LinkList p;
    if(!L) return ERROR;
    p=L->next;
    
    while(p)
    {
        printf(" %d",p->data);
        p=p->next;
    }
    printf("\n");
    return OK;
}

int QueueLenth(LinkQueue Q)
{
    int n=0;
    LinkList p;
    if(Q.rear==Q.front)
        return 0;
    p=Q.front->next;
    while(p)
    {
        n++;
        p=p->next;
    }
    return n;
}

int main()
{
    int x;
    LinkQueue Q;
    InitQueue(&Q);
    QueueInsert(&Q,1);QueueInsert(&Q,2);QueueInsert(&Q,3);
    List(Q.front );
    QueueDelete( &Q,&x);
    printf(" %d %d\n",x,QueueLenth(Q));
    QueueDelete(&Q,&x);QueueDelete(&Q,&x);
    printf(" %d %d\n",x,QueueLenth(Q));
    return 0;
}

Status QueueInsert(LinkQueue *Q,ElemType e){
    LNode *newnode = new LNode;
    if(newnode==NULL){
        return ERROR;
    }else{
        newnode->data = e;
        newnode->next = NULL;
        Q->rear->next = newnode;
        Q->rear = newnode;
        return OK;
    }
}

Status QueueDelete(LinkQueue *Q, ElemType *e) {
    if (Q->front == Q->rear) {
        return ERROR;
    }
    LinkList temp = Q->front->next;
    *e = temp->data; 
    Q->front->next = temp->next;
    if (Q->rear == temp) {
        Q->rear = Q->front;
    }
    free(temp); 
    return OK;
}
