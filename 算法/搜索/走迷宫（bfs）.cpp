#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int bfs(vector<vector<int>>& maze, int sx, int sy, int gx, int gy, int m, int n);

int main() {
    int m, n;
    int sx, sy;
    int gx, gy;

    cin >> m >> n >> sx >> sy >> gx >> gy;

    vector<vector<int>> maze(m, vector<int>(n));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> maze[i][j];
        }
    }

    int res = bfs(maze, sx, sy, gx, gy, m, n);
    cout << res << endl;

    return 0;
}

int bfs(vector<vector<int>> maze, int sx, int sy, int gx, int gy, int m, int n) {
    typedef pair<int, int> p;
    queue<p> q;
    
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    
    vector<vector<int>> d(m, vector<int>(n, -1));  
    
    q.push(p(sx, sy));
    d[sx][sy] = 0;  
    
    while (!q.empty()) {
        p current = q.front();
        q.pop();
        int x = current.first, y = current.second;
        if (x == gx && y == gy) {
            return d[x][y];
        }
        
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            
            if (0 <= nx && nx < m && 0 <= ny && ny < n && maze[nx][ny] != 1 && d[nx][ny] == -1) {
                q.push(p(nx, ny));
                d[nx][ny] = d[x][y] + 1; 
            }
        }
    }

}

