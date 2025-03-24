//Trie树快速存储字符集合和快速查询字符集合
#include <iostream>
using namespace std;
const int N = 100010;
//son[][]存储子节点的位置，分支最多26条；
//cnt[]存储以某节点结尾的字符串个数（同时也起标记作用）
//idx表示当前要插入的节点是第几个,每创建一个节点值+1
int son[N][26], cnt[N], idx;
char str[N];
void insert(char *str)
{
    int p = 0;  //类似指针，指向当前节点
    for(int i = 0; str[i]; i++)
    {
        int u = str[i] - 'a'; //将字母转化为数字
        if(!son[p][u]) son[p][u] = ++idx;   //该节点不存在，创建节点
        p = son[p][u];  //使“p指针”指向下一个节点
    }
    cnt[p]++;  //结束时的标记，也是记录以此节点结束的字符串个数
}
int query(char *str)
{
    int p = 0;
    for(int i = 0; str[i]; i++)
    {
        int u = str[i] - 'a';
        if(!son[p][u]) return 0;  //该节点不存在，即该字符串不存在
        p = son[p][u]; 
    }
    return cnt[p];  //返回字符串出现的次数
}
int main()
{
    int m;
    cin >> m;

    while(m--)
    {
        char op[2];
        scanf("%s%s", op, str);

        if(*op == 'I') insert(str);
        else printf("%d\n", query(str));
    }

    return 0;
}