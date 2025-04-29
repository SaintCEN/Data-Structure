#include <iostream>
#include <queue>
#include <vector>
#include <climits>

using namespace std;

#define MVNum 100

struct AMGraph
{
    char vexs[MVNum];       // 结点
    int arcs[MVNum][MVNum]; // 边
    int vexnum, arcnum;     // 结点总数 边总数
};

struct Edge
{
    int u, v;   // 边的两个顶点索引
    int weight; // 边的权值
};

struct Compare // 优先队列排序定义 取最小
{
    bool operator()(const struct Edge &e1, const struct Edge &e2)
    {
        return e1.weight > e2.weight;
    }
};

// 并查集
int parent[MVNum];

void InitParent(int n)
{
    for (int i = 0; i < n; ++i)
    {
        parent[i] = i;
    }
}

int Find(int x)
{
    if (parent[x] != x)
    {
        parent[x] = Find(parent[x]); // Path compression
    }
    return parent[x];
}

void Union(int x, int y)
{
    int rootX = Find(x);
    int rootY = Find(y);
    if (rootX != rootY)
    {
        parent[rootX] = rootY;
    }
}

// Kruskal算法
void Kruskal(AMGraph &G)
{
    // 初始化并查集
    InitParent(G.vexnum);

    priority_queue<struct Edge, vector<struct Edge>, Compare> pq;

    // 遍历邻接矩阵，将所有有效边加入优先队列
    for (int i = 0; i < G.vexnum; ++i)
    {
        for (int j = i + 1; j < G.vexnum; ++j)
        { // 从 i+1 开始，避免重复边（如 (i,j) 和 (j,i)）
            if (G.arcs[i][j] != INT_MAX && G.arcs[i][j] > 0)
            {                            // 检查是否存在有效边（权重非无穷且大于0）
                struct Edge e;           // 创建边结构体对象
                e.u = i;                 // 设置边的起点顶点索引
                e.v = j;                 // 设置边的终点顶点索引
                e.weight = G.arcs[i][j]; // 设置边的权重
                pq.push(e);              // 将边压入优先队列
            }
        }
    }

    int edgeCount = 0; // 记录已加入最小生成树的边数
    while (!pq.empty() && edgeCount < G.vexnum - 1)
    {                             // 循环直到队列为空或边数达到顶点数-1
        struct Edge e = pq.top(); // 取出权重最小的边
        pq.pop();                 // 从优先队列中移除该边

        int rootU = Find(e.u); // 查找起点顶点所在集合的根
        int rootV = Find(e.v); // 查找终点顶点所在集合的根

        if (rootU != rootV)
        { // 若两顶点不在同一集合，加入该边不会形成环
            cout << G.vexs[e.u] << " -> " << G.vexs[e.v] << " : " << e.weight << endl;
            Union(e.u, e.v); // 合并两顶点的集合
            edgeCount++;
        }
    }

    if (edgeCount < G.vexnum - 1)
    { // 如果边数不足顶点数-1，说明图不连通
        return;
    }
}