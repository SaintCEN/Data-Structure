#include <iostream>
using namespace std;
const int N = 1000010;
char p[N], s[N]; // 用 p 来匹配 s
// “next” 数组，若第 i 位存储值为 k
// 说明 p[0...i] 内最长相等前后缀的前缀的最后一位下标为 k
// 即 p[0...k] == p[i-k...i]
int ne[N]; 
int n, m; // n 是模板串长度 m 是模式串长度
int main()
{
    cin >> n >> p >> m >> s;
    // p[0...0] 的区间内一定没有相等前后缀
    ne[0] = -1;
    // 构造模板串的 next 数组
    for (int i = 1, j = -1; i < n; i ++)
    {
        while (j != -1 && p[i] != p[j + 1])
        {
            // 若前后缀匹配不成功
            // 反复令 j 回退，直至到 -1 或是 s[i] == s[j + 1]
            j = ne[j];
        }
        if (p[i] == p[j + 1]) 
        {
            j ++; // 匹配成功时，最长相等前后缀变长，最长相等前后缀前缀的最后一位变大
        }
        ne[i] = j; // 令 ne[i] = j，以方便计算 next[i + 1]
    }
    // kmp start !
    for (int i = 0, j = -1; i < m; i ++)
    {
       while (j != -1 && s[i] != p[j + 1])
       {
           j = ne[j];
       }
       if (s[i] == p[j + 1])
       {
           j ++; // 匹配成功时，模板串指向下一位
       }
       if (j == n - 1) // 模板串匹配完成，第一个匹配字符下标为 0，故到 n - 1
       {
           // 匹配成功时，文本串结束位置减去模式串长度即为起始位置
           cout << i - j << ' ';
           // 模板串在模式串中出现的位置可能是重叠的
           // 需要让 j 回退到一定位置，再让 i 加 1 继续进行比较
           // 回退到 ne[j] 可以保证 j 最大，即已经成功匹配的部分最长
           j = ne[j]; 
       }
    }

   return 0;
}