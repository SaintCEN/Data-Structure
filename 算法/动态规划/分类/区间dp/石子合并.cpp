#include <iostream>
#include <cstring>
using namespace std;
const int N = 307;
int a[N], s[N];
int f[N][N];
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        s[i] += s[i - 1] + a[i];
    }
    memset(f, 0x3f, sizeof f);
    for (int len = 1; len <= n; len ++) { //区间长度
        for (int i = 1; i + len - 1 <= n; i ++) {//枚举起点
            int j = i + len - 1; //枚举终点
            if (len == 1) {
                f[i][j] = 0;  
                continue;
            }
            for (int k = i; k <= j - 1; k ++) { //枚举分割点成两堆
                f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j] + s[j] - s[i - 1]);
            }
        }
    }
    cout << f[1][n] << endl;
    return 0;
}