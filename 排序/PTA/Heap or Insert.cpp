#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    if (!(cin >> N))
        return 0;
    vector<int> orig(N), partial(N);
    for (int i = 0; i < N; i++)
        cin >> orig[i];
    for (int i = 0; i < N; i++)
        cin >> partial[i];

    int k = 1;
    while (k < N && partial[k] >= partial[k - 1])
        k++;
    bool ok = true;
    for (int i = k; i < N; i++)
    {
        if (partial[i] != orig[i])
        {
            ok = false;
            break;
        }
    }
    if (ok)
    {
        cout << "Insertion Sort" << "\n";
        vector<int> next = partial;
        int val = next[k];
        int i = k;
        while (i > 0 && next[i - 1] > val)
        {
            next[i] = next[i - 1];
            i--;
        }
        next[i] = val;
        for (int j = 0; j < N; j++)
        {
            cout << next[j] << (j + 1 < N ? ' ' : '\n');
        }
    }
    else
    {
        cout << "Heap Sort" << "\n";
        vector<int> heap = orig;
        auto cmp = less<int>();
        int heapSize = N;
        function<void(int, int)> siftdown = [&](int i, int sz)
        {
            int largest = i;
            int l = 2 * i + 1, r = 2 * i + 2;
            if (l < sz && heap[l] > heap[largest])
                largest = l;
            if (r < sz && heap[r] > heap[largest])
                largest = r;
            if (largest != i)
            {
                swap(heap[i], heap[largest]);
                siftdown(largest, sz);
            }
        };
        for (int i = (heapSize / 2) - 1; i >= 0; i--)
            siftdown(i, heapSize);
        bool found = false;
        for (int i = N - 1; i > 0; i--)
        {
            swap(heap[0], heap[i]);
            siftdown(0, i);
            if (heap == partial)
            {
                swap(heap[0], heap[i - 1]);
                siftdown(0, i - 1);
                for (int j = 0; j < N; j++)
                {
                    cout << heap[j] << (j + 1 < N ? ' ' : '\n');
                }
                found = true;
                break;
            }
        }
        if (!found)
        {
            swap(heap[0], heap[N - 1]);
            siftdown(0, N - 1);
            for (int j = 0; j < N; j++)
            {
                cout << heap[j] << (j + 1 < N ? ' ' : '\n');
            }
        }
    }
    return 0;
}