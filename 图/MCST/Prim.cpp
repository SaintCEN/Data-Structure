#include <iostream>
#include <climits>

using namespace std;

#define MVNum 100

typedef char VerTexType;
typedef int ArcType;

struct AMGraph
{
    VerTexType vexs[MVNum];
    ArcType arcs[MVNum][MVNum];
    int vexnum, arcnum;
};

struct CloseEdge
{
    VerTexType adjvex; // 该顶点在生成树中的邻接顶点
    ArcType lowcost;   // 最小权值，0表示已加入生成树
} closedge[MVNum];

// 查找顶点u在G.vexs中的下标
int LocateVex(const AMGraph &G, VerTexType u)
{
    for (int i = 0; i < G.vexnum; ++i)
    {
        if (G.vexs[i] == u)
            return i;
    }
    return -1;
}

void Prim(AMGraph G, VerTexType u)
{
    int k = LocateVex(G, u);

    if (k == -1)
    {
        return;
    }

    // 初始化closedge数组
    for (int i = 0; i < G.vexnum; ++i)
    {
        if (i != k)
        {                                       // 如果不是起始顶点u
            closedge[i].adjvex = u;             // 初始时，所有顶点的最近邻接顶点都是u
            closedge[i].lowcost = G.arcs[k][i]; // 初始时，最小权值就是u到该顶点的权值
        }
        else
        {
            closedge[i].lowcost = 0; // u自身已加入生成树，lowcost设为0
        }
    }

    // 构建生成树的n-1条边
    for (int i = 1; i < G.vexnum; ++i)
    {
        // 寻找当前最小的边
        int min_cost = INT_MAX;
        int min_index = -1;
        for (int j = 0; j < G.vexnum; ++j)
        {
            if (closedge[j].lowcost > 0 && closedge[j].lowcost < min_cost)
            {
                min_cost = closedge[j].lowcost;
                min_index = j;
            }
        }

        if (min_index == -1)
        { // 图不连通，无法生成树
            return;
        }

        // 输出最小生成树的边
        cout << closedge[min_index].adjvex << " -> "
             << G.vexs[min_index] << " : " << min_cost << endl;

        // 将顶点min_index加入生成树
        closedge[min_index].lowcost = 0;

        // 更新closedge数组
        for (int j = 0; j < G.vexnum; ++j)
        {
            if (closedge[j].lowcost != 0 && G.arcs[min_index][j] < closedge[j].lowcost) // 更新到最小生成树的最短权值
            {
                closedge[j].adjvex = G.vexs[min_index];
                closedge[j].lowcost = G.arcs[min_index][j];
            }
        }
    }
}