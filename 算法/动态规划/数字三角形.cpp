#include <iostream>
#include <cstring>
using namespace std;
int n;
int main(){
    cin >> n;
    int a[n+1][n+1];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cin >> a[i][j];
        }
    }
    int dp[n+1][n+1];
    memset(dp,0,sizeof(dp));
    dp[1][1] = a[1][1];
    for(int i=2;i<=n;i++){
        for(int j=1;j<=i;j++){
            if(j==1){
            dp[i][1] = dp[i-1][1] + a[i][1];
            }
            else if(j==i){
                dp[i][i] = dp[i-1][i-1] + a[i][i];
            }
            else{
                dp[i][j] = max(dp[i-1][j],dp[i-1][j-1]) + a[i][j];
            }
        }
    }
    int ans = 0;
    for(int i=1;i<=n;i++){
        if(dp[n][i]>ans){
            ans = dp[n][i];
        }
    }
    cout << ans;
    return 0;
}