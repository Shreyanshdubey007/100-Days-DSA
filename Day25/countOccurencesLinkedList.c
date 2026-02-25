//Problem: Count Occurrences of an Element in Linked List - Implement using linked list with dynamic memory allocation.

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int countOccurrences(struct Node* head, int key) {
    int count = 0;
    struct Node* temp = head;

    while (temp != NULL) {
        if (temp->data == key)
            count++;
        temp = temp->next;
    }

    return count;
}

int main() {
    int n, value, key;
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        if (newNode == NULL) {
            printf("Memory allocation failed\n");
            return 1;
        }

        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) {
            head = temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    printf("Enter element to count: ");
    scanf("%d", &key);

    int result = countOccurrences(head, key);
    printf("Occurrences of %d: %d\n", key, result);

    return 0;
}