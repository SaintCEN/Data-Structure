#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1010;
int m, n;
char a[N],b[N];
int dp[N][N];
int main(){
    scanf("%d%s", &m, a + 1);   
    scanf("%d%s", &n, b + 1);//从1开始
    for(int i = 0; i <= m; i++) dp[i][0] = i;  //全删除
    for(int i = 0; i <= n; i++) dp[0][i] = i;  //全插入
    for(int i = 1; i <=m; i++)
        for(int j = 1; j <=n; j++)
        {
            dp[i][j] = min(dp[i][j-1], dp[i-1][j]) + 1;
            dp[i][j] = min(dp[i][j], dp[i-1][j-1] + (a[i] != b[j]));  
        }
    printf("%d\n",dp[m][n]);
    return 0;
}