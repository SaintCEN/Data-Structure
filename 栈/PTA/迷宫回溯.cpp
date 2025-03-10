#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};

bool solve(vector<vector<int>>& maze, int sx, int sy, int gx, int gy, int n, stack<pair<int, int>>& path) {
    if (sx == gx && sy == gy) {
        path.push({sx, sy});
        return true;
    }

    maze[sx][sy] = 1;

    for (int i = 0; i < 8; i++) {
        int nx = sx + dx[i];
        int ny = sy + dy[i];

        if (nx >= 0 && nx < n && ny >= 0 && ny < n && maze[nx][ny] == 0) {
            if (solve(maze, nx, ny, gx, gy, n, path)) {
                path.push({sx, sy});
                return true;
            }
        }
    }
    return false;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> maze(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> maze[i][j];
        }
    }

    int sx, sy, gx, gy;
    cin >> sx >> sy >> gx >> gy;

    stack<pair<int, int>> path;
    if (solve(maze, sx, sy, gx, gy, n, path)) {
        while (!path.empty()) {
            pair<int, int> p = path.top();
            path.pop(); 
        }
    } else {
        cout << "No path found!";
    }
    return 0;
}