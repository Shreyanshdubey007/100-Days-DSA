//Problem Statement: Implement a Queue using a linked list supporting enqueue and dequeue operations.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
        printf("-1\n");
        return;
    }

    printf("Dequeued: %d\n", front->data);
    struct Node* temp = front;
    front = front->next;

    if (front == NULL) {
        rear = NULL;
    }

    free(temp);
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
    char op[20];

    printf("Enter number of operations: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter operation (enqueue/dequeue/display): ");
        scanf("%s", op);

        if (op[0] == 'e' && op[1] == 'n') {
            printf("Enter value: ");
            scanf("%d", &val);
            enqueue(val);
        }
        else if (op[0] == 'd') {
            dequeue();
        }
        else if (op[0] == 'd' && op[1] == 'i') {
            display();
        }
    }

    return 0;
}