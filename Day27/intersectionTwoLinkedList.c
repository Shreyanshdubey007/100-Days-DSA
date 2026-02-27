//Problem: Find Intersection Point of Two Linked Lists - Implement using linked list with dynamic memory allocation.

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createList(int n) {
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;
    int value;

    for (int i = 0; i < n; i++) {
        scanf("%d", &value);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        if (newNode == NULL) {
            printf("Memory allocation failed\n");
            exit(1);
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
    return head;
}

int getLength(struct Node* head) {
    int len = 0;
    while (head != NULL) {
        len++;
        head = head->next;
    }
    return len;
}

struct Node* findIntersection(struct Node* head1, struct Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    struct Node *ptr1 = head1, *ptr2 = head2;
    int diff = abs(len1 - len2);

    if (len1 > len2) {
        for (int i = 0; i < diff; i++)
            ptr1 = ptr1->next;
    } else {
        for (int i = 0; i < diff; i++)
            ptr2 = ptr2->next;
    }

    while (ptr1 != NULL && ptr2 != NULL) {
        if (ptr1->data == ptr2->data)
            return ptr1;
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    return NULL;
}

int main() {
    int n, m;
    struct Node *list1, *list2, *intersection;

    printf("Enter number of nodes in first list: ");
    scanf("%d", &n);
    printf("Enter %d elements:\n", n);
    list1 = createList(n);

    printf("Enter number of nodes in second list: ");
    scanf("%d", &m);
    printf("Enter %d elements:\n", m);
    list2 = createList(m);

    intersection = findIntersection(list1, list2);

    if (intersection != NULL)
        printf("Intersection at node with value: %d\n", intersection->data);
    else
        printf("No Intersection\n");

    return 0;
}