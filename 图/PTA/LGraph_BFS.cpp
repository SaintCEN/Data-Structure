#include <stdio.h>

#define MaxVertexNum 10 /* 最大顶点数设为10 */
typedef int Vertex;     /* 用顶点下标表示顶点,为整型 */

/* 邻接点的定义 */
typedef struct AdjVNode *PtrToAdjVNode;
struct AdjVNode
{
    Vertex AdjV;        /* 邻接点下标 */
    PtrToAdjVNode Next; /* 指向下一个邻接点的指针 */
};

/* 顶点表头结点的定义 */
typedef struct Vnode
{
    PtrToAdjVNode FirstEdge; /* 边表头指针 */
} AdjList[MaxVertexNum];     /* AdjList是邻接表类型 */

/* 图结点的定义 */
typedef struct GNode *PtrToGNode;
struct GNode
{
    int Nv;    /* 顶点数 */
    int Ne;    /* 边数   */
    AdjList G; /* 邻接表 */
};
typedef PtrToGNode LGraph; /* 以邻接表方式存储的图类型 */

bool Visited[MaxVertexNum]; /* 顶点的访问标记 */

LGraph CreateGraph(); /* 创建图并且将Visited初始化为false；裁判实现，细节不表 */

void Visit(Vertex V)
{
    printf(" %d", V);
}

void BFS(LGraph Graph, Vertex S, void (*Visit)(Vertex));

int main()
{
    LGraph G;
    Vertex S;

    G = CreateGraph();
    scanf("%d", &S);
    printf("BFS from %d:", S);
    BFS(G, S, Visit);

    return 0;
}

void BFS(LGraph Graph, Vertex S, void (*Visit)(Vertex))
{
    Vertex queue[MaxVertexNum];
    int front = 0, rear = 0;

    Visited[S] = true;
    queue[rear] = S;
    rear = (rear + 1) % MaxVertexNum;

    while (front != rear)
    {
        Vertex V = queue[front];
        front = (front + 1) % MaxVertexNum;
        Visit(V);

        PtrToAdjVNode p = Graph->G[V].FirstEdge;
        while (p != NULL)
        {
            Vertex AdjV = p->AdjV;
            if (!Visited[AdjV])
            {
                Visited[AdjV] = true;
                queue[rear] = AdjV;
                rear = (rear + 1) % MaxVertexNum;
            }
            p = p->Next;
        }
    }
}