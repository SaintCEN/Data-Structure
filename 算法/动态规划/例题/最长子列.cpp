#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	char a[n];
	char b[m];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> b[i];
	}
	int dp[n + 1][m + 1];
	memset(dp, 0, sizeof dp);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i] == b[j]) {
				dp[i + 1][j + 1] = dp[i][j] + 1;
			} else {
				dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
			}
		}
	}
	cout << dp[n][m];
	return 0;
}