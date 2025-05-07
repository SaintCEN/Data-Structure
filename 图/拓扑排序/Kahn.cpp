#include <iostream>
#include <stack>
using namespace std;

#define MAX_VERTEX_NUM 100

// 边表结点
typedef struct ArcNode
{
    int adjvex;              // 该弧所指向的顶点的位置
    struct ArcNode *nextarc; // 指向下一条弧的指针
} ArcNode;

// 顶点表结点
typedef struct VNode
{
    int in;            // 顶点入度
    ArcNode *firstarc; // 指向第一条依附该顶点的弧的指针
} VNode, AdjList[MAX_VERTEX_NUM];

// 图结构
typedef struct
{
    AdjList vertices;   // 邻接表
    int vexnum, arcnum; // 顶点数和弧数
} ALGraph;

void TopologicalSort(ALGraph G, int topo[])
{
    int indegree[MAX_VERTEX_NUM]; // 入度数组
    stack<int> s;

    // 初始化入度数组
    for (int i = 0; i < G.vexnum; ++i)
    {
        indegree[i] = G.vertices[i].in;
        if (indegree[i] == 0)
        {
            s.push(i); // 入度为0的顶点入栈
        }
    }

    int count = 0;
    while (!s.empty())
    {                    // 判断栈是否为空
        int u = s.top(); // 获取栈顶元素
        s.pop();         // 弹出栈顶
        topo[count] = u; // 存储拓扑序列
        count++;

        // 遍历u的所有邻接点
        for (ArcNode *p = G.vertices[u].firstarc; p != nullptr; p = p->nextarc)
        {
            int v = p->adjvex;
            if (--indegree[v] == 0) // 减少入度
            {
                s.push(v); // 入栈
            }
        }
    }

    // 存在环则无法完成拓扑排序
    if (count != G.vexnum)
    {
        return;
    }
}

int main()
{
    ALGraph G;
    G.vexnum = 4;
    G.arcnum = 4;

    // 邻接表初始化
    for (int i = 0; i < G.vexnum; ++i)
    {
        G.vertices[i].in = 0;
        G.vertices[i].firstarc = nullptr;
    }

    ArcNode *arc;

    // 添加边 0->1
    arc = new ArcNode{1, nullptr};
    arc->nextarc = G.vertices[0].firstarc;
    G.vertices[0].firstarc = arc;
    G.vertices[1].in++;

    // 添加边 0->2
    arc = new ArcNode{2, nullptr};
    arc->nextarc = G.vertices[0].firstarc;
    G.vertices[0].firstarc = arc;
    G.vertices[2].in++;

    // 添加边 1->3
    arc = new ArcNode{3, nullptr};
    arc->nextarc = G.vertices[1].firstarc;
    G.vertices[1].firstarc = arc;
    G.vertices[3].in++;

    // 添加边 2->3
    arc = new ArcNode{3, nullptr};
    arc->nextarc = G.vertices[2].firstarc;
    G.vertices[2].firstarc = arc;
    G.vertices[3].in++;

    int topo[MAX_VERTEX_NUM];
    TopologicalSort(G, topo);

    for (int i = 0; i < G.vexnum; ++i)
    {
        cout << topo[i] << " ";
    }
    cout << endl;

    return 0;
}