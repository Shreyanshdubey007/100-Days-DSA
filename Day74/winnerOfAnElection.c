//Problem Statement: Given an array of candidate names where each name represents a vote cast for that candidate,
//determine the candidate who received the maximum number of votes. In case of a tie, return the lexicographically smallest candidate name.

#include <stdio.h>
#include <string.h>

#define MAX 1000

int main() {
    int n;
    char names[MAX][50];

    printf("Enter number of votes: ");
    scanf("%d", &n);

    printf("Enter names:\n");
    for (int i = 0; i < n; i++) {
        scanf("%s", names[i]);
    }

    int maxCount = 0;
    char winner[50];

    for (int i = 0; i < n; i++) {
        int count = 1;

        // count occurrences of names[i]
        for (int j = i + 1; j < n; j++) {
            if (strcmp(names[i], names[j]) == 0) {
                count++;
            }
        }

        if (count > maxCount) {
            maxCount = count;
            strcpy(winner, names[i]);
        }
        else if (count == maxCount) {
            // lexicographically smaller
            if (strcmp(names[i], winner) < 0) {
                strcpy(winner, names[i]);
            }
        }
    }

    printf("%s %d\n", winner, maxCount);

    return 0;
}