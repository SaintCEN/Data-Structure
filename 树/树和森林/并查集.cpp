#include <iostream>
using namespace std;

const int MAXN = 1000;
int father[MAXN];
int Rank[MAXN];

void init()
{
    for (int i = 0; i < MAXN; i++)
    {
        father[i] = i;
        Rank[i] = 1;
    }
}

int find_set(int x)
{
    if (x != father[x])
    {
        father[x] = find_set(father[x]);
    }
    return father[x];
}

void Union(int x, int y)
{
    int root_x = find_set(x);
    int root_y = find_set(y);
    if (root_x == root_y)
        return;
    if (Rank[root_x] > Rank[root_y])
    {
        father[root_y] = root_x;
        Rank[root_x] += Rank[root_y];
    }
    else
    {
        father[root_x] = root_y;
        Rank[root_y] += Rank[root_x];
    }
}

int main()
{
    init();
    return 0;
}