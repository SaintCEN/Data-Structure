#include <bits/stdc++.h>
using namespace std;

#define MVNum 100

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
        cin >> v1 >> v2;
        int i = LocateVex(G, v1);
        int j = LocateVex(G, v2);
        if (i != -1 && j != -1) {
            G.arcs[i][j] = 1;  // 有向图
        }
    }
}

bool TopologicalSort(Graph &G) {
    vector<int> inDegree(G.vexNum, 0);
    for (int i = 0; i < G.vexNum; i++) {
        for (int j = 0; j < G.vexNum; j++) {
            if (G.arcs[j][i] == 1) {
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
    
    int count = 0;  
    vector<char> result;  
    
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        result.push_back(G.vexs[v]);
        count++;
        
        for (int i = 0; i < G.vexNum; i++) {
            if (G.arcs[v][i] == 1) {
                inDegree[i]--;
                if (inDegree[i] == 0) {
                    q.push(i);
                }
            }
        }
    }
    
    if (count == G.vexNum) {
        for (char c : result) {
            cout << c << " ";
        }
        cout << endl;
        return true;
    } else {
        return false;
    }
}

int main() {
    Graph G;
    CreateGraph(G);
    TopologicalSort(G);
    return 0;
} 