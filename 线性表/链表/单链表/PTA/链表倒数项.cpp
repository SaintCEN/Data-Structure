#include <stdio.h>
#include <stdlib.h>

#define ERROR -1
typedef int ElemSet;
typedef struct ListNode *Position; /* 指针即结点位置 */
typedef Position List;
struct ListNode
{
    ElemSet data;  /* 存储数据 */
    Position next; /* 线性表中下一个元素的位置 */
};

List ReadList()
{ /* 创建带空头结点的、有n个数据结点的单链表 */
    List p, rear;
    int n;
    scanf("%d", &n);
    p = (List)malloc(sizeof(struct ListNode));
    p->next = NULL;
    rear = p;
    while (n--)
    { /* 新读入的数据插在链表尾 */
        rear->next = (List)malloc(sizeof(struct ListNode));
        scanf("%d", &rear->next->data);
        rear->next->next = NULL;
        rear = rear->next;
    }
    return p;
}

void PrintList(List list)
{ /* 顺序输出带空头结点的单链表的结点数据 */
    while (list->next != NULL)
    {
        list = list->next;
        printf("%d ", list->data);
    }
    printf("\n");
}

ElemSet Find(List list, int m);

int main(void)
{
    List list;
    int m;

    list = ReadList();
    scanf("%d", &m);
    printf("%d\n", Find(list, m));
    PrintList(list);
    return 0;
}

ElemSet Find(List list, int m)
{
    int n = 0;
    Position p = list->next;

    while (p != NULL)
    {
        n++;
        p = p->next;
    }

    if (m <= 0 || m > n)
    {
        return ERROR;
    }

    int k = n - m + 1;
    Position prev = list;
    for (int i = 0; i < k; i++)
    {
        prev = prev->next;
    }
    return prev->data;
}