#define MAXSIZE 100

typedef int Elemtype;
typedef struct
{
    Elemtype *data;
    int length;
} Sqlist;

void Init(Sqlist &L)
{
    L.length = 0;
    L.data = new Elemtype[MAXSIZE];
}

void Insert(Sqlist &L, int i, Elemtype e)
{
    if (i < 1 || i > L.length + 1)
    {
        return;
    }
    if (L.length >= MAXSIZE)
    {
        return;
    }
    for (int j = L.length; j >= i; j--)
    { // 第i号下标为i-1
        L.data[j] = L.data[j - 1];
    }
    L.data[i - 1] = e;
    L.length++;
}

void Delete(Sqlist &L, int i, Elemtype &e)
{
    if (i < 1 || i > L.length)
    {
        return;
    }
    e = L.data[i - 1];
    for (int j = i; j < L.length; j++)
    {
        L.data[j - 1] = L.data[j];
    }
    L.length--;
}

int Locate(Sqlist L, Elemtype e)
{
    for (int i = 0; i < L.length; i++)
    {
        if (L.data[i] == e)
        {
            return i;
        }
    }
}

void del_all_x(Sqlist &L, Elemtype x)
{
    int k = 0;
    for (int i = 0; i < L.length; i++)
    {
        if (L.data[i] != x)
        {
            L.data[k] = L.data[i];
            k++;
        }
    }
    L.length = k;
}

void del_same(Sqlist &L)
{ // 已经为有序表
    int i, j;
    for (int i = 0, j = 1; j < L.length; j++)
    {
        if (L.data[i] != L.data[j])
        {
            i++;
            L.data[i] = L.data[j];
            L.length = i + 1;
        }
    }
}

void Merge(Sqlist &A, Sqlist &B, Sqlist &C)
{
    int i = 0, j = 0, k = 0;
    while (i < A.length && j < B.length)
    {
        if (A.data[i] <= B.data[j])
        {
            C.data[k] = A.data[i];
            i++;
            k++;
        }
        else
        {
            C.data[k] = B.data[j];
            j++;
            k++;
        }
    }
    while (i < A.length)
    {
        C.data[k] = A.data[i];
        k++;
        i++;
    }
    while (j < B.length)
    {
        C.data[k] = B.data[j];
        k++;
        j++;
    }
    C.length = k;
}

void DeleteKElem(Sqlist &L, int i, int k)
{
    if (i < 1 || k < 0 || i + k > L.length + 1)
    {
        return;
    }
    else
    {
        if (k == 0)
            return;
        for (int j = i + k; j <= L.length; j++)
        {
            L.data[j - k] = L.data[j];
        }
        L.length -= k;
    }
}