#include<bits/stdc++.h>
using namespace std;

#define MAXVEX 100
#define INF 114514

typedef struct {
    int adjvex;
    int weight;
    struct ArcNode *next;
} ArcNode;

typedef struct {
    ArcNode *firstarc;
} AdjList[MAXVEX];

typedef struct {
    AdjList vertices;
    int vexnum, arcnum;
} Graph;

bool hasCycle(Graph &G, int from, int to, vector<bool>& visited, int parent) {
    visited[from] = true;
    ArcNode* p = G.vertices[from].firstarc;
    while(p) {
        int next = p->adjvex;
        if(!visited[next]) {
        if(hasCycle(G, next, to, visited, from)) {
                return true;
            }
        }
        else if( next != parent && next == to) {
            return true;
        }
        p = p->next;
    }
    return false;
}

bool isSafe(Graph &G, int from, int to) {
    vector<bool> visited(G.vexnum + 1, false);
    return !hasCycle(G, from, to, visited, -1);
}

void CreateGraph(Graph &G) {
    cin >> G.vexnum >> G.arcnum;
    for(int i=1; i<=G.vexnum; i++) {
        G.vertices[i].firstarc = nullptr;
    }
    for(int i=1; i<=G.arcnum; i++) {
        int m,n,w;
        cin >> m >> n >> w;
        ArcNode *p1 = new ArcNode;
        p1->adjvex = n;
        p1->weight = w;
        p1->next = G.vertices[m].firstarc;
        G.vertices[m].firstarc = p1;
        
        ArcNode *p2 = new ArcNode;
        p2->adjvex = m;
        p2->weight = w;
        p2->next = G.vertices[n].firstarc;
        G.vertices[n].firstarc = p2;
    }
}

void PrintMST(vector<vector<int>> &mst, int n) {
    for(int i=1; i<=n; i++) {
        for(int j=i+1; j<=n; j++) {
            if(mst[i][j] != 0) {
                cout << i << " " << j << endl;
            }
        }
    }
}

int main() {
    Graph G;
    CreateGraph(G);
    vector<vector<int>> mst(G.vexnum+1, vector<int>(G.vexnum+1, 0));
    int MSTedge = 0;
    
    while(MSTedge < G.vexnum-1) {
        int min = INF;
        int p1 = -1, p2 = -1;
        
        for(int i=1; i<=G.vexnum; i++) {
            ArcNode *p = G.vertices[i].firstarc;
            while(p) {
                if(p->weight < min && !mst[i][p->adjvex] && isSafe(G, i, p->adjvex)) {
                    min = p->weight;
                    p1 = i;
                    p2 = p->adjvex;
                }
                p = p->next;
            }
        }
        
        if(p1 == -1) {
            cout << "Invalid." << endl;
            return 1;
        }
        
        mst[p1][p2] = 1;
        mst[p2][p1] = 1;
        MSTedge++;
    }
    
    PrintMST(mst, G.vexnum);
    return 0;
}
