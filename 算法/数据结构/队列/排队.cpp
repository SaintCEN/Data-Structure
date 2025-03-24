#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    deque<int> q;  

    q.push_back(1);  

    for (int i = 2; i <= n; i++) {
        int num, flag;
        cin >> num >> flag;

        auto it = find(q.begin(), q.end(), num);

        if (it != q.end()) {  
            if (flag == 1) {  
                q.insert(it + 1, i);
            } 
			if (flag == 0) {  
                q.insert(it, i);
            }
        } else {  
            if (flag == 1) {  
                q.push_back(i);  
            } 
			if (flag == 0) {  
                q.insert(it, i);
            }
        }
    }

    int m;
    cin >> m;

    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;

        auto it = find(q.begin(), q.end(), x);
        if (it != q.end()) {      
            q.erase(it);  
        }

    }

    while (q.size()>0) {
        cout << q.front() << " ";
        q.pop_front();
    }

    return 0;
}

