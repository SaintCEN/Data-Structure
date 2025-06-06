#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define kMaxLen 1000

int LCS(char x[], int n, char y[], int m);

int main(void)
{
    char x[kMaxLen + 1], y[kMaxLen + 1];

    scanf("%s\n", x);
    scanf("%s\n", y);
    printf("%d\n", LCS(x, strlen(x), y, strlen(y)));

    return 0;
}
int LCS(char x[], int n, char y[], int m)
{
    int **dp = (int **)malloc((n + 1) * sizeof(int *));
    for (int i = 0; i <= n; i++)
    {
        dp[i] = (int *)malloc((m + 1) * sizeof(int));
        dp[i][0] = 0;
    }
    for (int i = 0; i <= m; i++)
    {
        dp[0][i] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (x[i - 1] == y[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                if (dp[i][j - 1] > dp[i - 1][j])
                {
                    dp[i][j] = dp[i][j - 1];
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
    }
    int len = dp[n][m];
    char *lcs = (char *)malloc((len + 1) * sizeof(char));
    lcs[len] = '\0';
    int i = n, j = m;
    int pos = len - 1;

    while (i > 0 && j > 0)
    {
        if (x[i - 1] == y[j - 1])
        {
            lcs[pos--] = x[i - 1];
            i--;
            j--;
        }
        else if (dp[i - 1][j] >= dp[i][j - 1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }

    printf("%s\n", lcs);
    for (int i = 0; i <= n; i++)
    {
        free(dp[i]);
    }
    free(dp);
    free(lcs);
    return len;
}