/*
给定一个 R行 C列的矩阵，表示一个矩形网格滑雪场。矩阵中第 i行第 j列的点表示滑雪场的第 i行第 j列区域的高度。
一个人从滑雪场中的某个区域内出发，每次可以向上下左右任意一个方向滑动一个单位距离。
当然，一个人能够滑动到某相邻区域的前提是该区域的高度低于自己目前所在区域的高度。
下面给出一个矩阵作为例子：
 1  2  3  4 5
16 17 18 19 6
15 24 25 20 7
14 23 22 21 8
13 12 11 10 9
在给定矩阵中，一条可行的滑行轨迹为 24−17−2−1。
在给定矩阵中，最长的滑行轨迹为 25−24−23−…−3−2−1，沿途共经过 25个区域。现在给定你一个二维矩阵表示滑雪场各区域的高度，请你找出在该滑雪场中能够完成的最长滑雪轨迹，并输出其长度(可经过最大区域数)。
*/
#include<iostream>
#include<cstring>
using namespace std;
const int N = 310;
int n,m;
int g[N][N];
int f[N][N];
int dx[4] = {-1,0,1,0},dy[4] = {0,-1,0,1};
int dp(int x,int y){
    if(f[x][y] != -1) return f[x][y]; 
    f[x][y] = 1;
    for(int i = 0;i < 4;i++){
        int a = x + dx[i],b = y + dy[i];
        if(a >= 1 && a <= n && b >= 1 && b <= m&& g[a][b] > g[x][y]){
            f[x][y] = max(f[x][y],dp(a,b)+1);
        }
    }
    return f[x][y];
}
int main(){
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
        for(int j = 1 ; j <= m;j++)
            cin >> g[i][j];
    memset(f,-1,sizeof f);//初始化为-1表示没有走过
    int res = -1;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            res = max(res,dp(i,j));
        }
    }
    cout << res << endl;
    return 0;
}
