#include <iostream>
using namespace std;

#define maxlen 255
#define chunksize 80
// 顺序存储
typedef struct
{
    char ch[maxlen + 1];
    int length;
} SString;
// 链式存储
typedef struct chunk
{
    char ch[chunksize];
    struct chunk *next;
} chunk;
typedef struct
{
    chunk *head, *tail;
    int length;
} LString;