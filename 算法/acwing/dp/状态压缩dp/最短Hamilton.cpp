//0—n-1每个点都经过一次
//w[i][j]表示i点和j点的距离
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=20,M=1<<N;
int f[M][N],w[N][N];//w表示无权图
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
     for(int j=0;j<n;j++)
      cin>>w[i][j];
    memset(f,0x3f,sizeof(f));//初始化为无穷大
    f[1][0]=0;//因为零是起点,所以f[1][0]=0;
    for(int i=0;i<1<<n;i++)//i表示所有的情况
     for(int j=0;j<n;j++)//j表示走到哪一个点
      if(i>>j&1)//第j位是1
       for(int k=0;k<n;k++)//k表示走到j这个点之前,以k为终点的最短距离
        if(i>>k&1)//第k位是1
         f[i][j]=min(f[i][j],f[i-(1<<j)][k]+w[k][j]);//更新最短距离

    cout<<f[(1<<n)-1][n-1]<<endl;//表示所有点都走过了,且终点是n-1的最短距离
    return 0;
}