#include <iostream>
using namespace std;

#define MAXSIZE 100

typedef struct
{
    int data[MAXSIZE];
    int length;
} Sqlist;

void bubble(Sqlist &L)
{
    for (int i = L.length - 1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (L.data[j] > L.data[j + 1])
            {
                swap(L.data[j], L.data[j + 1]);
            }
        }
    }
}
