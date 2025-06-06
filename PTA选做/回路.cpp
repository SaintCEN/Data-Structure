#include <stdio.h>
#include <stdlib.h>

typedef int Vertex;                /* 顶点编号类型 */
typedef char VertInfo;             /* 顶点信息类型 */
typedef struct EdgeNode *Position; /* 指针即结点位置 */
struct EdgeNode
{
    Vertex dest;   /* 边的另一端点编号 */
    Position next; /* 线性表中下一个元素的位置 */
};
typedef struct HeadNode *AdjList; /* 邻接表 */
struct HeadNode
{
    Position adj;  /* 邻接表头指针 */
    VertInfo data; /* 存储顶点信息 */
};
typedef struct LGraphNode *LGraph; /* 邻接表表示的图 */
struct LGraphNode
{
    int n_verts;       /* 顶点数 */
    int m_edges;       /* 边数 */
    AdjList *ver_list; /* 存储顶点邻接表 */
    bool directed;     /* true为有向图，false为无向图 */
};

#define kMaxV 1000
/* 裁判实现，细节略 */
void InitGraph(LGraph graph, int kMaxVertex, bool directed);
bool ExistEdge(LGraph graph, Vertex u, Vertex v);
void InsertEdge(LGraph graph, Vertex u, Vertex v);
LGraph BuildGraph();
/* 裁判实现部分结束 */

bool IsAcyclic(LGraph graph);

int main(void)
{
    LGraph graph;

    graph = BuildGraph();
    if (IsAcyclic(graph) == true)
    {
        printf("Yes\n");
    }
    else
    {
        printf("No\n");
    }

    return 0;
}

// 0: 未访问（unvisited）
// 1: 正在访问中（visiting，当前递归栈中的节点）
// 2: 已访问（visited，已处理完成的节点）
bool hasCycle(LGraph graph, Vertex v, int *state)
{
    if (state[v] == 1)
        return true; 
    if (state[v] == 2)
        return false;

    state[v] = 1; 
    Position p = graph->ver_list[v]->adj;
    while (p != NULL)
    {
        Vertex neighbor = p->dest;
        if (hasCycle(graph, neighbor, state))
        {
            return true;
        }
        p = p->next;
    }
    state[v] = 2; 
    return false;
}

bool IsAcyclic(LGraph graph)
{
    if (graph->n_verts == 0)
        return true; 

    int *state = (int *)calloc(graph->n_verts, sizeof(int));
    for (Vertex v = 0; v < graph->n_verts; v++)
    {
        if (state[v] == 0)
        { 
            if (hasCycle(graph, v, state))
            {
                free(state);
                return false; 
            }
        }
    }
    free(state);
    return true; 
}