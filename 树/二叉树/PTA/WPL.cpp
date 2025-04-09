#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef struct
{
    int weight;
    int lchild, rchild, parent;
} HTNode, *HuffmanTree;

void CreateHuffmanTree(int n, HuffmanTree &HT)
{
    int m = 2 * n - 1;
    HT = new HTNode[m + 1];
    for (int i = 1; i <= m; i++)
    {
        HT[i].lchild = 0;
        HT[i].rchild = 0;
        HT[i].parent = 0;
    }

    for (int i = 1; i <= n; i++)
    {
        cin >> HT[i].weight;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (int i = 1; i <= n; i++)
    {
        pq.push({HT[i].weight, i});
    }

    for (int i = n + 1; i <= m; i++)
    {
        int s1 = pq.top().second;
        int min1 = pq.top().first;
        pq.pop();
        int s2 = pq.top().second;
        int min2 = pq.top().first;
        pq.pop();
        HT[s1].parent = i;
        HT[s2].parent = i;
        HT[i].lchild = s1;
        HT[i].rchild = s2;
        HT[i].weight = min1 + min2;
        pq.push({HT[i].weight, i});
    }

    int WPL = 0;
    for (int i = 1; i <= n; i++)
    {
        int length = 0;
        int current = i;
        while (HT[current].parent != 0)
        {
            length++;
            current = HT[current].parent;
        }
        WPL += length * HT[i].weight;
    }
    cout << WPL << endl;
}

int main()
{
    int n;
    cin >> n;
    HTNode *HT = NULL;
    CreateHuffmanTree(n, HT);
    delete[] HT;
    return 0;
}
