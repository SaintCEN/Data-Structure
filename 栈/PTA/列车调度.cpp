#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> tops; 
    for (int i = 0; i < n; i++) {
        auto it = lower_bound(tops.begin(), tops.end(), a[i]);
        if (it != tops.end()) {
            *it = a[i];
        } else {
            tops.push_back(a[i]);
        }
    }

    cout << tops.size() << endl;
    return 0;
}