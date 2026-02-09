//Problem: A secret system stores code names in forward order. To display them in mirror format,
//you must transform the given code name so that its characters appear in the opposite order.

#include <stdio.h>

int main() {
    char s[100];
    int i;

    printf("Enter string (no spaces): ");
    scanf("%s", &s);

    for(i = 0; s[i] != '\0'; i++);

    for(i = i - 1; i >= 0; i--){
        printf("%c", s[i]);
    }

    return 0;
}