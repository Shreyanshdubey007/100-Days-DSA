//Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

#include <stdio.h>
#include <stdlib.h>

int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {
    int freq[20001] = {0};
    int unique[20001];
    int uniqueSize = 0;

    for (int i = 0; i < numsSize; i++) {
        freq[nums[i] + 10000]++;
    }

    for (int i = 0; i < 20001; i++) {
        if (freq[i] > 0) {
            unique[uniqueSize++] = i - 10000;
        }
    }

    for (int i = 0; i < uniqueSize - 1; i++) {
        for (int j = 0; j < uniqueSize - i - 1; j++) {
            if (freq[unique[j] + 10000] < freq[unique[j + 1] + 10000]) {
                int temp = unique[j];
                unique[j] = unique[j + 1];
                unique[j + 1] = temp;
            }
        }
    }

    int* result = (int*)malloc(k * sizeof(int));
    *returnSize = k;

    for (int i = 0; i < k; i++) {
        result[i] = unique[i];
    }

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

    printf("Enter k: ");
    scanf("%d", &k);

    int returnSize;
    int* result = topKFrequent(nums, n, k, &returnSize);

    printf("Top %d frequent elements: ", k);

    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }

    printf("\n");

    free(nums);
    free(result);

    return 0;
}