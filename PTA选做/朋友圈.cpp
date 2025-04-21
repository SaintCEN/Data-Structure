#include <iostream>
using namespace std;

const int MAXN = 30001;
int father[MAXN];
int Size[MAXN];

void init()
{
    for (int i = 0; i < MAXN; ++i)
    {
        father[i] = i;
        Size[i] = 1;
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

    if (Size[root_x] < Size[root_y])
    {
        father[root_x] = root_y;
        Size[root_y] += Size[root_x];
    }
    else
    {
        father[root_y] = root_x;
        Size[root_x] += Size[root_y];
    }
}

int main()
{
    init();
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < M; ++i)
    {
        int Mi, first, student;
        cin >> Mi >> first;
        for (int j = 1; j < Mi; ++j)
        {
            cin >> student;
            Union(first, student);
        }
    }

    int max_circle = 0;
    for (int i = 1; i <= N; ++i)
    {
        int root = find_set(i);
        if (Size[root] > max_circle)
        {
            max_circle = Size[root];
        }
    }

    cout << max_circle << endl;
    return 0;
}