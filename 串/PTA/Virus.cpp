#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<int> Next(const string &j)
{
    int m = j.length();
    vector<int> next(m + 1, 0);
    int k = 0;
    next[0] = -1;
    for (int i = 1; i < m; i++)
    {
        while (k >= 0 && j[i] != j[k])
        {
            k = next[k];
        }
        k++;
        next[i + 1] = k;
    }
    return next;
}
bool KMP(const string &t, const string &j)
{
    int n = t.length();
    int m = j.length();
    if (m == 0)
    {
        return false;
    }
    vector<int> next = Next(j);
    int i = 0;
    int k = 0;

    while (i < n)
    {
        if (k == -1 || t[i] == j[k])
        {
            i++;
            k++;
            if (k == m)
            {
                return true;
            }
        }
        else
        {
            k = next[k];
        }
    }
    return false;
}
bool Infected(const string &virus, const string &patient)
{
    int m = virus.length();
    string extendedVirus = virus + virus; // 环状检测

    for (int i = 0; i < m; i++)
    {
        string pattern = extendedVirus.substr(i, m);
        if (KMP(patient, pattern))
        {
            return true;
        }
    }
    return false;
}
int main()
{
    int i;
    cin >> i;
    cin.ignore();
    while (i--)
    {
        string virus, patient;
        cin >> virus >> patient;
        if (Infected(virus, patient))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}
