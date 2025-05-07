#include <iostream>
#include <climits>
using namespace std;

#define MVNum 100 // 假设最大顶点数为100

const int INF = INT_MAX;

typedef struct
{
    char vexs[MVNum];       // 顶点表
    int arcs[MVNum][MVNum]; // 邻接矩阵
    int vexNum, arcNum;     // 顶点数和边数
} AMGraph;

// 定位顶点
int LocateVex(const AMGraph &G, char v)
{
    for (int i = 0; i < G.vexNum; ++i)
    {
        if (G.vexs[i] == v)
            return i;
    }
    return -1;
}

void Floyd(const AMGraph &G, int dist[][MVNum])
{
    // 初始化距离矩阵
    for (int i = 0; i < G.vexNum; ++i)
    {
        for (int j = 0; j < G.vexNum; ++j)
        {
            dist[i][j] = G.arcs[i][j];
        }
    }

    // 三重循环更新最短路径
    for (int k = 0; k < G.vexNum; ++k)
    {
        for (int i = 0; i < G.vexNum; ++i)
        {
            for (int j = 0; j < G.vexNum; ++j)
            {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][j] > dist[i][k] + dist[k][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}

void CreateAMGraph(AMGraph &G)
{
    cin >> G.vexNum >> G.arcNum;

    for (int i = 0; i < G.vexNum; ++i)
        cin >> G.vexs[i];

    for (int i = 0; i < G.vexNum; ++i)
        for (int j = 0; j < G.vexNum; ++j)
            G.arcs[i][j] = (i == j) ? 0 : INF;

    for (int k = 0; k < G.arcNum; ++k)
    {
        char v1, v2;
        int weight;
        cin >> v1 >> v2 >> weight;
        int i = LocateVex(G, v1);
        int j = LocateVex(G, v2);
        G.arcs[i][j] = weight;
    }
}

int main()
{
    AMGraph G;
    CreateAMGraph(G);

    int dist[MVNum][MVNum];
    Floyd(G, dist);

    for (int j = 0; j < G.vexNum; ++j)
    {
        if (dist[0][j] != INF)
            cout << "Distance from " << G.vexs[0] << " to " << G.vexs[j] << ": " << dist[0][j] << endl;
        else
            cout << "No path from " << G.vexs[0] << " to " << G.vexs[j] << endl;
    }
    return 0;
}