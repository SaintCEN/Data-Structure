#include <iostream>
#include <string.h>
using namespace std;
int main(){
    int n;
    int k;
    int a[100000];
    int m[100000];
    int dp[100001];
    cin >> n >> k;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<n;i++){
        cin >> m[i];
    }
    memset(dp,-1,sizeof(dp));
    dp[0]=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<=k;j++){
            if(dp[j]>=0){
                dp[j]=m[i];
            }
            else if( j<a[i] || dp[j-a[i]]<=0 ){
                dp[j]=-1;
            }
            else{
                dp[j]=dp[j-a[i]]-1;
            }
        }
    }
    if(dp[k]>=0) printf("yes");
    else printf("no"); 
    return 0;
}