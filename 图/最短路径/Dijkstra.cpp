#include <bits/stdc++.h>
using namespace std;

#define MVNum 100
#define INF 114154

typedef struct
{
    char vexs[MVNum];       
    int arcs[MVNum][MVNum]; 
    int vexNum, arcNum;     
} Graph;

int LocateVex(const Graph &G, char v)
{
    for (int i = 0; i < G.vexNum; ++i)
    {
        if (G.vexs[i] == v)
            return i;
    }
    return -1;
}

void Create(Graph &G)
{
    cin >> G.vexNum >> G.arcNum;
    for (int i = 1; i <= G.vexNum; i++)
    {
        cin >> G.vexs[i];
    }
    for (int i = 1; i <= G.vexNum; i++)
    {
        for(int j=1;j<=G.vexNum;j++)
        {
            G.arcs[i][j]=INF;
            if(i==j)
            {
                G.arcs[i][j]=0;
            }
        }
    }
    for (int k = 1; k <= G.arcNum; k++)
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

void Dijkstra(Graph &G, char start){
    int v0 = LocateVex(G,start);
    int n = G.vexNum;
    
    vector<int> dist(n + 1, INF);
    vector<bool> visited(n + 1, false);
    vector<int> path(n + 1, -1); 
    dist[v0] = 0;
    
    for(int i = 1; i <= n; i++) {
        int u = -1;
        int minDist = INF;
        for(int j = 1; j <= n; j++) {
            if(!visited[j] && dist[j] < minDist) {
                u = j;
                minDist = dist[j];
            }
        }
        
        if(u == -1) break;  
        visited[u] = true;
        
        for(int v = 1; v <= n; v++) {
            if(!visited[v] && G.arcs[u][v] != INF) {
                if(dist[u] + G.arcs[u][v] < dist[v]) {
                    dist[v] = dist[u] + G.arcs[u][v];
                    path[v] = u;  // 记录路径
                }
            }
        }
    }
    
    for(int i = 1; i <= n; i++) {
        if(i != v0) {
            if(dist[i] == INF) {
                cout << "Invalid." << endl;
            } else {
                cout << dist[i] << endl;
                cout << start;
                vector<int> route;
                int k = i;
                while(k != -1) {
                    route.push_back(k);
                    k = path[k];
                }
                for(int r = route.size()-1; r >= 0; r--) {
                    cout << " -> " << G.vexs[route[r]];
                }
                cout << endl;
            }
        }
    }
}

int main()
{
    Graph G;
    Create(G);
    char start;
    cin >> start;
    Dijkstra(G, start);
    return 0;
}