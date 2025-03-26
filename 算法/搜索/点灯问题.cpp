#include <iostream>
using namespace std;

const int R = 5;
const int C = 6;
int map[R][C];
int pressed[R][C] = {0};
int dir[5][2] = { {0, 0}, {-1, 0}, {1, 0}, {0, 1}, {0, -1} }; // 包括自身

// 按下按钮 (x, y)，改变灯的状态
void press(int x, int y) {
    for (int i = 0; i < 5; i++) {
        int nx = x + dir[i][0], ny = y + dir[i][1];
        if (nx >= 0 && nx < R && ny >= 0 && ny < C) {
            map[nx][ny] = 1 - map[nx][ny];
        }
    }
}

// 检查是否所有灯都熄灭
bool check() {
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (map[i][j] == 1) return false;
        }
    }
    return true;
}

// 递归求解
bool solve(int i, int j) {
    if (i == R) return check(); // 到达最后一行，检查是否成功
    if (j == C) return solve(i + 1, 0); // 换行

    // 不按按钮
    if (solve(i, j + 1)) return true;

    // 按按钮
    press(i, j);
    pressed[i][j] = 1;
    if (solve(i, j + 1)) return true;

    // 恢复状态
    press(i, j);
    pressed[i][j] = 0;
    return false;
}

int main() {
    // 输入灯的状态
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> map[i][j];
        }
    }

    // 求解
    if (solve(0, 0)) {
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                cout << pressed[i][j] << ' ';
            }
            cout << endl;
        }
    } else {
        cout << "No solution." << endl;
    }

    return 0;
}