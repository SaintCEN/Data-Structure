//无优化版
#include <iostream>
using namespace std;
const int N = 1010;
int n, m;
int v[N], w[N];
int f[N][N];
int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> v[i] >> w[i];
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= m; j++) {
            f[i][j] = f[i-1][j];
            if(j>=v[i]) f[i][j] = max(f[i][j], f[i-1][j-v[i]]+w[i]);
        }
    }
    cout << f[n][m] << endl;
 return 0;    
}
//有优化版
/*
1. f[i] 仅用到了f[i-1]层, 
2. j与j-v[i] 均小于j
3.若用到上一层的状态时,从大到小枚举, 反之从小到大哦
*/
#include <iostream>
using namespace std;
const int N = 1010;
int n, m;
int v[N], w[N];
int f[N];
int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> v[i] >> w[i];
    for(int i = 1; i <= n; i++) 
        for(int j = m; j >= v[i]; j--) 
            f[j] = max(f[j], f[j-v[i]]+w[i]);
    cout << f[m] << endl;
 return 0;    
}