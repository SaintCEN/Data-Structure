#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int data;
    struct ListNode *next;
};

struct ListNode *createlist(); 
struct ListNode *reverse( struct ListNode *head );
void printlist( struct ListNode *head )
{
     struct ListNode *p = head;
     while (p) {
           printf("%d ", p->data);
           p = p->next;
     }
     printf("\n");
}

int main()
{
    struct ListNode  *head;

    head = createlist();
    head = reverse(head);
    printlist(head);
    
    return 0;
}

struct ListNode *reverse( struct ListNode *head ){
    struct ListNode *p = NULL;
    struct ListNode *current = head;
    struct ListNode *next = NULL;
        while(current != NULL){
            next = current->next;
            current->next = p;
            p = current;
            current = next;
        }
        return p;
}