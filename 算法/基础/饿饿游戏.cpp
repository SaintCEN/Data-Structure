#include <iostream>
#include <vector>
using namespace std;
void solve() {
    int t;
    cin >> t;
    while (t--) {
        int n, T;
        cin >> n >> T;

        vector<int> mushrooms(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> mushrooms[i];
        }

        vector<long long> prefix(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            prefix[i] = prefix[i - 1] + mushrooms[i];
        }

        int valid_intervals = 0;
        for (int l = 1; l <= n; l++) {
            int current_poison = 0;
            int s = l;
            for (int r = l; r <= n; r++) {
                current_poison = prefix[r] - prefix[s - 1];
                if (current_poison > T) {
                    current_poison = 0;
                    s = r + 1;
                    continue;
                }
                if (current_poison <= T) {
                    valid_intervals++;
                }
            }
        }

        if (valid_intervals == 0) {
            cout << -1 << endl;
        } else {
            cout << valid_intervals << endl;
        }
    }
}

int main() {
    solve();
    return 0;
}
