//Problem: Implement push and pop operations on a stack and verify stack operations.

#include <stdio.h>

#define MAX 1000

int stack[MAX];
int top = -1;

void push(int val) {
    stack[++top] = val;
    printf("Pushed: %d\n", val);
}

void pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
    } 
    else {
        printf("Popped: %d\n", stack[top--]);
    }
}

void display() {
    if (top == -1) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack (top to bottom): ");
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    int n, m, val;

    printf("Enter number of elements to push: ");
    scanf("%d", &n);

    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        push(val);
    }

    printf("Enter number of pops: ");
    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        pop();
    }

    display();

    return 0;
}