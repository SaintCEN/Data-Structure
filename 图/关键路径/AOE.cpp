#include <bits/stdc++.h>
using namespace std;

#define MVNum 100
#define INF 114154

typedef struct {
    char vexs[MVNum];        
    int arcs[MVNum][MVNum];  
    int vexNum, arcNum;      
} Graph;

int LocateVex(const Graph &G, char v) {
    for (int i = 0; i < G.vexNum; ++i) {
        if (G.vexs[i] == v)
            return i;
    }
    return -1;
}

void CreateGraph(Graph &G) {
    cin >> G.vexNum >> G.arcNum;
    
    for (int i = 0; i < G.vexNum; i++) {
        cin >> G.vexs[i];
    }
    
    for (int i = 0; i < G.vexNum; i++) {
        for (int j = 0; j < G.vexNum; j++) {
            G.arcs[i][j] = 0;
        }
    }
    
    for (int k = 0; k < G.arcNum; k++) {
        char v1, v2;
        int w;
        cin >> v1 >> v2 >> w;
        int i = LocateVex(G, v1);
        int j = LocateVex(G, v2);
        if (i != -1 && j != -1) {
            G.arcs[i][j] = w;
        }
    }
}

bool TopologicalSort(Graph &G, vector<int> &topoOrder) {
    vector<int> inDegree(G.vexNum, 0);
    for (int i = 0; i < G.vexNum; i++) {
        for (int j = 0; j < G.vexNum; j++) {
            if (G.arcs[j][i] != 0) {
                inDegree[i]++;
            }
        }
    }
    
    queue<int> q;
    for (int i = 0; i < G.vexNum; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }
    
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        topoOrder.push_back(v);
        
        for (int i = 0; i < G.vexNum; i++) {
            if (G.arcs[v][i] != 0) {
                inDegree[i]--;
                if (inDegree[i] == 0) {
                    q.push(i);
                }
            }
        }
    }
    
    return topoOrder.size() == G.vexNum;
}

void CalculateVE(Graph &G, const vector<int> &topoOrder, vector<int> &ve) {
    // 初始化ve数组
    ve.resize(G.vexNum, 0);
    
    // 按拓扑顺序计算ve
    for (int i = 0; i < topoOrder.size(); i++) {
        int u = topoOrder[i];
        for (int v = 0; v < G.vexNum; v++) {
            if (G.arcs[u][v] != 0) {
                ve[v] = max(ve[v], ve[u] + G.arcs[u][v]);
            }
        }
    }
}

void CalculateVL(Graph &G, const vector<int> &topoOrder, const vector<int> &ve, vector<int> &vl) {
    // 初始化vl数组
    vl.resize(G.vexNum, ve[topoOrder.back()]);
    
    // 按逆拓扑顺序计算vl
    for (int i = topoOrder.size() - 1; i >= 0; i--) {
        int u = topoOrder[i];
        for (int v = 0; v < G.vexNum; v++) {
            if (G.arcs[u][v] != 0) {
                vl[u] = min(vl[u], vl[v] - G.arcs[u][v]);
            }
        }
    }
}

void FindCriticalPath(Graph &G, const vector<int> &ve, const vector<int> &vl) {
    for (int i = 0; i < G.vexNum; i++) {
        for (int j = 0; j < G.vexNum; j++) {
            if (G.arcs[i][j] != 0) {
                int e = ve[i];  // 活动最早开始时间
                int l = vl[j] - G.arcs[i][j];  // 活动最晚开始时间
                if (e == l) {  // 关键活动
                    cout << G.vexs[i] << " " << G.vexs[j] << " " << G.arcs[i][j] << endl;
                }
            }
        }
    }
}

int main() {
    Graph G;
    CreateGraph(G);
    
    vector<int> topoOrder;
    if (!TopologicalSort(G, topoOrder)) {
        cout << "ERROR" << endl;
        return 0;
    }
    
    vector<int> ve, vl;
    CalculateVE(G, topoOrder, ve);
    CalculateVL(G, topoOrder, ve, vl);
    
    FindCriticalPath(G, ve, vl);
    
    return 0;
}