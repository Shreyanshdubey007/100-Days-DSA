//Given the head of a singly linked list, reverse the list, and return the reversed list.

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode *prev = NULL;
    struct ListNode *curr = head;
    struct ListNode *next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

int main() {
    int n, x;
    struct ListNode *head = NULL, *temp = NULL, *newNode = NULL;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);

        newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        if (newNode == NULL) {
            printf("Memory allocation failed\n");
            return 1;
        }

        newNode->val = x;
        newNode->next = NULL;

        if (head == NULL) {
            head = temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    head = reverseList(head);

    printf("Reversed list: ");
    temp = head;
    while (temp != NULL) {
        printf("%d ", temp->val);
        temp = temp->next;
    }

    return 0;
}