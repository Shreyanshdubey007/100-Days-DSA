//Problem: Evaluate Postfix Expression - Implement using linked list with dynamic memory allocation.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

void push(int val) {
    struct Node* newNode = createNode(val);
    newNode->next = top;
    top = newNode;
    printf("Pushed: %d\n", val);
}

int pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
        return -1;
    }
    else {
        int val = top->data;
        struct Node* temp = top;
        top = top->next;
        free(temp);
        return val;
    }
}

int evaluatePostfix(char* expr) {
    char* token = strtok(expr, " ");

    while (token != NULL) {
        if (strcmp(token, "+") == 0 || strcmp(token, "-") == 0 ||
            strcmp(token, "*") == 0 || strcmp(token, "/") == 0) {
            int b = pop();
            int a = pop();

            if (strcmp(token, "+") == 0) {
                push(a + b);
            }
            else if (strcmp(token, "-") == 0) {
                push(a - b);
            }
            else if (strcmp(token, "*") == 0) {
                push(a * b);
            }
            else if (strcmp(token, "/") == 0) {
                push(a / b);
            }
        }
        else {
            push(atoi(token));
        }

        token = strtok(NULL, " ");
    }

    return pop();
}

int main() {
    char expr[1000];

    printf("Enter postfix expression: ");
    fgets(expr, sizeof(expr), stdin);

    expr[strcspn(expr, "\n")] = '\0';

    int result = evaluatePostfix(expr);

    printf("Result: %d\n", result);

    return 0;
}