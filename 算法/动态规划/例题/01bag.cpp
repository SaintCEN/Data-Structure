/*
#include <iostream>
#include <cstring>
using namespace std;
int main(){
	int n;
	int w;
	scanf("%d %d",&n,&w);
	int W[n];
	int V[n];
	for(int i=0;i<n;i++){
		scanf("%d",&W[i]);
	}
	for(int i=0;i<n;i++){
		scanf("%d",&V[i]);
	}
	int dp[n+1][w+1];
	memset(dp,0,sizeof(dp));
	for(int i=0;i<n;i++){
		for(int j=0;j<=w;j++){
			if(j<W[i]){
				dp[i+1][j]=dp[i][j];
			}
			else{
				dp[i+1][j]=max(dp[i][j],dp[i][j-W[i]]+V[i]);
			}
		}
	}
	printf("%d",dp[n][w]);
	return 0;
}
*/
#include<iostream>
using namespace std;
const int N = 1010;
int v[N],w[N];  
int dp[N];
int n,m;
int main()
{
    scanf("%d %d",&n,&m);
    for(int i = 1;i<=n;i++)
    {
       scanf("%d",&v[i]);
    }
	for(int i = 1;i<=n;i++)
    {
       scanf("%d",&w[i]);
    }
       for(int i = 1;i<=n;i++)
    {   
        for(int j = m;j>=v[i];j--)   
        {  
            dp[j] = max(dp[j],dp[j-v[i]]+w[i]); 
                                              
        } 
    }
    printf("%d",dp[m]);
    return 0 ;
}

