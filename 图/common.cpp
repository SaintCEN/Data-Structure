#include <bits/stdc++.h>
using namespace std;

#define MaxInt 32767     // 极大值
#define MVNum 100        // 顶点最大值
typedef char VerTexType; // 顶点类型定义
typedef int ArcType;     // 边类型定义

// 邻接矩阵表示法
typedef struct
{
    VerTexType vexs[MVNum];     // 顶点表
    ArcType arcs[MVNum][MVNum]; // 邻接矩阵
    int vexnum, arcnum;         // 顶点数目 边数目
} AMGraph;

// 为AMGraph定位顶点
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

// 初始化邻接矩阵
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

// 为 ALGraph 定位顶点
int LocateVex(const ALGraph &G, VerTexType v)
{
    for (int i = 0; i < G.vexnum; i++)
    {
        if (G.vertices[i].data == v)
        {
            return i;
        }
    }
    return -1;
}

// 初始化邻接表
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
        int i = LocateVex(G, v1);
        int j = LocateVex(G, v2);

        // 添加边 v1 -> v2
        ArcNode *p1 = new ArcNode;
        p1->adjvex = j;
        p1->weight = weight;
        p1->nextarc = G.vertices[i].firstarc;
        G.vertices[i].firstarc = p1;

        /* 添加边 v2 -> v1（无向图必须对称）
        ArcNode *p2 = new ArcNode;
        p2->adjvex = i;
        p2->weight = weight;
        p2->nextarc = G.vertices[j].firstarc;
        G.vertices[j].firstarc = p2;
        */
    }
}

// 十字链表表示法（有向图）
typedef struct ArcNode_OL
{
    int tailvex;              // 弧尾顶点位置
    int headvex;              // 弧头顶点位置
    struct ArcNode_OL *hlink; // 指向同一弧头的下一条弧
    struct ArcNode_OL *tlink; // 指向同一弧尾的下一条弧
    int weight;               // 弧的权值
    InfoType info;            // 其他信息
} ArcNode_OL;

typedef struct VexNode_OL
{
    VerTexType data;      // 顶点数据
    ArcNode_OL *firstin;  // 指向以该顶点为弧头的第一条弧
    ArcNode_OL *firstout; // 指向以该顶点为弧尾的第一条弧
} VexNode_OL;

typedef struct
{
    VexNode_OL xlist[MVNum]; // 顶点表
    int vexnum, arcnum;      // 顶点数和弧数
} OLGraph;

// 邻接多重表表示法（无向图）
typedef struct EBox
{
    int ivex, jvex;     // 该边依附的两个顶点位置
    struct EBox *ilink; // 指向依附于顶点ivex的下一条边
    struct EBox *jlink; // 指向依附于顶点jvex的下一条边
    int weight;         // 边的权值
    bool mark;          // 访问标记
    InfoType info;      // 其他信息
} EBox;

typedef struct VexBox
{
    VerTexType data; // 顶点数据
    EBox *firstedge; // 指向第一条依附于该顶点的边
} VexBox;

typedef struct
{
    VexBox adjmulist[MVNum]; // 顶点表
    int vexnum, edgenum;     // 顶点数和边数
} AMLGraph;
