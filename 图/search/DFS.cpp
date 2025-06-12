#include <iostream>
#include <vector>
using namespace std;

const int MVNum = 100;
bool visited[MVNum];
vector<int> path;  

struct AMGraph
{
    int arcs[MVNum][MVNum];
    int vexnum, arcnum;
};

struct ArcNode
{
    int adjvex;
    ArcNode *nextarc;
};

struct VNode
{
    ArcNode *firstarc;
};

struct ALGraph
{
    VNode vertices[MVNum];
    int vexnum, arcnum;
};

void DFS_AM(AMGraph G, int v)
{
    cout << v << " ";
    visited[v] = true;
    path.push_back(v);
    for (int w = 0; w < G.vexnum; w++)
        if (G.arcs[v][w] && !visited[w])
            DFS_AM(G, w);
}

void DFS_AL(ALGraph G, int v)
{
    cout << v << " ";
    visited[v] = true;
    path.push_back(v);
    ArcNode *p = G.vertices[v].firstarc;
    while (p)
    {
        int w = p->adjvex;
        if (!visited[w])
            DFS_AL(G, w);
        p = p->nextarc;
    }
}

void DFSTraverse_AM(AMGraph G)
{
    path.clear();
    for (int i = 0; i < G.vexnum; ++i)
        visited[i] = false;
    for (int i = 0; i < G.vexnum; ++i)
        if (!visited[i])
            DFS_AM(G, i);
}

void DFSTraverse_AL(ALGraph G)
{
    path.clear();
    for (int i = 0; i < G.vexnum; ++i)
        visited[i] = false;
    for (int i = 0; i < G.vexnum; ++i)
        if (!visited[i])
            DFS_AL(G, i);
}

void PrintPath()
{
    for (size_t i = 0; i < path.size(); ++i) {
        cout << path[i];
        if (i < path.size() - 1)
            cout << " -> ";
    }
    cout << endl;
}