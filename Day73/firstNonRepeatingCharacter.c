//Problem Statement: Given a string s consisting of lowercase English letters, find and return the first character that does not
//repeat in the string. If all characters repeat, return '$'.

#include <stdio.h>
#include <string.h>

int main() {
    char s[1000];
    int freq[26] = {0};

    printf("Enter string: ");
    scanf("%s", s);

    // Step 1: count frequency
    for (int i = 0; s[i] != '\0'; i++) {
        freq[s[i] - 'a']++;
    }

    // Step 2: find first non-repeating character
    for (int i = 0; s[i] != '\0'; i++) {
        if (freq[s[i] - 'a'] == 1) {
            printf("%c\n", s[i]);
            return 0;
        }
    }

    // if none found
    printf("$\n");
    return 0;
}