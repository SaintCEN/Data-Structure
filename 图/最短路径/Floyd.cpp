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

void Floyd(Graph &G)
{
    int n = G.vexNum;
    vector<vector<int>> dist(n + 1, vector<int>(n + 1));
    vector<vector<int>> path(n + 1, vector<int>(n + 1, -1));
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            dist[i][j] = G.arcs[i][j];
            if(dist[i][j] < INF && i != j) {
                path[i][j] = i;  
            }
        }
    }
    
    for(int k = 1; k <= n; k++) {  
        for(int i = 1; i <= n; i++) {  
            for(int j = 1; j <= n; j++) {  
                if(dist[i][k] != INF && dist[k][j] != INF && 
                   dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    path[i][j] = path[k][j];  
                }
            }
        }
    }
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i != j) {
                cout << G.vexs[i] << " " << G.vexs[j];
                if(dist[i][j] == INF) {
                    cout << "Invalid." << endl;
                } else {
                    cout << dist[i][j] << endl;
                    cout << G.vexs[i];
                    int k = path[i][j];
                    vector<int> route;
                    while(k != -1) {
                        route.push_back(k);
                        k = path[i][k];
                    }
                    for(int r = route.size()-1; r >= 0; r--) {
                        cout << " -> " << G.vexs[route[r]];
                    }
                    cout << " -> " << G.vexs[j] << endl;
                }
            }
        }
    }
}

int main()
{
    Graph G;
    Create(G);
    Floyd(G);
    return 0;
}