//假设k为给定的值
/*
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int n,k;
int main(){
    cin >> n >> k;
    int dp[k+1][n+1];
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++){
        dp[1][i] = i;
    }
    for(int p=2;p<=k;p++){
        for(int q=1;q<=n;q++){
            for(int x=1;x<q;x++){
            dp[p][q] = max(dp[p-1][q-x]*x,dp[p][q]);
        }
    }
}
    cout << dp[k][n];
    return 0;
}
*/
/*
//假设k为随机值，dp
#include <iostream>
#include <algorithm>
using namespace std;
int n;
int main(){
    cin >> n ;
    int dp[n+1];
    dp[0]=0;
    dp[1]=1;
    for(int i=1;i<=n;i++){
        dp[i] = i;
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j>0;j--){
            dp[i]=max(dp[i],dp[i-j]*j);
        }
    }
    cout << dp[n];
    return 0;
}
*/
//k为随机值，贪心
#include <iostream>
#include <math.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int count = 0;
    while(n>5){
        n-=6;
        count++;
    }
    int ans=1;
    ans*=pow(9,count);
    if(n==5){
        ans*=6;
    }
    else if(n==1){
        ans*=1.5;
    }
    else{
        ans*=n;
    }
    cout << ans;
    return 0;
}

