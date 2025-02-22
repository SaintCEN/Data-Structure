#include <cstring>
#include <iostream>
using namespace std;
const int N = 1e5 + 3;
int h[N], e[N], ne[N], idx;  
int n;
void insert(int x) {
    int k = (x % N + N) % N;//整数，k为哈希值
    e[idx] = x;//存储在哈希表的idx位置
    ne[idx] = h[k];//存储idx位置的哈希值为k的索引
    h[k] = idx++;//自增，为下一次插入准备空间
}
bool find(int x) {
    int k = (x % N + N) % N;
    for (int i = h[k]; i != -1; i = ne[i]) {
        if (e[i] == x) {
            return true;
        }
    }
    return false;
}
int main() {
    cin >> n;
    memset(h, -1, sizeof h); 
    while (n--) {
        string op;
        int x;
        cin >> op >> x;
        if (op == "I") {
            insert(x);
        } else {
            if (find(x)) {
                puts("Yes");
            } else {
                puts("No");
            }
        }
    }
    return 0;
}