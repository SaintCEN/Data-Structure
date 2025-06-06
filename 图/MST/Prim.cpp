#include<bits/stdc++.h>
using namespace std;

#define INF 32366
#define MAX_VERTICES 100

typedef struct {
    int edges[MAX_VERTICES][MAX_VERTICES];
    int edgeCount;
    int vertexCount;
} Graph;

void printMST(vector<vector<int>>& mst, int n) {
    for(int i = 1; i <= n; i++) {
        for(int j = i + 1; j <= n; j++) {
            if(mst[i][j] == 1) {
                cout << i << " - " << j << endl;
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    
    Graph g;
    g.edgeCount = n - 1;
    g.vertexCount = n;
    
    for (int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            g.edges[i][j] = INF;
        }
    }
    
    for(int i = 1; i <= n; i++) {
        int from, to, weight;
        cin >> from >> to >> weight;
        g.edges[from][to] = weight;
        g.edges[to][from] = weight;
    }

    vector<bool> visited(n + 1, false);
    vector<vector<int>> mst(n + 1, vector<int>(n + 1, 0));
    visited[1] = true;
    int mstEdgeCount = 0;

    while(mstEdgeCount < n - 1) {
        int minWeight = INF;
        int minFrom = -1;
        int minTo = -1;

        for(int i = 1; i <= n; i++) {
            if(visited[i]) {
                for(int j = 1; j <= n; j++) {
                    if(!visited[j] && g.edges[i][j] < minWeight) {
                        minWeight = g.edges[i][j];
                        minFrom = i;
                        minTo = j;
                    }
                }
            }
        }

        if(minFrom == -1) {
            cout << "Invalid." << endl;
            return 1;
        }

        mst[minFrom][minTo] = 1;
        mst[minTo][minFrom] = 1;
        visited[minTo] = true;
        mstEdgeCount++;
    }

    printMST(mst, n);
    
    return 0;
}