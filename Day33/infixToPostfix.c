//Problem: Convert an infix expression to postfix notation using stack.

#include <stdio.h>
#include <string.h>
#define MAX 1000

char stack[MAX];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    if (top == -1) {
        return '\0';
    }
    else {
        return stack[top--];
    }
}

char peek() {
    if (top == -1) {
        return '\0';
    }
    else {
        return stack[top];
    }
}

int precedence(char c) {
    if (c == '*' || c == '/') {
        return 2;
    }
    else if (c == '+' || c == '-') {
        return 1;
    }
    else {
        return 0;
    }
}

int isOperator(char c) {
    if (c == '+' || c == '-' || c == '*' || c == '/') {
        return 1;
    }
    else {
        return 0;
    }
}

void infixToPostfix(char* expr) {
    int n = strlen(expr);
    char result[MAX];
    int k = 0;

    for (int i = 0; i < n; i++) {
        char c = expr[i];

        if (c == '(') {
            push(c);
        }
        else if (c == ')') {
            while (peek() != '(') {
                result[k++] = pop();
            }
            pop();
        }
        else if (isOperator(c)) {
            while (top != -1 && precedence(peek()) >= precedence(c)) {
                result[k++] = pop();
            }
            push(c);
        }
        else {
            result[k++] = c;
        }
    }

    while (top != -1) {
        result[k++] = pop();
    }
    result[k] = '\0';
    
    printf("Postfix expression: %s\n", result);
}

int main() {
    char expr[MAX];

    printf("Enter infix expression: ");
    scanf("%s", expr);

    infixToPostfix(expr);

    return 0;
}