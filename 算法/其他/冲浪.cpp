#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, m, l;
        cin >> n >> m >> l;
        vector<int> start(n + 1), end(n + 1);
        vector<int> dis(m + 1), val(m + 1);
        for (int i = 1; i <= n; i++) {
            cin >> start[i] >> end[i];
        }
        for (int i = 1; i <= m; i++) {
            cin >> dis[i] >> val[i];
        }
        int ans = 0;
        bool flag = true;
        int a = 1;
        vector<bool> f(m+1,true);
        priority_queue<int> q;
        for (int i = 1; i <= n; i++) {
            while (a < end[i] - start[i] + 2) {
                for (int j = 1; j <= m; j++) {
                    if (dis[j] < start[i] && f[j]) {
                        q.push(val[j]);
                        f[j] = false;
                    }
                }
                if (q.empty()) {
                    flag = false;
                    break;
                }
                int top = q.top();
                q.pop();
                a += top;
                ans++;
            if (a >= end[i] - start[i] + 2) {
                break;
                }
            }
            if (!flag) {
                break;
            }
        }
        if (flag) {
            cout << ans << endl;
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}