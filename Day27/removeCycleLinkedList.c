//Remove loop in Linked List

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void removeLoop(struct Node* head) {
    if (head == NULL || head->next == NULL)
        return;

    struct Node *slow = head, *fast = head;

    // Detect loop using Floyd’s Cycle Detection
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            break;
    }

    // No loop
    if (slow != fast)
        return;

    slow = head;

    // If loop starts at head
    if (slow == fast) {
        while (fast->next != slow)
            fast = fast->next;
    } else {
        while (slow->next != fast->next) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    // Remove loop
    fast->next = NULL;
}

void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int n, pos;
    scanf("%d", &n);

    if (n <= 0) return 0;

    struct Node* head = NULL;
    struct Node* tail = NULL;

    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);

        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = x;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Position where cycle starts (0-based index, -1 for no cycle)
    scanf("%d", &pos);

    if (pos >= 0) {
        struct Node* temp = head;
        for (int i = 0; i < pos && temp != NULL; i++) {
            temp = temp->next;
        }
        if (temp != NULL) {
            tail->next = temp; // Create loop
        }
    }

    removeLoop(head);

    printList(head);

    return 0;
}