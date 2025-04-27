#include <iostream>
#include <queue>
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

void BFS(Graph G, int v)
{
    queue<int> Q;
    cout << v;
    visited[v] = true;
    Q.push(v);
    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        for (int w = FirstAdjVex(G, u); w >= 0; w = NextAdjVex(G, u, w))
        {
            if (!visited[w])
            {
                cout << w;
                visited[w] = true;
                Q.push(w);
            }
        }
    }
}

void BFS_AM(Graph G, int v)
{
    queue<int> Q;
    cout << v;
    visited[v] = true;
    Q.push(v);
    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        for (int w = 0; w < G.vexnum; w++)
        {
            if (G.arcs[u][w] && !visited[w])
            {
                cout << w;
                visited[w] = true;
                Q.push(w);
            }
        }
    }
}

void BFS_AL(ALGraph G, int v)
{
    queue<int> Q;
    cout << v;
    visited[v] = true;
    Q.push(v);
    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        ArcNode *p = G.vertices[u].firstarc;
        while (p)
        {
            int w = p->adjvex;
            if (!visited[w])
            {
                cout << w;
                visited[w] = true;
                Q.push(w);
            }
            p = p->nextarc;
        }
    }
}

void BFSTraverse(Graph G)
{
    for (int i = 0; i < G.vexnum; ++i)
        visited[i] = false;
    for (int i = 0; i < G.vexnum; ++i)
        if (!visited[i])
            BFS_AM(G, i);
}

void BFSTraverse(ALGraph G)
{
    for (int i = 0; i < G.vexnum; ++i)
        visited[i] = false;
    for (int i = 0; i < G.vexnum; ++i)
        if (!visited[i])
            BFS_AL(G, i);
}