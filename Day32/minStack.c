//Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

#include <stdio.h>

#include <stdlib.h>

#define MAX 30001

typedef struct {
    int stack[MAX];
    int minStack[MAX];
    int top;
    int minTop;
} MinStack;

MinStack* minStackCreate() {
    MinStack* obj = (MinStack*)malloc(sizeof(MinStack));
    obj->top = -1;
    obj->minTop = -1;
    return obj;
}

void minStackPush(MinStack* obj, int val) {
    obj->stack[++obj->top] = val;
    if (obj->minTop == -1 || val <= obj->minStack[obj->minTop]) {
        obj->minStack[++obj->minTop] = val;
    }
}

void minStackPop(MinStack* obj) {
    if (obj->stack[obj->top] == obj->minStack[obj->minTop]) {
        obj->minTop--;
    }
    obj->top--;
}

int minStackTop(MinStack* obj) {
    return obj->stack[obj->top];
}

int minStackGetMin(MinStack* obj) {
    return obj->minStack[obj->minTop];
}

void minStackFree(MinStack* obj) {
    free(obj);
}

int main() {
    MinStack* minStack = minStackCreate();

    int n, choice, val;

    printf("Enter number of operations: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("\nEnter operation (1=push, 2=pop, 3=top, 4=getMin): ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter value to push: ");
            scanf("%d", &val);
            minStackPush(minStack, val);
            printf("Pushed: %d\n", val);
        }
        else if (choice == 2) {
            minStackPop(minStack);
            printf("Popped top element\n");
        }
        else if (choice == 3) {
            printf("Top element: %d\n", minStackTop(minStack));
        }
        else if (choice == 4) {
            printf("Minimum element: %d\n", minStackGetMin(minStack));
        }
    }

    minStackFree(minStack);
    return 0;
}