#include <stdio.h>

int Flower(int* a, int n, int m, int k);

int main() {
    int m, n, k;
    scanf("%d%d%d", &n, &m, &k);
    int a[n + 1]; 
    for (int i = 1; i <= n; i++) {
        a[i] = i;
    }
    int ans = Flower(a, n, m, k);
    printf("%d", ans);
    return 0;
}

int Flower(int* a, int n, int m, int k) {
    int count = m;
    int peopleLeft = n; 
    while (peopleLeft > 1) {
        for (int i = 0; i < k ; i++) {
                count++;
                if (count > n) count = 1;
                if (a[count]==0) count++;
        }
        a[count-1] = 0; 
        peopleLeft--; 
    }

    for (int i = 1; i <= n; i++) {
        if (a[i] != 0) {
            return a[i]; 
        }
    }
}

#include <stdio.h>
int josephus(int n, int m, int k) {
    if (n == 1) {
        return m;
    } else {
        return (josephus(n - 1, m, k) + k) % n;
    }
}
int main() {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    int result = josephus(n, m - 1, k) + 1;
    printf("%d\n", result);
    return 0;
}


#include <iostream>
#include <queue>
using namespace std;

int josephus(int n, int m, int k) {
    queue<int> q;
    for (int i = m; i <= n; i++) {
        q.push(i);
    }
    for (int i = 1; i < m; i++) {
        q.push(i);
    }
    while (q.size() > 1) {
        for (int i = 1; i < k; i++) {
            int front = q.front();
            q.pop();
            q.push(front);  
        }
        q.pop();  
    }
    return q.front();
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    int result = josephus(n, m, k);
    cout << result << endl;
    return 0;
}