#include<bits/stdc++.h>
using namespace std;

#define MAXN 10005
int graph[MAXN][MAXN];
vector<int> path;
vector<int> longest_path;
int max_len = 0;

void dfs(int curr, vector<int>& curr_path, int n) {
    curr_path.push_back(curr);
    
    bool is_leaf = true;
    for(int i = 0; i < n; i++) {
        if(graph[curr][i] == 1) {
            is_leaf = false;
            dfs(i, curr_path, n);
        }
    }
    
    if(is_leaf) {
        if(curr_path.size() > max_len || 
           (curr_path.size() == max_len && curr_path < longest_path)) {
            max_len = curr_path.size();
            longest_path = curr_path;
        }
    }
    
    curr_path.pop_back();
}

int main() {
    int N;
    cin >> N;
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            graph[i][j] = 0;
        }
    }
    
    for(int i = 0; i < N; i++) {
        int k;
        cin >> k;
        for(int j = 0; j < k; j++) {
            int child;
            cin >> child;
            graph[i][child] = 1;
        }
    }
    
    vector<int> curr_path;
    for(int i = 0; i < N; i++) {
        bool is_root = true;
        for(int j = 0; j < N; j++) {
            if(graph[j][i] == 1) {
                is_root = false;
                break;
            }
        }
        if(is_root) {
            dfs(i, curr_path, N);
            break;
        }
    }
    
    cout << max_len << endl;
    for(int i = 0; i < longest_path.size(); i++) {
        cout << longest_path[i];
        if(i < longest_path.size() - 1) {
            cout << " ";
        }
    }
    cout << endl;
    
    return 0;
}
