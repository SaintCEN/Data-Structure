/*给定一条长度为 L 的直线，在直线上有 n 个点。每个点的位置由数组 x[] 给出。现在你需要计算以下两项：
最小时间（minT）：对于每个点，计算它到起点 0 或终点 L 的最小距离，然后取这些最小距离中的最大值。
最大时间（maxT）：对于每个点，计算它到起点 0 或终点 L 的最大距离，然后取这些最大距离中的最大值。
请你计算并输出最小时间和最大时间。*/
#include <iostream>
#include <algorithm>
using namespace std;

void solve(int n, int L, int x[]) {
    int minT = 0, maxT = 0;
    
    // 计算 minT（到 0 或 L 的最小时间）
    for (int i = 0; i < n; i++) {
        minT = max(minT, min(x[i], L - x[i]));
    }

    // 计算 maxT（到 0 或 L 的最大时间）
    for (int i = 0; i < n; i++) {
        maxT = max(maxT, max(x[i], L - x[i]));
    }

    // 输出结果
    cout << "最小时间: " << minT << endl;
    cout << "最大时间: " << maxT << endl;
}

int main() {
    int n = 5; // 点的数量
    int L = 10; // 线段的长度
    int x[] = {2, 6, 3, 8, 1}; // 例子中的点的位置
    
    solve(n, L, x); // 调用求解函数

    return 0;
}
