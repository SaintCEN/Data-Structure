#include <iostream>
#include <queue>
#include <cmath>
#include <vector>
using namespace std;

int d, N;
const double r = 7.5;
const int l = 50;

int main()
{
    cin >> N >> d;
    vector<pair<int, int>> v(N + 1);
    vector<bool> visited(N + 1, false);

    for (int i = 1; i <= N; ++i)
    {
        int x, y;
        cin >> x >> y;
        v[i] = {x, y};
    }

    queue<pair<int, int>> q;

    for (int i = 1; i <= N; ++i)
    {
        int x = v[i].first, y = v[i].second;
        if (sqrt(x * x + y * y) <= d + r)
        {
            q.push(v[i]);
            visited[i] = true;
        }
    }

    while (!q.empty())
    {
        auto current = q.front();
        q.pop();
        int x = current.first, y = current.second;

        if (abs(x - l) <= d || abs(x + l) <= d ||
            abs(y - l) <= d || abs(y + l) <= d)
        {
            cout << "Yes" << endl;
            return 0;
        }

        for (int i = 1; i <= N; ++i)
        {
            if (!visited[i])
            {
                int X = v[i].first, Y = v[i].second;
                double dist = sqrt((x - X) * (x - X) + (y - Y) * (y - Y));
                if (dist <= d)
                {
                    q.push(v[i]);
                    visited[i] = true;
                }
            }
        }
    }

    cout << "No" << endl;
    return 0;
}