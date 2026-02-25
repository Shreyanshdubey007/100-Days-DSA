//Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *detectCycle(struct ListNode *head) {
    if (head == NULL || head->next == NULL)
        return NULL;

    struct ListNode *slow = head;
    struct ListNode *fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            slow = head;
            while (slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }

    return NULL;
}

int main() {
    int n, x, pos;
    struct ListNode *head = NULL, *temp = NULL, *newNode = NULL;
    struct ListNode *cycleNode = NULL;
    int index = 0;

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

    printf("Enter position to create cycle (-1 for no cycle): ");
    scanf("%d", &pos);

    temp = head;
    index = 0;
    while (temp != NULL) {
        if (index == pos)
            cycleNode = temp;
        if (temp->next == NULL)
            break;
        temp = temp->next;
        index++;
    }

    if (pos != -1 && temp != NULL)
        temp->next = cycleNode;

    struct ListNode *result = detectCycle(head);

    if (result == NULL)
        printf("No cycle\n");
    else {
        int idx = 0;
        temp = head;
        while (temp != result) {
            temp = temp->next;
            idx++;
        }
        printf("Cycle starts at node index %d\n", idx);
    }

    return 0;
}