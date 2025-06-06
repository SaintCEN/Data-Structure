#include <stdio.h>
#include <stdlib.h>

typedef struct ActivityNode *Activities;
struct ActivityNode
{
    int start;  /* 开始时间 */
    int finish; /* 结束时间 */
};

int CmpStart(const void *a, const void *b)
{
    return (((const struct ActivityNode *)a)->start > ((const struct ActivityNode *)b)->start) ? 1 : -1;
}

int main(void)
{
    Activities a;
    int n, i;

    scanf("%d", &n);
    a = (Activities)malloc(sizeof(struct ActivityNode) * (n + 1));
    a[0].finish = 0; /* a[0] 是一个虚设的活动，其结束时间为 0 */
    a[0].start = 0;
    for (i = 1; i <= n; i++)
    {
        scanf("%d %d", &a[i].start, &a[i].finish);
    }
    qsort(a, n + 1, sizeof(struct ActivityNode), CmpStart);
    printf("%d", ActivityScheduling(a, n));

    return 0;
}

int ActivityScheduling(Activities a, int n)
{
    if (n == 0)
        return 0;
    int *heap = (int *)malloc((n + 2) * sizeof(int));
    int heap_size = 0;
    int max_rooms = 0;

    for (int i = 1; i <= n; i++)
    {
        int start = a[i].start;
        int finish = a[i].finish;

        while (heap_size > 0 && heap[0] <= start)
        {
            heap[0] = heap[heap_size - 1];
            heap_size--;
            int current = 0;
            while (1)
            {
                int left = 2 * current + 1;
                int right = 2 * current + 2;
                int smallest = current;
                if (left < heap_size && heap[left] < heap[smallest])
                {
                    smallest = left;
                }
                if (right < heap_size && heap[right] < heap[smallest])
                {
                    smallest = right;
                }
                if (smallest != current)
                {
                    int temp = heap[current];
                    heap[current] = heap[smallest];
                    heap[smallest] = temp;
                    current = smallest;
                }
                else
                {
                    break;
                }
            }
        }

        heap[heap_size] = finish;
        heap_size++;
        int current = heap_size - 1;
        while (current > 0)
        {
            int parent = (current - 1) / 2;
            if (heap[current] < heap[parent])
            {
                int temp = heap[parent];
                heap[parent] = heap[current];
                heap[current] = temp;
                current = parent;
            }
            else
            {
                break;
            }
        }

        if (heap_size > max_rooms)
        {
            max_rooms = heap_size;
        }
    }

    free(heap);
    return max_rooms;
}