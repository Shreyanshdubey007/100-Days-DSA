//Problem: You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10001

int evalRPN(char** tokens, int tokensSize) {
    int stack[tokensSize];
    int top = -1;

    for (int i = 0; i < tokensSize; i++) {
        char* t = tokens[i];

        if (strcmp(t, "+") == 0 || strcmp(t, "-") == 0 ||
            strcmp(t, "*") == 0 || strcmp(t, "/") == 0) {
            int b = stack[top--];
            int a = stack[top--];

            if (strcmp(t, "+") == 0) {
                stack[++top] = a + b;
            }
            else if (strcmp(t, "-") == 0) {
                stack[++top] = a - b;
            }
            else if (strcmp(t, "*") == 0) {
                stack[++top] = a * b;
            }
            else if (strcmp(t, "/") == 0) {
                stack[++top] = a / b;
            }
        }
        else {
            stack[++top] = atoi(t);
        }
    }

    return stack[top];
}

int main() {
    int n;

    printf("Enter number of tokens: ");
    scanf("%d", &n);

    char** tokens = (char**)malloc(n * sizeof(char*));

    for (int i = 0; i < n; i++) {
        tokens[i] = (char*)malloc(10 * sizeof(char));
        printf("Enter token %d: ", i + 1);
        scanf("%s", tokens[i]);
    }

    int result = evalRPN(tokens, n);
    printf("Output: %d\n", result);

    for (int i = 0; i < n; i++) {
        free(tokens[i]);
    }
    free(tokens);

    return 0;
}