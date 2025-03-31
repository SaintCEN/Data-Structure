#include <iostream>
#include <cstring>
using namespace std;
void dfs(int x, int *p) {
    dfs(p[x], p);
    cout << x << " ";
}
int main() {
    int N;
    cin >> N;
    int num[N + 1];
    int con[N + 1][N + 1];
    int p[N + 1];
    memset(con, 0, sizeof(con));
    for (int i = 1; i <= N; i++) {
        cin >> num[i];
    }
    for (int i = 1; i <= N - 1; i++) {
        for (int j = i + 1; j <= N; j++) {
            cin >> con[i][j];
            con[j][i] = con[i][j];
        }
    }
    int dp[N + 1];
    for (int i = 1; i <= N; i++) {
        dp[i] = num[i];
        p[i] = 0;
    }
    int ans = 0;
    int des = 0;
    for (int i = 2; i <= N; i++) {
        for (int j = i - 1; j >= 1; j--) {
            if (con[j][i]) {
                if (dp[i] < dp[j] + num[i]) {
                    dp[i] = dp[j] + num[i];
                    p[i] = j;
                }
            }
        }
        if (ans < dp[i]) {
            ans = dp[i];
            des = i;
        }
    }

    if (des != 0) {
        dfs(des, p);
    }
    cout << endl << ans;
    return 0;
}
