#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> sqtree(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> sqtree[i];
    }
    int i, j;
    cin >> i >> j;

    if (sqtree[i] == 0)
    {
        cout << "ERROR: T[" << i << "] is NULL";
        return 0;
    }
    if (sqtree[j] == 0)
    {
        cout << "ERROR: T[" << j << "] is NULL";
        return 0;
    }

    unordered_set<int> ancestor;
    while (i >= 1)
    {
        ancestor.insert(i);
        i /= 2;
    }
    ancestor.insert(1);
    while (j >= 1)
    {
        if (ancestor.find(j) != ancestor.end())
        {
            cout << j << " " << sqtree[j];
            return 0;
        }
        j /= 2;
    }
    cout << "1" << " " << sqtree[1];
    return 0;
}