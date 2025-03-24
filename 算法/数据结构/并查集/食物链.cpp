//animals*n a->b->c three type
#include <iostream>
using namespace std;
const int N = 1000001;
int par[N];//root
int rank[N];//height
void init(int n){//initialize
    for(int i = 0; i < n; i++){
        par[i] = i;
        rank[i] = 0;
    }
}
int find(int x){//find root
    if (par[x] == x){
        return x;
    } else {
        return par[x] = find(par[x]);
    }
}
void unite(int x, int y){//compound x&y
    x = find(x);
    y = find(y);
    if(x == y) return;
    if(rank[x] < rank[y]){
        par[x] = y;
    } else {
        par[y] = x;
        if(rank[x] == rank[y]) rank[x]++;
    }
}
bool same(int x, int y){
    return find(x) == find(y);
}
int main(){
    int n, k;
    cin >> n >> k;
    init(n * 3);
    int ans = 0;
    for(int i = 0; i < k; i++){
        int t, x, y;
        cin >> t >> x >> y;
        x--; y--;//1~n base to 0~n-1 base
        if(x < 0 || x >= n || y < 0 || y >= n){
            ans++;
            continue;
        }
        if(t == 1){//x&y same
            if(same(x, y + n) || same(x, y + 2 * n)){
                ans++;
            }
            else{
                unite(x, y + n);
                unite(x + n, y + n);
                unite(x + 2 * n, y + 2 * n);
            }
        }
        else{//x eat y
            if(same(x, y) || same(x, y + 2 * n)){
                ans++;
            }
            else{
                unite(x, y);
                unite(x + n, y + 2 * n);
                unite(x + 2 * n, y);
            }
        }
    }
    cout << ans << endl;
    return 0;
}