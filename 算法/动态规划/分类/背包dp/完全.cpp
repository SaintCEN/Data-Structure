/*
#include<iostream>
using namespace std;
const int N = 1010;
int n, m;
int f[N][N], v[N], w[N];

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i ++ )
        cin >> v[i] >> w[i];
    for(int i = 0; i <= m; i++)//初始化
    {
        f[0][i] = 0;
    }
    for(int i = 1; i <= n; i ++ )
        for(int j = 0; j <= m; j ++ )
            for(int k = 0; k * v[i] <= j; k ++ )
                f[i][j] = max(f[i][j], f[i - 1][j - k * v[i]] + k * w[i]);//求出每一个 f[i][j]
    cout << f[n][m] << endl;
}
*/
//优化版
#include<iostream>
using namespace std;
const int N = 1010;
int f[N];
int v[N],w[N];
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i = 1 ; i <= n ;i ++)
    {
        cin>>v[i]>>w[i];
    }

    for(int i = 1 ; i<=n ;i++)
    for(int j = v[i] ; j<=m ;j++)
    {
            f[j] = max(f[j],f[j-v[i]]+w[i]);
    }
    cout<<f[m]<<endl;
}