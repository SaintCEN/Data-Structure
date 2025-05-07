#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
using namespace std;

#define MVNum 100

typedef struct
{
    char vexs[MVNum];       // 顶点表
    int arcs[MVNum][MVNum]; // 邻接矩阵
    int vexNum, arcNum;     // 节点数 边数
} AMGraph;

// 定位节点
int LocateVex(const AMGraph &G, char v)
{
    for (int i = 0; i < G.vexNum; ++i)
    {
        if (G.vexs[i] == v)
            return i;
    }
    return -1;
}

// 初始化邻接矩阵图
void CreateAMGraph(AMGraph &G)
{
    cin >> G.vexNum >> G.arcNum;
    // 输入顶点字符
    for (int i = 0; i < G.vexNum; ++i)
    {
        cin >> G.vexs[i];
    }
    // 初始化邻接矩阵
    for (int i = 0; i < MVNum; ++i)
    {
        fill(G.arcs[i], G.arcs[i] + MVNum, INT_MAX);
        G.arcs[i][i] = 0;
    }
    // 输入边信息
    for (int k = 0; k < G.arcNum; ++k)
    {
        char v1, v2;
        int w;
        cin >> v1 >> v2 >> w;
        int i = LocateVex(G, v1);
        int j = LocateVex(G, v2);
        if (i != -1 && j != -1)
        {
            G.arcs[i][j] = w;
        }
    }
}

void ShortestPath_DIJ(const AMGraph &G, char start)
{
    int v0 = LocateVex(G, start); // 将字符顶点转化为索引
    if (v0 == -1)
    {
        return;
    }

    int n = G.vexNum;        // 顶点总数
    int dist[MVNum];         // 存储源点到各点的最短距离
    int path[MVNum];         // 存储路径前驱节点
    bool S[MVNum] = {false}; // 标记顶点是否已处理

    // 初始化数组
    for (int i = 0; i < n; ++i)
    {
        dist[i] = G.arcs[v0][i]; // 初始化为源点到各点的直接距离
        if (dist[i] != INT_MAX)
        { // 可到达则设前驱为源点
            path[i] = v0;
        }
        else
        {
            path[i] = -1;
        }
    }
    dist[v0] = 0;  // 自身距离为0
    S[v0] = true;  // 标记为已处理
    path[v0] = -1; // 源点无前驱

    // 主循环：进行n-1次迭代（每次确定一个顶点的最短路径）
    for (int i = 1; i < n; i++)
    {
        int minDist = INT_MAX; // 当前未处理顶点中的最小距离
        int u = -1;            // 最小距离顶点索引（初始-1表示未找到）

        // 遍历所有顶点寻找最小值
        for (int j = 0; j < n; ++j)
        {
            // 仅处理未确定最短路径的顶点
            // 且当前顶点的距离比已记录的最小值更小
            if (!S[j] && dist[j] < minDist)
            {
                minDist = dist[j]; // 更新最小距离值
                u = j;             // 记录当前最小顶点的索引
            }
        }

        // 如果没有找到有效顶点
        if (u == -1)
            break;

        S[u] = true; // 将顶点u标记为已处理

        // 遍历所有顶点v，检查通过u到达v是否更优
        for (int v = 0; v < n; ++v)
        {
            // 仅处理未确定最短路径的顶点
            // 且存在u到v的边
            // 且新的路径距离比原有记录更短
            if (!S[v] && G.arcs[u][v] != INT_MAX && dist[u] + G.arcs[u][v] < dist[v])
            {
                dist[v] = dist[u] + G.arcs[u][v]; // 更新最短距离
                path[v] = u;                      // 记录前驱顶点为u
            }
        }
    }

    // 输出结果
    for (int i = 0; i < n; ++i)
    {
        if (dist[i] == INT_MAX)
        {
            cout << G.vexs[i] << " unreachable" << endl;
            continue;
        }

        vector<int> pathTrace;
        int cur = i;
        while (cur != -1)
        {
            pathTrace.push_back(cur);
            cur = path[cur];
        }
        reverse(pathTrace.begin(), pathTrace.end());

        cout << G.vexs[i] << " " << dist[i] << " ";
        for (size_t j = 0; j < pathTrace.size(); ++j)
        {
            if (j > 0)
                cout << "->";
            cout << G.vexs[pathTrace[j]];
        }
        cout << endl;
    }
}

int main()
{
    AMGraph G;
    CreateAMGraph(G);
    char start;
    cin >> start;
    ShortestPath_DIJ(G, start);
    return 0;
}