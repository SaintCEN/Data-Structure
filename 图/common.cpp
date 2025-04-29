#include <iostream>

using namespace std;

#define MaxInt 32767     // 极大值
#define MVNum 100        // 顶点最大值
typedef char VerTexType; // 顶点
typedef int ArcType;     // 边

// 邻接矩阵表示法
typedef struct
{
    VerTexType vexs[MVNum];     // 顶点表
    ArcType arcs[MVNum][MVNum]; // 邻接矩阵
    int vexnum, arcnum;
} AMGraph;

int LocateVex(AMGraph G, VerTexType v)
{
    for (int i = 0; i < G.vexnum; i++)
    {
        if (G.vexs[i] == v)
        {
            return i;
        }
    }
    return -1;
}

void CreateAM(AMGraph &G)
{
    cin >> G.vexnum >> G.arcnum;
    for (int i = 0; i < G.vexnum; i++)
    {
        cin >> G.vexs[i];
    }
    for (int i = 0; i < G.vexnum; i++)
    {
        for (int j = 0; j < G.vexnum; j++)
        {
            if (i == j)
            {
                G.arcs[i][j] = 0;
            }
            else
            {
                G.arcs[i][j] = MaxInt;
            }
        }
    }
    for (int k = 0; k < G.arcnum; k++)
    {
        VerTexType v1, v2;
        ArcType w;
        cin >> v1 >> v2 >> w;
        int i = LocateVex(G, v1);
        int j = LocateVex(G, v2);
        G.arcs[i][j] = w;
        G.arcs[j][i] = w;
    }
}

// 邻接表表示法
typedef struct ArcNode
{
    int adjvex; // 该边指向的顶点位置
    int weight; // 边的权重
    struct ArcNode *nextarc;
} ArcNode;

typedef struct VNode
{
    VerTexType data;   // 顶点信息
    ArcNode *firstarc; // 指向第一条边的指针
} VNode, AdjList[MVNum];

typedef struct
{
    AdjList vertices;   // 邻接表
    int vexnum, arcnum; // 顶点数和边数
} ALGraph;

void CreateAL(ALGraph &G)
{
    cin >> G.vexnum >> G.arcnum;
    for (int i = 0; i < G.vexnum; i++)
    {
        cin >> G.vertices[i].data;
        G.vertices[i].firstarc = NULL;
    }
    for (int k = 0; k < G.arcnum; k++)
    {
        VerTexType v1, v2;
        ArcType weight;
        cin >> v1 >> v2 >> weight;
        int i = LocateVex(*(AMGraph *)&G, v1);
        int j = LocateVex(*(AMGraph *)&G, v2);
        ArcNode *p1 = new ArcNode;
        p1->adjvex = j;
        p1->weight = weight;
        p1->nextarc = G.vertices[i].firstarc;
        G.vertices[i].firstarc = p1;
        /*
        // 无向图需要对称添加（v2->v1）
        ArcNode *p2 = new ArcNode;
        p2->adjvex = i;
        p2->weight = weight;
        p2->nextarc = G.vertices[j].firstarc;
        G.vertices[j].firstarc = p2;
        */
    }
}