#include <stdio.h>
#include <stdlib.h>

/* 邻接表表示的图定义 */
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

bool ExistPath(LGraph graph, Vertex u, Vertex v);

int main(void)
{
    LGraph graph;
    int k, i;
    Vertex u, v;

    graph = BuildGraph();
    scanf("%d", &k);
    for (i = 0; i < k; i++)
    {
        scanf("%d %d", &u, &v);
        if (ExistPath(graph, u, v) == true)
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }

    return 0;
}

bool ExistPath(LGraph graph, Vertex u, Vertex v)
{
    if (u == v)
        return true;
    if (u < 0 || u >= graph->n_verts || v < 0 || v >= graph->n_verts)
    {
        return false;
    }

    bool *visited = (bool *)malloc(graph->n_verts * sizeof(bool));
    for (int i = 0; i < graph->n_verts; ++i)
    {
        visited[i] = false;
    }

    Vertex *queue = (Vertex *)malloc(graph->n_verts * sizeof(Vertex));
    int front = 0, rear = 0;
    queue[rear++] = u;
    visited[u] = true;

    while (front < rear)
    {
        Vertex current = queue[front++];
        Position p = graph->ver_list[current]->adj;

        while (p)
        {
            Vertex neighbor = p->dest;
            if (neighbor == v)
            {
                free(visited);
                free(queue);
                return true;
            }
            if (!visited[neighbor])
            {
                visited[neighbor] = true;
                queue[rear++] = neighbor;
            }
            p = p->next;
        }
    }

    free(visited);
    free(queue);
    return false;
}