//第一种：同种物品可选多次
#include <bits/stdc++.h>
using namespace std;
int a[10005],b[10005],t=0,n,m,dp[10005],w,v,s;
int main()
{
    cin>>n>>m;
    while(n--)
    {
        cin>>v>>w>>s;
        while(s--)
        {
            a[++t]=v;
            b[t]=w;
        }//死拆，把多重背包拆成01背包
    }
    for(int i=1;i<=t;i++)
    for(int j=m;j>=a[i];j--)
    dp[j]=max(dp[j-a[i]]+b[i],dp[j]);
    cout<<dp[m]<<endl;
    return 0;
}
//第二种：二进制优化
#include<iostream>
using namespace std;
const int N = 12010, M = 2010;
int n, m;
int v[N], w[N]; 
int f[M]; 
int main()
{
    cin >> n >> m;
    int cnt = 0; 
    for(int i = 1;i <= n;i ++)
    {
        int a,b,s;
        cin >> a >> b >> s;
        int k = 1; // 组别里面的个数
        while(k<=s)
        {
            cnt ++ ; //组别先增加
            v[cnt] = a * k ; 
            w[cnt] = b * k; 
            s -= k; 
            k *= 2; 
        }
        if(s>0)
        {
            cnt ++ ;
            v[cnt] = a*s; 
            w[cnt] = b*s;
        }
    }
    n = cnt ; 
    for(int i = 1;i <= n ;i ++)
        for(int j = m ;j >= v[i];j --)
            f[j] = max(f[j],f[j-v[i]] + w[i]);
    cout << f[m] << endl;
    return 0;
}
