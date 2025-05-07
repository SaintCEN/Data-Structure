#include <iostream>
#include <climits>
#include <vector>

using namespace std;

const int MVNum = 201;
const int INF = INT_MAX;

struct MGraph
{
    int arcs[MVNum][MVNum];
    int VexNum, ArcNum;
};

void Create(MGraph &G)
{
    cin >> G.VexNum >> G.ArcNum;

    for (int i = 0; i <= G.VexNum; i++)
    {
        for (int j = 0; j <= G.VexNum; j++)
        {
            G.arcs[i][j] = INF;
        }
        G.arcs[i][i] = 0;
    }

    for (int k = 0; k < G.ArcNum; k++)
    {
        int a, b, d;
        cin >> a >> b >> d;
        G.arcs[a][b] = d;
        G.arcs[b][a] = d;
    }
}

void Check(MGraph G)
{
    int K;
    cin >> K;
    int validCount = 0;
    int minCost = INF;
    int minIndex = -1;

    for (int i = 1; i <= K; i++)
    {
        int n;
        cin >> n;
        vector<int> path(n);
        for (int j = 0; j < n; j++)
        {
            cin >> path[j];
        }

        if (n != G.VexNum)
            continue;

        vector<bool> visited(G.VexNum + 1, false);
        bool valid = true;

        for (int v : path)
        {
            if (v < 1 || v > G.VexNum || visited[v])
            {
                valid = false;
                break;
            }
            visited[v] = true;
        }
        if (!valid)
            continue;

        for (int v = 1; v <= G.VexNum; v++)
        {
            if (!visited[v])
            {
                valid = false;
                break;
            }
        }
        if (!valid)
            continue;

        int totalCost = 0;

        if (G.arcs[0][path[0]] == INF)
            continue;

        totalCost += G.arcs[0][path[0]];

        for (int j = 0; j < n - 1; j++)
        {
            if (G.arcs[path[j]][path[j + 1]] == INF)
            {
                valid = false;
                break;
            }
            totalCost += G.arcs[path[j]][path[j + 1]];
        }
        if (!valid)
            continue;

        if (G.arcs[path[n - 1]][0] == INF)
            continue;
        totalCost += G.arcs[path[n - 1]][0];

        validCount++;
        if (totalCost < minCost || (totalCost == minCost && i < minIndex))
        {
            minCost = totalCost;
            minIndex = i;
        }
    }

    cout << validCount << endl;
    if (validCount > 0)
    {
        cout << minIndex << " " << minCost << endl;
    }
}

int main()
{
    MGraph G;
    Create(G);
    Check(G);
    return 0;
}