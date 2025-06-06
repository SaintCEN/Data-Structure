#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, p;
    cin >> n >> p;

    vector<char> filled(p, 0);
    vector<int> info(n);
    unordered_map<int, int> mp;

    for (int i = 0; i < n; i++)
    {
        int key;
        cin >> key;

        auto it = mp.find(key);
        if (it != mp.end())
        {
            info[i] = it->second;
            continue;
        }

        int h = key % p;
        if (h < 0)
            h += p;
        while (filled[h])
        {
            h = (h + 1) % p;
        }
        filled[h] = 1;
        mp[key] = h;
        info[i] = h;
    }

    for (int i = 0; i < n; i++)
    {
        cout << info[i] << " ";
    }
    return 0;
}
