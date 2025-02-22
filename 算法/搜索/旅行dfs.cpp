#include<cstdio>
#include<iostream>
using namespace std;

typedef struct {
    int a[101][101];
    int vex_num;
    int arc_num;
} Graph;

Graph G;

int visited[101] = {0};
int sequence[101] = {0};
int count = 1;
int endcount = 0;

void DFS(int u) {
    if (visited[u] == 0) {
        if (u == G.vex_num) {
            endcount = count;
        }
        sequence[count] = u;
        count++;
    }
    visited[u] = 1;

    if (u == G.vex_num) {
        return;
    }

    for (int l = 1; l <= G.vex_num; l++) {
        if (G.a[u][l] == 1 && visited[l] == 0) {
            DFS(l);
        }
    }

    visited[u] = 0;
    return;
}
int main() {
    int i, j;
    scanf("%d %d", &G.vex_num, &G.arc_num);
    for (int k = 1; k <= G.arc_num; k++) {
        scanf("%d %d", &i, &j);
        G.a[i][j] = G.a[j][i] = 1;
    }

    DFS(1);

    if (visited[G.vex_num] == 1) {
        printf("YES\n");
        for (j = 1; j <= endcount; j++) {
            if (sequence[j] != 0) {
                printf("%d ", sequence[j]);
            }
        }
    } else {
        printf("NO\n");
        endcount = count;
        for (j = 1; j <= endcount; j++) {
            if (sequence[j] != 0) {
                printf("%d ", sequence[j]);
            }
        }
    }
    return 0;
}
//vector&<int> push_back