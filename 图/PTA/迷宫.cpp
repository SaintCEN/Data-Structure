#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Graph
{
    vector<vector<int>> adj;
    int vexnum;
};

void Create(Graph &G)
{
    cin >> G.vexnum;
    G.adj.resize(G.vexnum + 1);

    for (int i = 1; i <= G.vexnum; i++)
    {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++)
        {
            int c;
            cin >> c;
            G.adj[i].push_back(c);
            G.adj[c].push_back(i);
        }
    }
}

void BFS(Graph &G)
{
    vector<bool> visited(G.vexnum + 1, false);
    queue<pair<int, int>> q;
    q.push({1, 0});
    visited[1] = true;
    int max_length = 0;
    int max_node;

    while (!q.empty())
    {
        auto current = q.front();
        q.pop();
        int node = current.first;
        int length = current.second;

        if (length > max_length)
        {
            max_length = length;
            max_node = node;
        }

        for (int neighbor : G.adj[node])
        {
            if (!visited[neighbor])
            {
                visited[neighbor] = true;
                q.push({neighbor, length + 1});
            }
        }
    }

    cout << max_node << endl;
}

int main()
{
    Graph G;
    Create(G);
    BFS(G);
    return 0;
}