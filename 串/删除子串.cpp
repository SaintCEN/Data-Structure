#include <stdio.h>

char *StrRemove(char *str, int idx, int len);

int main()
{
    char a[1024];
    int i, n;
    gets(a);
    scanf("%d%d", &i, &n);
    StrRemove(a, i, n);
    puts(a);
    return 0;
}

char *StrRemove(char *str, int idx, int len)
{
    if (str == NULL || idx < 0 || len <= 0)
    {
        return str;
    }
    int str_len = 0;
    while (str[str_len] != '\0')
    {
        str_len++;
    }
    if (idx >= str_len)
    {
        return str;
    }
    if (idx + len >= str_len)
    {
        len = str_len - idx;
    }
    for (int i = idx + len; i <= str_len; i++)
    {
        str[i - len] = str[i];
    }
    return str;
}