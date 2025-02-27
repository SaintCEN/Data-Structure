#include <iostream>
using namespace std;
const int R = 5;
const int C = 6;
int map[R][C];
int pressed[R][C] = {0};
bool found = false; 
int dir[4][2] = { {-1, 0}, {1, 0}, {0, 1}, {0, -1} };
void press(int x, int y) {
    map[x][y] = 1 - map[x][y];
    for (int i = 0; i < 4; i++) {
        int nx = x + dir[i][0], ny = y + dir[i][1];
        if (nx >= 0 && nx < R && ny >= 0 && ny < C) {
            map[nx][ny] = 1 - map[nx][ny];
        }
    }
}
bool check() {
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (map[i][j] == 1) {
                return false;
            }
        }
    }
    return true;
}
void solve(int i, int j) {
    if (found) return; 
    if (i == R) {
        if (check()) {
            found = true;
        }
        return;
    }
    if (j == C) {
        solve(i + 1, 0);
        return;
    }

    pressed[i][j] = 0;
    solve(i, j + 1);
    if (found) return;

    press(i, j);
    pressed[i][j] = 1;
    solve(i, j + 1);
    if (found) return;

    press(i, j);
    pressed[i][j] = 0;
}

int main() {
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> map[i][j];
        }
    }

    solve(0, 0);

    if (found) {
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                cout << pressed[i][j] << ' ';
            }
            cout << endl;
        }
    } else {
        cout << "Invalid." << endl;
    }

    return 0;
}