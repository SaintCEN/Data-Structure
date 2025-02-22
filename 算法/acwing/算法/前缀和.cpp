#include <iostream>
#include <cstdio>

using namespace std;

const int N = 100010;

int n , m; //第一行的两个整数 其中n表示数列有几个元素，m表示有几行
int a[N],s[N]; //a[N]表示的是第N项,s[N]表示前N项和
int main()
{
    scanf("%d%d",&n,&m); //读入第一行的两个整数
    for(int i = 1; i<= n ;i++) scanf("%d",&a[i]); //读入第二行的n个数，并存入a[N]中

    for(int i = 1 ; i <= n; i++) s[i] = s[i-1] + a[i]; //前缀和（dfs） 前N项等于前N-1项加上第N个数 用空间换时间

    while (m -- ) //进入循环
    {
        int l , r; 
        scanf("%d%d",&l,&r);//每次循环读入一遍第3行及以后的数
        printf("%d\n",s[r] - s[l - 1]); // 要求输出输出原序列中从第 l个数到第 r个数的和 用前r项的和减去前l-1项的和则得到从l到r的和
    }
    return 0;
}
/*
S[i, j] = 第i行j列格子左上部分所有元素的和
以(x1, y1)为左上角，(x2, y2)为右下角的子矩阵的和为：
S[x2, y2] - S[x1 - 1, y2] - S[x2, y1 - 1] + S[x1 - 1, y1 - 1]
*/