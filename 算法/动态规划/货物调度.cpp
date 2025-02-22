/*
西西艾弗岛上共有 nn 间物流仓库，小 P 目前有 m 件货物存放其中。为了获得至少为 v 的现金，小 P 需要选取一些货物卖出。
已知货物信息如下，第 i 件（0≤i<m）货物：存放在第 ti间仓库中（0≤ti<n）；价值为 aia i，即选择卖出该货物可获得 ai的现金。
但在调货出库时也需要支付一些费用，对于第 j 间（0≤j<n）仓库：只要调用了该仓库的货物（至少一件），就需要支付 bj的基本费用；
如果调用了该仓库中共k 件货物，则还需要支付 k×cj的计件费用。
小 P 的最终目标是获得至少为 v 的现金，即要求卖出的货物总价值减去总费用的结果大于或等于 v.在满足该目标的前提下，试为小 
P 规划一种花费最小的卖货方案。*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
int dp[1001][40001];
vector<int>a[1005];
int b[1005];
int c[1005];
int main(){
    int n,m,v;
    int val,t;
    cin >> n >> m >> v;
    for(int i=0;i<=40000;i++){
        dp[0][i]=0;
    }
    for(int i=0;i<n;i++){
        cin >> b[i] >> c[i];
    }
    for(int i=0;i<m;i++){
        cin >> val >> t;
        a[t].push_back(val);
    }
    for(int i=0;i<n;i++){
    sort(a[i].begin(),a[i].end(),cmp);
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<=40000;j++){
            int sum = 0;
            dp[i][j]=dp[i-1][j];
            for(int k = 0;k<a[i].size();k++){
                if(b[i]+c[i]*k>=j){
                    break;
                }
                sum+=a[i][k];
                dp[i][j]=max(dp[i][j],dp[i-1][j-b[i]-c[i]*k]+sum-b[i]-c[i]*k);
            }
        }
    }
    for(int s=0;s<=40000;s++){
        if(dp[n-1][s]>=v){
            cout << s << endl;
            break;
        }
    }
    return 0;
}