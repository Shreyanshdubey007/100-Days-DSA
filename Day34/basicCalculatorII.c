//Given a string s which represents an expression, evaluate this expression and return its value. 

#include <stdio.h>
#include <stdlib.h>

#include <string.h>

int calculate(char* s) {
    int n = strlen(s);
    int stack[n];
    int top = -1;
    int num = 0;
    char op = '+';

    for (int i = 0; i < n; i++) {
        char c = s[i];

        if (c >= '0' && c <= '9') {
            num = num * 10 + (c - '0');
        }

        if ((c == '+' || c == '-' || c == '*' || c == '/') || i == n - 1) {
            if (op == '+') {
                stack[++top] = num;
            }
            else if (op == '-') {
                stack[++top] = -num;
            }
            else if (op == '*') {
                stack[top] = stack[top] * num;
            }
            else if (op == '/') {
                stack[top] = stack[top] / num;
            }

            op = c;
            num = 0;
        }
    }

    int result = 0;

    while (top >= 0) {
        result += stack[top--];
    }

    return result;
}

int main() {
    char s[300001];

    printf("Enter the expression: ");
    fgets(s, sizeof(s), stdin);

    s[strcspn(s, "\n")] = '\0';

    int result = calculate(s);

    printf("Output: %d\n", result);

    return 0;
}