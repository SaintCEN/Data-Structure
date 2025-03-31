/*
#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int n;
	int w;
	cin>>n>>w;
	pair<int,int> a[n];
	for(int i=0;i<n;i++){
		cin>>a[i].first>>a[i].second;
	}
	int dp[n+1][w+1]={0};
	for(int i=0;i<n;i++){
		for(int j=0;j<=w;j++){
			for(int k=0;k*a[i].first<=j;k++){
				dp[i+1][j]=max(dp[i+1][j],dp[i-k*a[i].first]+k*a[i].second);
			}
		}
	}
	cout << dp[n][w];
	return 0;
}
*/
#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int n;
	int w;
	cin>>n>>w;
	pair<int,int> a[n];
	for(int i=0;i<n;i++){
		cin>>a[i].first>>a[i].second;
	}
	int dp[n+1][w+1]={0};
	for(int i=0;i<n;i++){
		for(int j=0;j<=w;j++){
			if(j<a[i].second){
				dp[i+1][j]=dp[i][j];
			}
			else{
				dp[i+1][j]=max(dp[i][j],dp[i+1][j-a[i].first]+a[i].second);
			}
		}
	}
	cout << dp[n][w];
	return 0;
}