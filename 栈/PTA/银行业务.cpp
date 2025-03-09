#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n;
    cin >> n;
    queue<int> qa;
    queue<int> qb;

    int x;

    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x % 2 == 1) {
            qa.push(x);
        } else {
            qb.push(x);
        }
    }

    while (!qa.empty() || !qb.empty()) {
        if (qa.empty()) {
            cout << qb.front() << " ";
            qb.pop();
        } else if (qb.empty()) {
            cout << qa.front() << " ";
            qa.pop();
        } else {
                cout << qa.front() << " ";
                qa.pop();
                cout << qa.front() << " ";
                qa.pop();
                cout << qb.front() << " ";
                qb.pop();
        }
    }
    cout << endl;
    return 0;
}