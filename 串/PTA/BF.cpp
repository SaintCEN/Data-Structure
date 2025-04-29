#include <stdio.h>
#include <string.h>

char *StrStr(const char *txt, const char *pat);

int main()
{
    char m[1024], s[1024], *p;
    gets(m);
    gets(s);
    p = StrStr(m, s);
    if (p)
    {
        printf("Found at %d\n", (int)(p - m));
    }
    else
    {
        puts("Not found");
    }
    return 0;
}
char *StrStr(const char *txt, const char *pat)
{
    if (*pat == '\0')
    {
        return NULL;
    }

    for (int i = 0; txt[i] != '\0'; i++)
    {
        int j = 0;
        while (pat[j] != '\0' && txt[i + j] == pat[j])
        {
            j++;
        }
        if (pat[j] == '\0')
        {
            return (char *)(txt + i);
        }
    }
    return NULL;
}