#include <iostream>
#include <vector>
#include <queue>
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

void BFS_AM(AMGraph G, int v)
{
    queue<int> Q;
    cout << v << " ";
    visited[v] = true;
    path.push_back(v);
    Q.push(v);
    
    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        for (int w = 0; w < G.vexnum; w++)
        {
            if (G.arcs[u][w] && !visited[w])
            {
                cout << w << " ";
                visited[w] = true;
                path.push_back(w);
                Q.push(w);
            }
        }
    }
}

void BFS_AL(ALGraph G, int v)
{
    queue<int> Q;
    cout << v << " ";
    visited[v] = true;
    path.push_back(v);
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
                cout << w << " ";
                visited[w] = true;
                path.push_back(w);
                Q.push(w);
            }
            p = p->nextarc;
        }
    }
}

void BFSTraverse_AM(AMGraph G)
{
    path.clear();
    for (int i = 0; i < G.vexnum; ++i)
        visited[i] = false;
    for (int i = 0; i < G.vexnum; ++i)
        if (!visited[i])
            BFS_AM(G, i);
}

void BFSTraverse_AL(ALGraph G)
{
    path.clear();
    for (int i = 0; i < G.vexnum; ++i)
        visited[i] = false;
    for (int i = 0; i < G.vexnum; ++i)
        if (!visited[i])
            BFS_AL(G, i);
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