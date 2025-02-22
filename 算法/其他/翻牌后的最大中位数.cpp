/*
n张卡片摆成一排，其中n是奇数。每张牌的两面都写着数字。在这张牌上，ai面朝上，bi面朝下。
格莱美希望最大化所有朝上数字的中位数。为了达到这个目的，她可以进行以下操作最多一次。
选择一个区间[l，r]，翻转区间内的所有纸牌。翻牌后，bi朝上，ai朝下。
请帮格莱美计算在她的最优策略下所有朝上的数字的中位数。
*/
#include <stdio.h>
#include <stdlib.h>
int find_median(int *arr,int n);
int compare(const void *a,const void *b);
int find_max_midian(int *a,int *b,int n);
int main() {
    int n;
    scanf("%d", &n);

    int *a = (int *)malloc(n * sizeof(int));
    int *b = (int *)malloc(n * sizeof(int));
    int *c = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &a[i], &b[i]);
        c[i] = a[i];
    }

    int maxMedian=find_max_midian(a,b,n);
    
    free(a);
    free(b);
    free(c);
    
    printf("%d",maxMedian);
    
    return 0;
}

int find_median(int *arr,int n){
	return arr[n/2];
}

int find_max_median(int *a , int *b , int n){
	int maxMedian = find_median(a, n);
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int *temp = (int *)malloc(n * sizeof(int));
            for (int k = 0; k < n; k++) {
                if (k >= i && k <= j) {
                    temp[k] = b[k];
                } else {
                    temp[k] = a[k];
                }
            }
            qsort(temp, n, sizeof(int), compare);
            int currentMedian = find_median(temp, n);
            maxMedian = currentMedian > maxMedian ? currentMedian : maxMedian;
            free(temp);
        }
    }
    return maxMedian;
}