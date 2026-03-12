//Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i]
//is the number of days you have to wait after the ith day to get a warmer temperature.
//If there is no future day for which this is possible, keep answer[i] == 0 instead.

#include <stdio.h>
#include <stdlib.h>

#include <string.h>

int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize) {
    *returnSize = temperaturesSize;
    int* result = (int*)calloc(temperaturesSize, sizeof(int));
    int* stack = (int*)malloc(temperaturesSize * sizeof(int));
    int top = -1;

    for (int i = 0; i < temperaturesSize; i++) {
        while (top != -1 && temperatures[stack[top]] < temperatures[i]) {
            int idx = stack[top--];
            result[idx] = i - idx;
        }

        stack[++top] = i;
    }

    free(stack);
    return result;
}

int main() {
    int n;

    printf("Enter number of days: ");
    scanf("%d", &n);

    int* temperatures = (int*)malloc(n * sizeof(int));

    printf("Enter %d temperatures: ", n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &temperatures[i]);
    }

    int returnSize;
    int* result = dailyTemperatures(temperatures, n, &returnSize);

    printf("Output: ");

    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }

    printf("\n");

    free(temperatures);
    free(result);

    return 0;
}