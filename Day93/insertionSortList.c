//Given the head of a singly linked list, sort the list using insertion sort, and return the sorted list's head.

#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode* newNode(int val)
{
    struct ListNode *node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val  = val;
    node->next = NULL;
    return node;
}

struct ListNode* insertionSortList(struct ListNode* head)
{
    struct ListNode dummy;
    dummy.val  = 0;
    dummy.next = NULL;

    struct ListNode *curr = head;

    while (curr != NULL)
    {
        struct ListNode *next = curr->next;
        struct ListNode *prev = &dummy;

        while (prev->next != NULL && prev->next->val < curr->val)
        {
            prev = prev->next;
        }

        curr->next = prev->next;
        prev->next = curr;
        curr       = next;
    }

    return dummy.next;
}

void printList(struct ListNode *head)
{
    while (head != NULL)
    {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

int main()
{
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    struct ListNode *head = NULL;
    struct ListNode *tail = NULL;

    printf("Enter elements: ");
    for (int i = 0; i < n; i++)
    {
        int val;
        scanf("%d", &val);

        struct ListNode *node = newNode(val);

        if (head == NULL)
        {
            head = node;
            tail = node;
        }
        else
        {
            tail->next = node;
            tail       = node;
        }
    }

    struct ListNode *sorted = insertionSortList(head);

    printf("Sorted list: ");
    printList(sorted);

    return 0;
}