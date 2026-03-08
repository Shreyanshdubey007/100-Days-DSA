//Problem: Circular Queue Using Array - Implement using linked list with dynamic memory allocation.

#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

struct Node {
    int data;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;
int size = 0;

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
        rear->next = front;
    }
    else {
        rear->next = newNode;
        rear = newNode;
        rear->next = front;
    }

    size++;
    printf("Enqueued: %d\n", val);
}

void dequeue() {
    if (front == NULL) {
        printf("Queue Underflow\n");
        return;
    }
    else if (front == rear) {
        printf("Dequeued: %d\n", front->data);
        free(front);
        front = NULL;
        rear = NULL;
    }
    else {
        printf("Dequeued: %d\n", front->data);
        struct Node* temp = front;
        front = front->next;
        rear->next = front;
        free(temp);
    }

    size--;
}

void display() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue (front to rear): ");
    struct Node* temp = front;

    for (int i = 0; i < size; i++) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

int main() {
    int n, m, val;

    printf("Enter number of elements to enqueue: ");
    scanf("%d", &n);

    printf("Enter %d elements: ", n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        enqueue(val);
    }

    printf("Enter number of dequeue operations: ");
    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        dequeue();
    }

    display();

    return 0;
}