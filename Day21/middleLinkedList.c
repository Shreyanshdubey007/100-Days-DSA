//Given the head of a singly linked list, return the middle node of the linked list.
//If there are two middle nodes, return the second middle node.

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* middleNode(struct ListNode* head) {
    if (head == NULL) return NULL;

    struct ListNode *slow = head;
    struct ListNode *fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

int main() {
    int n, x;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    struct ListNode *head = NULL, *temp = NULL, *newNode;

    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        newNode->val = x;
        newNode->next = NULL;

        if (head == NULL) {
            head = temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    struct ListNode *mid = middleNode(head);

    printf("Middle onwards: ");
    while (mid != NULL) {
        printf("%d ", mid->val);
        mid = mid->next;
    }

    return 0;
}