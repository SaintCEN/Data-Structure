#include <bits/stdc++.h>
using namespace std;

int ipow32(int e)
{
    int r = 1;
    while (e--)
        r *= 32;
    return r;
}

int main()
{
    int n, p;
    cin >> n >> p;

    vector<int> filled(p, 0);
    vector<int> info(n);
    unordered_map<string, int> mp;

    for (int i = 0; i < n; i++)
    {
        string key;
        cin >> key;

        auto it = mp.find(key);
        if (it != mp.end())
        {
            info[i] = it->second;
            continue;
        }

        long long hash = 0;
        int len = min(3, (int)key.size());
        for (int j = 0; j < len; j++)
        {
            int c = key[key.size() - 1 - j] - 'A';
            hash += 1LL * c * ipow32(j);
        }

        int h = int((hash % p + p) % p);

        if (filled[h])
        {
            for (int k = 1; k < p; k++)
            {
                int p1 = (h + k * k) % p;
                int p2 = (h - k * k % p + p) % p;
                if (!filled[p1])
                {
                    h = p1;
                    break;
                }
                if (!filled[p2])
                {
                    h = p2;
                    break;
                }
            }
        }

        mp[key] = h;
        info[i] = h;
        filled[h] = 1;
    }

    for (int i = 0; i < n; i++)
    {
        cout << info[i] << " ";
    }
    return 0;
}