//Problem: Implement a stack data structure using an array with the following operations: push, pop, and display.

#include <stdio.h>

#define MAX 1000

int stack[MAX];
int top = -1;

void push(int val) {
    stack[++top] = val;
    printf("Pushed: %d\n", val);
}

void pop() {
    if (top == -1)
        printf("Stack Underflow\n");
    else
        printf("Popped: %d\n", stack[top--]);
}

void display() {
    if (top == -1) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack (top to bottom): ");
    for (int i = top; i >= 0; i--)
        printf("%d ", stack[i]);
    printf("\n");
}

int main() {
    int n, op, val;
    printf("Enter number of operations: ");
    scanf("%d", &n);
    
    while (n--) {
        printf("Enter operation (1=push, 2=pop, 3=display): ");
        scanf("%d", &op);
        if (op == 1) {
            printf("Enter value to push: ");
            scanf("%d", &val);
            push(val);
        } else if (op == 2) {
            pop();
        } else if (op == 3) {
            display();
        }
    }
    return 0;
}