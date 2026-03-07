//Problem: Queue Using Array - Implement using linked list with dynamic memory allocation.

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

void enqueue(int val) {
    struct Node* newNode = createNode(val);

    if (rear == NULL) {
        front = newNode;
        rear = newNode;
    }
    else {
        rear->next = newNode;
        rear = newNode;
    }

    printf("Enqueued: %d\n", val);
}

void dequeue() {
    if (front == NULL) {
        printf("Queue Underflow\n");
        return;
    }
    else {
        printf("Dequeued: %d\n", front->data);
        struct Node* temp = front;
        front = front->next;

        if (front == NULL) {
            rear = NULL;
        }

        free(temp);
    }
}

void display() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue (front to rear): ");
    struct Node* temp = front;

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

int main() {
    int n, val;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements: ", n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        enqueue(val);
    }

    display();

    return 0;
}