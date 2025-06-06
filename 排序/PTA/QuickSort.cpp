#include <iostream>
using namespace std;

#define MAXSIZE 50
typedef int KeyType;

typedef struct
{
    KeyType key;
} ElemType;

typedef struct
{
    ElemType r[MAXSIZE + 1];
    int length;
} SqList;

void Create(SqList &L)
{
    int i;
    cin >> L.length;
    for (i = 1; i <= L.length; i++)
        cin >> L.r[i].key;
}

void Output(SqList L)
{
    int i;
    for (i = 1; i <= L.length; i++)
        cout << L.r[i].key << " ";
    cout << endl;
    ;
}

int Partition(SqList &L, int low, int high);
void QuickSort(SqList &L, int low, int high);

int main()
{
    SqList L;
    int low, high;
    Create(L);
    low = 1;
    high = L.length;
    QuickSort(L, low, high);
    Output(L);
    return 0;
}

int Partition(SqList &L, int low, int high)
{
    int info = high;
    KeyType pivot = L.r[info].key;
    while (low <= high)
    {
        while (L.r[low].key < pivot)
            low++;
        while (L.r[high].key > pivot)
            high--;
        if (low <= high)
        {
            ElemType temp = L.r[low];
            L.r[low] = L.r[high];
            L.r[high] = temp;
            low++;
            high--;
        }
    }
    return high;
}

void QuickSort(SqList &L, int low, int high)
{
    if (low < high)
    {
        int p = Partition(L, low, high);
        QuickSort(L, low, p);
        QuickSort(L, p + 1, high);
    }
}