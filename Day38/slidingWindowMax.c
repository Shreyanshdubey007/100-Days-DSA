//You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right.
//You can only see the k numbers in the window. Each time the sliding window moves right by one position.


#include <stdio.h>

#include <stdlib.h>

int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize) {
    *returnSize = numsSize - k + 1;
    int* result = (int*)malloc(*returnSize * sizeof(int));
    int* deque = (int*)malloc(numsSize * sizeof(int));
    int front = 0;
    int rear = -1;
    int ri = 0;

    for (int i = 0; i < numsSize; i++) {
        if (front <= rear && deque[front] < i - k + 1) {
            front++;
        }

        while (front <= rear && nums[deque[rear]] <= nums[i]) {
            rear--;
        }

        deque[++rear] = i;

        if (i >= k - 1) {
            result[ri++] = nums[deque[front]];
        }
    }

    free(deque);
    return result;
}

int main() {
    int n, k;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int* nums = (int*)malloc(n * sizeof(int));

    printf("Enter %d elements: ", n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    printf("Enter window size k: ");
    scanf("%d", &k);

    int returnSize;
    int* result = maxSlidingWindow(nums, n, k, &returnSize);

    printf("Max sliding window: ");

    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }

    printf("\n");

    free(nums);
    free(result);

    return 0;
}