#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define maxlen 255

// 顺序存储
typedef struct
{
    char ch[maxlen];
    int length;
} SString;

// 堆分配存储
typedef struct
{
    char *ch;
    int length;
} HString;

// 链式存储
typedef struct CharNode
{
    char ch;
    struct CharNode *next;
} CharNode, *CharPtr;

typedef struct
{
    CharPtr head;
    int length;
} LString;

// 字串定位算法
// Brute-Force
int BF(SString s, SSting t, int pos)
{
    int i = pos;
    int j = 1;
    while (i <= s.length && j <= t.length())
    {
        if (s.ch[i] == t.ch[j])
        {
            i++;
            j++;
        }
        else
        {
            i = i - j + 2;
            j = 1;
        }
    }
    if (j > t.length)
        return i - t.length;
    else
        return 0;
}

// KMP 1-based
void next(SString T, int next[])
{
    int i = 1, j = 0;
    next[1] = 0;
    while (i < T.length)
    {
        if (j == 0 || T.ch[i] == T.ch[j])
        {
            i++;
            j++; // 先自增的原因是next数组某下标的值是某下标-1的值
            next[i] = j;
        }
        else
        {
            j = next[j];
        }
    }
}

int KMP_Search(SString S, SString T)
{
    int next[] = new int[];
    get_next(T, next);

    int i = 1, j = 1;
    while (i <= S.length && j <= T.length)
    {
        if (j == 0 || S.ch[i] == T.ch[j])
        {
            i++;
            j++;
        }
        else
        {
            j = next[j];
        }
    }

    if (j > T.length)
        return i - T.length;
    else
        return 0;
}