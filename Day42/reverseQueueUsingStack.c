//Problem Statement: Given a queue of integers, reverse the queue using a stack.

#include <stdio.h>
#include <stdlib.h>

struct QNode {
    int data;
    struct QNode* next;
};

struct SNode {
    int data;
    struct SNode* next;
};

struct QNode* front = NULL;
struct QNode* rear = NULL;
struct SNode* top = NULL;

struct QNode* createQNode(int val) {
    struct QNode* newNode = (struct QNode*)malloc(sizeof(struct QNode));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

struct SNode* createSNode(int val) {
    struct SNode* newNode = (struct SNode*)malloc(sizeof(struct SNode));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

void enqueue(int val) {
    struct QNode* newNode = createQNode(val);

    if (rear == NULL) {
        front = newNode;
        rear = newNode;
    }
    else {
        rear->next = newNode;
        rear = newNode;
    }
}

int dequeue() {
    if (front == NULL) {
        return -1;
    }

    int val = front->data;
    struct QNode* temp = front;
    front = front->next;

    if (front == NULL) {
        rear = NULL;
    }

    free(temp);
    return val;
}

void push(int val) {
    struct SNode* newNode = createSNode(val);
    newNode->next = top;
    top = newNode;
}

int pop() {
    if (top == NULL) {
        return -1;
    }

    int val = top->data;
    struct SNode* temp = top;
    top = top->next;
    free(temp);
    return val;
}

void displayQueue() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    printf("Reversed queue: ");
    struct QNode* temp = front;

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

void reverseQueue() {
    while (front != NULL) {
        push(dequeue());
    }

    while (top != NULL) {
        enqueue(pop());
    }
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

    reverseQueue();

    displayQueue();

    return 0;
}