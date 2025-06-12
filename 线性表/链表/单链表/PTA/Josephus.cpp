#include <stdio.h>
#include <stdlib.h>

typedef int ElemSet;
typedef struct ListNode *Position; /* 指针即结点位置 */
struct ListNode
{
    ElemSet data;  /* 存储数据 */
    Position next; /* 线性表中下一个元素的位置 */
};
typedef struct HeadNode *List;
struct HeadNode
{
    Position head; /* 单链表头指针 */
    int length;    /* 表长 */
};

List JosephusProblem(int n, int m);

void PrintList(List list)
{ /* 顺序输出链表结点数据 */
    Position p;

    p = list->head->next; /* p指向第1个结点 */
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}
int main(void)
{
    List list;
    int n, m;
    scanf("%d %d", &n, &m);
    list = JosephusProblem(n, m);
    PrintList(list);
    return 0;
}

List JosephusProblem(int n, int m)
{
    if (n <= 0 || m <= 0)
        return NULL;

    List circle = (List)malloc(sizeof(struct HeadNode));
    circle->length = n;
    Position head = (Position)malloc(sizeof(struct ListNode));
    head->next = NULL;
    circle->head = head;

    Position tail = head;
    for (int i = 1; i <= n; i++)
    {
        Position node = (Position)malloc(sizeof(struct ListNode));
        node->data = i;
        node->next = NULL;
        tail->next = node;
        tail = node;
    }
    tail->next = head->next;

    List ans = (List)malloc(sizeof(struct HeadNode));
    ans->length = 0;
    Position ansHead = (Position)malloc(sizeof(struct ListNode));
    ansHead->next = NULL;
    ans->head = ansHead;
    Position ansTail = ansHead;

    Position prev = head;
    while (prev->next != head->next)
    {
        prev = prev->next;
    }

    int remaining = n;
    while (remaining > 0)
    {
        for (int step = 1; step < m; step++)
        {
            prev = prev->next;
        }
        Position toRemove = prev->next;
        prev->next = toRemove->next;

        Position newNode = (Position)malloc(sizeof(struct ListNode));
        newNode->data = toRemove->data;
        newNode->next = NULL;
        ansTail->next = newNode;
        ansTail = newNode;
        ans->length++;

        free(toRemove);
        remaining--;
    }

    free(head);
    return ans;
}