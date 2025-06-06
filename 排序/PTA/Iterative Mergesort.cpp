#include <stdio.h>

#define ElementType int
#define MAXN 100

void merge_pass(ElementType list[], ElementType sorted[], int N, int length);

void output(ElementType list[], int N)
{
    int i;
    for (i = 0; i < N; i++)
        printf("%d ", list[i]);
    printf("\n");
}

void merge_sort(ElementType list[], int N)
{
    ElementType extra[MAXN]; /* the extra space required */
    int length = 1;          /* current length of sublist being merged */
    while (length < N)
    {
        merge_pass(list, extra, N, length); /* merge list into extra */
        output(extra, N);
        length *= 2;
        merge_pass(extra, list, N, length); /* merge extra back to list */
        output(list, N);
        length *= 2;
    }
}

int main()
{
    int N, i;
    ElementType A[MAXN];

    scanf("%d", &N);
    for (i = 0; i < N; i++)
        scanf("%d", &A[i]);
    merge_sort(A, N);
    output(A, N);

    return 0;
}

void merge_pass(ElementType list[], ElementType sorted[], int N, int length)
{
    int i;
    for (i = 0; i < N; i += 2 * length)
    {
        int left_start = i;
        int left_end = (i + length < N) ? (i + length) : N;

        int right_start = left_end;
        int right_end = (i + 2 * length < N) ? (i + 2 * length) : N;

        int left = left_start;
        int right = right_start;
        int sorted_idx = left_start;

        while (left < left_end && right < right_end)
        {
            if (list[left] <= list[right])
            {
                sorted[sorted_idx++] = list[left++];
            }
            else
            {
                sorted[sorted_idx++] = list[right++];
            }
        }

        while (left < left_end)
        {
            sorted[sorted_idx++] = list[left++];
        }

        while (right < right_end)
        {
            sorted[sorted_idx++] = list[right++];
        }
    }
}
