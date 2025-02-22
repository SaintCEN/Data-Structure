#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N = 10;
int n;
int x,y,num;
int dp[N][N][N][N];
int g[N][N];
int main(){
    cin >> n;
    while(1){
        cin >> x >> y >> num;
        g[x][y] = num;
        if(x==0&&y==0&&num==0){
            break;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int p=1;p<=n;p++){
                for(int q=1;q<=n;q++){
                    dp[i][j][p][q]=max(max(dp[i-1][j][p-1][q],dp[i-1][j][p][q-1]),max(dp[i][j-1][p-1][q],dp[i][j-1][p][q-1]))+g[i][j]+g[p][q];
                    if(i==p&&j==q){
                        dp[i][j][p][q]-=g[i][j];
                    }
                }
            }
        }
    }
    cout << dp[n][n][n][n];
    return 0;
}