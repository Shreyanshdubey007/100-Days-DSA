//Implement a first in first out (FIFO) queue using only two stacks.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

typedef struct {
    int s1[MAX];
    int s2[MAX];
    int top1;
    int top2;
} MyQueue;

MyQueue* myQueueCreate() {
    MyQueue* obj = (MyQueue*)malloc(sizeof(MyQueue));
    obj->top1 = -1;
    obj->top2 = -1;
    return obj;
}

void myQueuePush(MyQueue* obj, int x) {
    obj->s1[++obj->top1] = x;
    printf("Pushed: %d\n", x);
}

int myQueuePop(MyQueue* obj) {
    if (obj->top2 == -1) {
        while (obj->top1 >= 0) {
            obj->s2[++obj->top2] = obj->s1[obj->top1--];
        }
    }

    return obj->s2[obj->top2--];
}

int myQueuePeek(MyQueue* obj) {
    if (obj->top2 == -1) {
        while (obj->top1 >= 0) {
            obj->s2[++obj->top2] = obj->s1[obj->top1--];
        }
    }

    return obj->s2[obj->top2];
}

bool myQueueEmpty(MyQueue* obj) {
    if (obj->top1 == -1 && obj->top2 == -1) {
        return true;
    }
    else {
        return false;
    }
}

void myQueueFree(MyQueue* obj) {
    free(obj);
}

int main() {
    MyQueue* myQueue = myQueueCreate();

    int n, choice, val;

    printf("Enter number of operations: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("\nEnter operation (1=push, 2=pop, 3=peek, 4=empty): ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter value to push: ");
            scanf("%d", &val);
            myQueuePush(myQueue, val);
        }
        else if (choice == 2) {
            printf("Popped: %d\n", myQueuePop(myQueue));
        }
        else if (choice == 3) {
            printf("Front element: %d\n", myQueuePeek(myQueue));
        }
        else if (choice == 4) {
            if (myQueueEmpty(myQueue)) {
                printf("Queue is empty: true\n");
            }
            else {
                printf("Queue is empty: false\n");
            }
        }
    }

    myQueueFree(myQueue);

    return 0;
}