#include <iostream>

using namespace std;

void QuickSort(int a[], int m, int n)
{
    if (m >= n)
        return;

    int low = m;
    int high = n;
    int pivot = a[(m + n) / 2];
    while (low <= high)
    {
        while (a[low] < pivot)
            low++;
        while (a[high] > pivot)
            high--;
        if (low <= high)
        {
            swap(a[low], a[high]);
            low++;
            high--;
        }
    }
    QuickSort(a, m, high);
    QuickSort(a, low, n);
}

int main()
{
    int a[] = {5, 4, 6, 3, 2};
    int n = sizeof(a) / sizeof(a[0]);

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    QuickSort(a, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}