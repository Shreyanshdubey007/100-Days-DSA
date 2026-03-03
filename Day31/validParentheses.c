//Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isValid(char* s) {
    int n = strlen(s);
    char stack[n];
    int top = -1;

    for (int i = 0; i < n; i++) {
        char c = s[i];
        if (c == '(' || c == '{' || c == '[') {
            stack[++top] = c;
        } else {
            if (top == -1) return false;
            char t = stack[top--];
            if (c == ')' && t != '(') return false;
            if (c == '}' && t != '{') return false;
            if (c == ']' && t != '[') return false;
        }
    }
    return top == -1;
}

int main() {
    char s[10001];
    printf("Enter the string: ");
    scanf("%s", s);

    if (isValid(s))
        printf("Output: true\n");
    else
        printf("Output: false\n");

    return 0;
}