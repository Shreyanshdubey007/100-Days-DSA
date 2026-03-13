//Task Scheduler

#include <stdio.h>

#include <stdlib.h>

int leastInterval(char* tasks, int tasksSize, int n) {
    int freq[26] = {0};

    for (int i = 0; i < tasksSize; i++) {
        freq[tasks[i] - 'A']++;
    }

    int maxFreq = 0;

    for (int i = 0; i < 26; i++) {
        if (freq[i] > maxFreq) {
            maxFreq = freq[i];
        }
    }

    int maxCount = 0;

    for (int i = 0; i < 26; i++) {
        if (freq[i] == maxFreq) {
            maxCount++;
        }
    }

    int slots = (maxFreq - 1) * (n + 1) + maxCount;

    if (slots > tasksSize) {
        return slots;
    }
    else {
        return tasksSize;
    }
}

int main() {
    int tasksSize, n;

    printf("Enter number of tasks: ");
    scanf("%d", &tasksSize);

    char* tasks = (char*)malloc(tasksSize * sizeof(char));

    printf("Enter %d tasks (space separated): ", tasksSize);

    for (int i = 0; i < tasksSize; i++) {
        scanf(" %c", &tasks[i]);
    }

    printf("Enter cooling interval n: ");
    scanf("%d", &n);

    int result = leastInterval(tasks, tasksSize, n);

    printf("Minimum CPU intervals required: %d\n", result);

    free(tasks);

    return 0;
}