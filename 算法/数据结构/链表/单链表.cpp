#include <iostream>
using namespace std;
const int N = 100010;
int n;
int h[N], e[N], ne[N], head, idx;

void init(){
    head = -1;
    idx = 0;
}
void int_to_head(int x){
    e[idx] = x;
    ne[idx] = head;
    head = idx;
    idx ++;
}
void add(int k, int x){
    e[idx] = x;
    ne[idx] = ne[k];
    ne[k] = idx;
    idx ++;
}
void remove(int k){
    ne[k] = ne[ne[k]];
}
int main(){
    cin >> n;
    init();
    for (int i = 0; i < n; i ++ ) {
        char s;
        cin >> s;
        if (s == 'H') {
            int x;
            cin >> x;
            int_to_head(x);
        }
        if (s == 'D'){
            int k;
            cin >> k;
            if (k == 0) head = ne[head];
            else remove(k - 1);
        }
        if (s == 'I'){
            int k, x;
            cin >> k >> x;
            add(k - 1, x);
        }
    }
    for (int i = head; i != -1; i = ne[i]) cout << e[i] << ' ' ;
    cout << endl;
    return 0;
}
