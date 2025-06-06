#include <stdio.h>
#include <stdlib.h>

typedef enum
{
    true,
    false,
    maybe
} Keys;

typedef Keys ElementType;

void Read(ElementType A[], int N); /* details omitted */

void MySort(ElementType A[], int N);

void PrintA(ElementType A[], int N)
{
    int i, k;

    k = i = 0;
    for (; i < N && A[i] == false; i++)
        ;
    if (i > k)
        printf("false in A[%d]-A[%d]\n", k, i - 1);
    k = i;
    for (; i < N && A[i] == maybe; i++)
        ;
    if (i > k)
        printf("maybe in A[%d]-A[%d]\n", k, i - 1);
    k = i;
    for (; i < N && A[i] == true; i++)
        ;
    if (i > k)
        printf("true in A[%d]-A[%d]\n", k, i - 1);
    if (i < N)
        printf("Wrong Answer\n");
}

int main()
{
    int N;
    ElementType *A;

    scanf("%d", &N);
    A = (ElementType *)malloc(N * sizeof(ElementType));
    Read(A, N);
    MySort(A, N);
    PrintA(A, N);
    return 0;
}

void MySort(ElementType A[], int N)
{
    int low = 0;
    int high = N - 1;
    int mid = 0;

    while (mid <= high)
    {
        if (A[mid] == false)
        {
            ElementType tmp = A[mid];
            A[mid] = A[low];
            A[low] = tmp;
            low++;
            mid++;
        }
        else if (A[mid] == maybe)
        {
            mid++;
        }
        else
        {
            ElementType tmp = A[mid];
            A[mid] = A[high];
            A[high] = tmp;
            high--;
        }
    }
}