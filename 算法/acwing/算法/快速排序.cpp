#include <stdio.h>

void swap(int *px, int *py);
void quick_sort(int q[], int l, int r);

int main() {
    int N = 1000000;
    int n;
    int q[N];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &q[i]);
    }
    quick_sort(q, 0, n - 1);
    for (int i = 0; i < n; i++) {
        printf("%d ", q[i]); 
    }
    printf("\n"); 
    return 0;
}

void swap(int *px, int *py) {
    int t;
    t = *px;
    *px = *py;
    *py = t;
}

void quick_sort(int q[], int l, int r)
{
    if(l >= r) return;
    int i = l , j = r , x = q[(l + r) >> 1];
    while(i < j)
    {
        while(q[i] < x) i++;
        while(q[j] > x) j--;
        if(i <= j) swap(&q[i],& q[j]);
    }
    quick_sort(q, l, j);
	quick_sort(q, j + 1, r);

    
}
