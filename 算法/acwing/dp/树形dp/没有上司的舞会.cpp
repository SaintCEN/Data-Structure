/*Ural 大学有 N名职员，编号为 1∼N。他们的关系就像一棵以校长为根的树，父节点就是子节点的直接上司。
每个职员有一个快乐指数，用整数 Hi给出，其中 1≤i≤N。现在要召开一场周年庆宴会，不过，没有职员愿意和直接上司一起参会。
在满足这个条件的前提下，主办方希望邀请一部分职员参会，使得所有参会职员的快乐指数总和最大，求这个最大值。*/
#include<bits/stdc++.h>
using namespace std; 
const int N = 10010;
int e[N],ne[N],h[N],idx;//单链表
int happy[N];//存快乐值 
int n; 
bool has_fa[N];//判断某人有没有上司 
int f[N][2];
//f[u][1]:以u为根节点的子树并且包括u的总快乐指数，
//f[u][0]:以u为根节点并且不包括u的总快乐指数;
void add(int a,int b)
{
    e[idx]=b,ne[idx]=h[a],h[a]=idx,idx++;  
}
void dfs(int u)//递归每一个点
{
    f[u][1]=happy[u];//该boss要来，此时快乐值至少为该boss的快乐值 
    for(int i=h[u];i!=-1;i=ne[i])//从头节点开始遍历邻接表 
    {
        int j=e[i];//取出相连点所存的值 （点的编号） 
        dfs(j);//用该值开始新遍历
        f[u][1]+=f[j][0];//u是j的上司，存在领导关系，所以一定不能让j来
        f[u][0]+=max(f[j][0],f[j][1]);//u可以作为j和u的上司的中间人，j来不来都可以 
}
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) cin>>happy[i];
    memset(h,-1,sizeof h);
    for(int i=n+1;i<2*n;i++)
    {
        int a,b;
        scanf("%d %d",&b,&a);
        has_fa[b]=true;//确认b有上司
        add(a,b);//加边建树 
    }
    int root=1; 
    while (has_fa[root])root++;//找到没有上司的节点，即为根节点
    dfs(root);//从根节点开始dfs遍历 
    printf("%d\n", max(f[root][0],f[root][1]));//比较头节点的两种方案 
    return 0;
}