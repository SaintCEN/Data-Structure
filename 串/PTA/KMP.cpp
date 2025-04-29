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

void KMP(const string &t, const string &j)
{
    int n = t.length();
    int m = j.length();
    if (m == 0)
    {
        cout << "Not Found" << endl;
        return;
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
                cout << t.substr(i - m) << endl;
                return;
            }
        }
        else
        {
            k = next[k];
        }
    }
    cout << "Not Found" << endl;
}

int main()
{
    string t;
    int n;
    getline(cin, t);
    cin >> n;
    cin.ignore();
    while (n--)
    {
        string j;
        getline(cin, j);
        KMP(t, j);
    }
    return 0;
}
/*
示例说明
假设模式串为 j = "ababc"，计算 next 数组的过程如下：
初始化：
next[0] = -1
k = 0
计算 next[1]：
i = 1，j[1] = 'b'，j[k] = 'a'
j[1] != j[k]，且 k == 0，回退到 next[0] = -1
k++，k = 0
next[1] = 0
计算 next[2]：
i = 2，j[2] = 'a'，j[k] = 'a'
j[2] == j[k]，k++，k = 1
next[2] = 1
计算 next[3]：
i = 3，j[3] = 'b'，j[k] = 'b'
j[3] == j[k]，k++，k = 2
next[3] = 2
计算 next[4]：
i = 4，j[4] = 'c'，j[k] = 'a'
j[4] != j[k]，回退到 next[k] = next[2] = 1
j[4] != j[k]，回退到 next[k] = next[1] = 0
j[4] != j[k]，回退到 next[k] = next[0] = -1
k++，k = 0
next[4] = 0
最终 next 数组为：[-1, 0, 0, 1, 2, 0]。
*/