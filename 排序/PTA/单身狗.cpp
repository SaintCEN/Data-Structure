#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    unordered_map<int, int> cp;
    for (int i = 0; i < N; i++)
    {
        int husband, wife;
        cin >> husband >> wife;
        cp[husband] = wife;
        cp[wife] = husband;
    }

    unordered_set<int> attend;
    int M;
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        int guest;
        cin >> guest;
        attend.insert(guest);
    }

    vector<int> single;
    for (auto it : attend)
    {
        int partner = cp[it];
        if (attend.find(partner) == attend.end())
        {
            single.push_back(it);
        }
    }

    sort(single.begin(), single.end());
    cout << single.size() << endl;
    for (int i = 0; i < single.size(); i++)
    {
        if (i > 0)
            cout << " ";
        cout << single[i];
    }
}