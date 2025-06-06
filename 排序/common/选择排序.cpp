#include <iostream>
using namespace std;

#define MAXSIZE 100
typedef struct
{
    int data[MAXSIZE];
    int length;
} Sqlist;

void Select(Sqlist &L)
{
    for (int i = 0; i < L.length - 1; i++)
    {
        int k = i;
        for (int j = i + 1; j < L.length; j++)
        {
            if (L.data[j] < L.data[k])
            {
                k = j;
            }
        }
        if (k != i)
        {
            swap(L.data[i], L.data[k]);
        }
    }
}
