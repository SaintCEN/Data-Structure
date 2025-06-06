#include <stdio.h>

void Print(int *s, int n);
void Queens(int n);

int main(void)
{
    int n;
    scanf("%d", &n);
    Queens(n);
    return 0;
}

int abs(int x)
{
    if (x < 0)
    {
        return -x;
    }
    else
    {
        return x;
    }
}

int cmp(int *a, int *b, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] > b[i])
        {
            return 1;
        }
        if (a[i] < b[i])
        {
            return 0;
        }
    }
    return 0;
}

void cpy(int *a, int *b, int n)
{
    for (int i = 0; i < n; i++)
    {
        b[i] = a[i];
    }
}

void dfs(int row, int n, int *s, int *s_max)
{
    if (row == n)
    {
        if (cmp(s, s_max, n))
        {
            cpy(s, s_max, n);
        }
    }

    for (int col = 0; col < n; col++)
    {
        int k;
        for (k = 0; k < row; k++)
        {
            if (s[k] == col)
            {
                break;
            }
            if (abs(col - s[k]) == abs(k - row))
            {
                break;
            }
        }
        if (k == row)
        {
            s[row] = col;
            dfs(row + 1, n, s, s_max);
        }
    }
}

void Queens(int n)
{
    int s[20];
    int s_max[20];
    dfs(0, n, s, s_max);
    for (int i = 0; i < n; i++)
    {
        s_max[i] = -1;
    }
    Print(s_max, n);
}