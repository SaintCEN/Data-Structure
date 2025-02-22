#include <iostream>
#include <string>
using namespace std;
typedef unsigned long long ULL;
const int N = 1e5 + 10, P = 131;
ULL h[N], p[N];
ULL get(int l, int r)
{
    return h[r] - h[l - 1] * p[r - l + 1];
}

int main()
{
    p[0] = 1;

    int n, m;
    string s;
    cin >> n >> m >> s;

    for(int i = 1; i <= n; i++)
    {
        // 用 p 数组存储 p 的幂, p[i] 表示 p 的 i 次幂
        p[i] = p[i - 1] * P;            
        // 根据性质 1 挨个计算 h[i]
        h[i] = h[i - 1] * P + s[i - 1];     
    }

    while(m--)
    {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;

        if(get(l1, r1) == get(l2, r2)) cout << "Yes" << endl;
        else cout << "No" << endl;
    }

    return 0;
}
//h[i]=h[i−1]×P+hash(s[i])
//有字符串 s1 s2 和 s1s2,hash(s2)=hash(s1s2)−hash(s1)×P|s2|