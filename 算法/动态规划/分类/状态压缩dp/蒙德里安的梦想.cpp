//n×m的棋盘可以摆放不同的1×2小方格的种类数
#include<iostream>
#include<cstring>
using namespace std;
const int N = 12;
const int M = 1 << N;//二进制表示状态，转化为十进制
//f[i][j]表示 i-1列的方案数已经确定，从i-1列伸出，并且第i列的状态是j的所有方案数
long long f[N][M];
//st[j|k]=true 表示能成功转移
bool st[M];
int n, m;
int main() {
//    预处理st数组
    while (cin >> n >> m, n || m) {
        for (int i = 0; i < 1 << n; i++) {
//            第 i-2 列伸到 i-1 列的状态为 k 
//            能成功转移到 
//            第 i-1 列伸到 i 列的状态为 j
            st[i] = true;
//            记录一列中0的个数
            int cnt = 0;
            for (int j = 0; j < n; j++) {
//                通过位操作，i状态下j行是否放置方格，
//                0就是不放， 1就是放
                if (i >> j & 1) {
//                    如果放置小方块使得连续的空白格子数成为奇数，
//                    这样的状态就是不行的，
                    if (cnt & 1) {
                        st[i] = false;
                        break;
                    }
                }else cnt++;
            }
            if (cnt & 1) st[i] = false;
        }
        memset(f, 0, sizeof f);
        f[0][0] = 1;
        for (int i = 1; i <= m; i++) {
//            枚举i列每一种状态
            for (int j = 0; j < 1 << n; j++) {
//                枚举i-1列每一种状态
                for (int k = 0; k < 1 << n; k++) {
//                    f[i-1][k] 成功转到 f[i][j]
                    if ((j & k) == 0 && st[j | k]) {
                        f[i][j] += f[i - 1][k]; //那么这种状态下它的方案数等于之前每种k状态数目的和
                    }
                }
            }
        }
//        棋盘一共有0~m-1列
//        f[i][j]表示 前i-1列的方案数已经确定，从i-1列伸出，并且第i列的状态是j的所有方案数
//        f[m][0]表示 前m-1列的方案数已经确定，从m-1列伸出，并且第m列的状态是0的所有方案数
//        也就是m列不放小方格，前m-1列已经完全摆放好并且不伸出来的状态
        cout << f[m][0] << endl;
    }
    return 0;
}