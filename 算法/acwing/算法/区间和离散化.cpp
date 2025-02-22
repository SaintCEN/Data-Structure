#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 300010; //x l r 各占100000,多的十个数防止越位
typedef pair<int,int>PII;//可以使用typedef为类型取一个新的名字。 例如将pair<int,int> 取名为PII 后续引用PII就等于引用pair<int,int> 
int n, m;
int a[N],s[N];//前缀和
vector<int>alls;//定义一维变长数组alls,将所有待离散化的值都存入,进行离散化
vector<PII>add,query;//定义二维变长数组add和query
int find(int x)//二分
{
    int l = 0,r = alls.size() - 1;
    while(l < r)
    {
        int mid =  l + r >> 1;
        if(alls[mid] >= x) r= mid;
        else l = mid + 1;
    }
    return r + 1;
}
int main()
{
    cin >> n >>m;//输入程序会进行几次操作，几次询问
    //根据题意可知,首先进行n次操作,每次操作将某一位置x上的数加c
    for(int i = 0 ; i< n;i++)
    {
        int x , c;
        cin >> x >>c;
        add.push_back({x,c});//push_back 在数组最后添加数据 给add行二维变长数组添加值
        alls.push_back(x); //给x添加值
    }
    //接下来进行m次询问，每次询问包含两个整数l,r，求出区间[l,r]所有数的和
    for(int i = 0 ; i< m ;i ++)
    {
        int l , r;
        cin >> l >> r;
        query.push_back({l,r});
    //此时alls已经添加上了该加c的x的坐标,每次循环都会添加对应的区间
        alls.push_back(l);//
        alls.push_back(r);
    }
    // 去除数组中重复元素
    sort(alls.begin(),alls.end());//先将坐标排序
    alls.erase(unique(alls.begin(),alls.end()), alls.end());//去重 只保留不重复数据
    //处理输入
    for(auto item : add)//意思是将 add 容器中的每一个元素从前往后枚举出来，并用 item 来表示
    {
        int x = find(item.first);//add是一个二维变长数组,item.first就是二维数组里的第一个数{1,8}就为1 
        // cout << x << ' ';//检测x值 因为find引入的alls的长度，所以要根据alls的长度来看数据
        a[x] += item.second;//同理item.second就是二维数组里的第二个数{1,8}就为8
    }
    //预处理前缀和
    for(int i = 1 ;i <= alls.size(); i++)s[i] = s[i-1] + a[i];
    //处理询问
    for(auto item : query)
    {
        int l = find(item.first),r = find(item.second);
        cout << s[r] - s[l - 1] <<endl;//求离散化后的边界进行前缀和相减
    }
    return 0;
}