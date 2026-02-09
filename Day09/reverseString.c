//Write a function that reverses a string. The input string is given as an array of characters s.

#include <stdio.h>

void reverseString(char* s, int sSize) {
    int left = 0;
    int right = sSize - 1;

    while (left < right) {
        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;

        left++;
        right--;
    }
}

int main() {
    char s[200];
    int size = 0;

    printf("Enter a string: ");
    fgets(s, sizeof(s), stdin);

    while (s[size] != '\0' && s[size] != '\n') {
        size++;
    }

    reverseString(s, size);

    printf("Reversed string: %s\n", s);

    return 0;
}