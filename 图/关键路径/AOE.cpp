#include <stdio.h>
#include <stdlib.h>

#define MVNum 100 // 最大顶点数
#define OK 1
#define ERROR 0

typedef char VerTexType; // 顶点类型
typedef int ArcType;     // 边的权值类型

typedef struct
{
    VerTexType vexs[MVNum];     // 顶点表
    ArcType arcs[MVNum][MVNum]; // 邻接矩阵
    int vexnum, arcnum;         // 图的当前顶点数和边数
} AMGraph;

int LocateVex(AMGraph *G, VerTexType v)
{
    for (int i = 0; i < G->vexnum; i++)
    {
        if (G->vexs[i] == v)
        {
            return i;
        }
    }
    return -1;
}

int CreateAOEGraph(AMGraph *G)
{
    scanf("%d", &G->vexnum);
    scanf("%d", &G->arcnum);

    for (int i = 0; i < G->vexnum; i++)
    {
        scanf(" %c", &G->vexs[i]);
    }

    // 初始化邻接矩阵
    for (int i = 0; i < G->vexnum; i++)
    {
        for (int j = 0; j < G->vexnum; j++)
        {
            G->arcs[i][j] = 0;
        }
    }

    for (int k = 0; k < G->arcnum; k++)
    {
        char v1, v2;
        int weight;
        scanf(" %c %c %d", &v1, &v2, &weight);
        int i = LocateVex(G, v1);
        int j = LocateVex(G, v2);
        if (i == -1 || j == -1)
        {
            return ERROR;
        }
        G->arcs[i][j] = weight;
    }
    return OK;
}

int TopologicalOrder(AMGraph G, int *topoOrder)
{
    int inDegree[MVNum] = {0};

    // 计算入度
    for (int j = 0; j < G.vexnum; j++)
    {
        for (int i = 0; i < G.vexnum; i++)
        {
            if (G.arcs[i][j] != 0)
            {
                inDegree[j]++;
            }
        }
    }

    int queue[MVNum];
    int front = 0, rear = 0;
    for (int i = 0; i < G.vexnum; i++)
    {
        if (inDegree[i] == 0)
        {
            queue[rear++] = i;
        }
    }

    int count = 0;
    while (front != rear)
    {
        int u = queue[front++];
        topoOrder[count++] = u;

        for (int v = 0; v < G.vexnum; v++)
        {
            if (G.arcs[u][v] != 0)
            {
                if (--inDegree[v] == 0)
                {
                    queue[rear++] = v;
                }
            }
        }
    }

    if (count != G.vexnum)
    {
        return ERROR; // 存在环
    }
    return OK;
}

void CalculateVE(AMGraph G, int *topoOrder, int *ve)
{
    for (int i = 0; i < G.vexnum; i++)
    {
        ve[i] = 0;
    }

    for (int i = 0; i < G.vexnum; i++)
    {
        int u = topoOrder[i];
        for (int v = 0; v < G.vexnum; v++)
        {
            if (G.arcs[u][v] != 0 && ve[v] < ve[u] + G.arcs[u][v])
            {
                ve[v] = ve[u] + G.arcs[u][v];
            }
        }
    }
}

void CalculateVL(AMGraph G, int *topoOrder, int *ve, int *vl)
{
    int maxVE = 0;
    // 找到所有汇点的最大ve值
    for (int i = 0; i < G.vexnum; i++)
    {
        int isSink = 1;
        for (int j = 0; j < G.vexnum; j++)
        {
            if (G.arcs[i][j] != 0)
            {
                isSink = 0;
                break;
            }
        }
        if (isSink && ve[i] > maxVE)
        {
            maxVE = ve[i];
        }
    }

    // 初始化vl
    for (int i = 0; i < G.vexnum; i++)
    {
        vl[i] = maxVE;
    }

    // 逆拓扑处理
    for (int i = G.vexnum - 1; i >= 0; i--)
    {
        int u = topoOrder[i];
        for (int v = 0; v < G.vexnum; v++)
        {
            if (G.arcs[u][v] != 0)
            {
                if (vl[u] > vl[v] - G.arcs[u][v])
                {
                    vl[u] = vl[v] - G.arcs[u][v];
                }
            }
        }
    }
}

void FindCriticalPath(AMGraph G, int *ve, int *vl)
{
    for (int i = 0; i < G.vexnum; i++)
    {
        for (int j = 0; j < G.vexnum; j++)
        {
            if (G.arcs[i][j] != 0)
            {
                int e = ve[i];
                int l = vl[j] - G.arcs[i][j];
                if (e == l)
                {
                    printf("%c -> %c, 权值: %d\n", G.vexs[i], G.vexs[j], G.arcs[i][j]);
                }
            }
        }
    }
}

int main()
{
    AMGraph G;
    int topoOrder[MVNum];

    if (TopologicalOrder(G, topoOrder) == ERROR)
    {
        return 1;
    }

    int ve[MVNum], vl[MVNum];
    CalculateVE(G, topoOrder, ve);
    CalculateVL(G, topoOrder, ve, vl);

    FindCriticalPath(G, ve, vl);

    return 0;
}