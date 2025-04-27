#include <iostream>
using namespace std;

const int MVNum = 100;
bool visited[MVNum];

struct Graph
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

int FirstAdjVex(Graph G, int v)
{
    for (int i = 0; i < G.vexnum; ++i)
        if (G.arcs[v][i])
            return i;
    return -1;
}

int NextAdjVex(Graph G, int v, int w)
{
    for (int i = w + 1; i < G.vexnum; ++i)
        if (G.arcs[v][i])
            return i;
    return -1;
}

void DFS(Graph G, int v)
{
    cout << v;
    visited[v] = true;
    for (int w = FirstAdjVex(G, v); w >= 0; w = NextAdjVex(G, v, w))
        if (!visited[w])
            DFS(G, w);
}

void DFSTraverse(Graph G)
{
    for (int i = 0; i < G.vexnum; ++i)
        visited[i] = false;
    for (int i = 0; i < G.vexnum; ++i)
        if (!visited[i])
            DFS(G, i);
}

void DFS_AM(Graph G, int v)
{
    cout << v;
    visited[v] = true;
    for (int w = 0; w < G.vexnum; w++)
        if (G.arcs[v][w] && !visited[w])
            DFS_AM(G, w);
}

void DFS_AL(ALGraph G, int v)
{
    cout << v;
    visited[v] = true;
    ArcNode *p = G.vertices[v].firstarc;
    while (p)
    {
        int w = p->adjvex;
        if (!visited[w])
            DFS_AL(G, w);
        p = p->nextarc;
    }
}