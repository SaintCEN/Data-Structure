#include <iostream>
using namespace std;

const int N = 11;

char q[N][N];
bool dg[N * 2], udg[N * 2], cor[N];

int n;

void dfs(int r)
{
    if(r == n)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
                cout << q[i][j];
            cout << endl;
        }
        cout << endl;
        return;
    }

    for(int i = 0; i < n; i++)
    {
        if(!cor[i] && !dg[i + r] && !udg[n - i + r])
        {
            q[r][i] = 'Q';
            cor[i] = dg[i + r] = udg[n - i + r] = 1;
            dfs(r + 1);
            cor[i] = dg[i + r] = udg[n - i + r] = 0;
            q[r][i] = '.';
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i ++ )
        for (int j = 0; j < n; j ++ )
            q[i][j] = '.';
    dfs(0);
    return 0;
}