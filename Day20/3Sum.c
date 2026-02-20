//Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {

    *returnSize = 0;

    if (numsSize < 3) {
        *returnColumnSizes = NULL;
        return NULL;
    }

    qsort(nums, numsSize, sizeof(int), compare);

    int capacity = 16;

    int** result = (int**)malloc(capacity * sizeof(int*));
    *returnColumnSizes = (int*)malloc(capacity * sizeof(int));

    for (int i = 0; i < numsSize - 2; i++) {

        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        int left = i + 1;
        int right = numsSize - 1;

        while (left < right) {

            int sum = nums[i] + nums[left] + nums[right];

            if (sum == 0) {

                if (*returnSize >= capacity) {

                    capacity *= 2;

                    int** temp1 = realloc(result, capacity * sizeof(int*));
                    int* temp2 = realloc(*returnColumnSizes, capacity * sizeof(int));

                    if (temp1 == NULL || temp2 == NULL)
                        return result;

                    result = temp1;
                    *returnColumnSizes = temp2;
                }

                result[*returnSize] = (int*)malloc(3 * sizeof(int));

                result[*returnSize][0] = nums[i];
                result[*returnSize][1] = nums[left];
                result[*returnSize][2] = nums[right];

                (*returnColumnSizes)[*returnSize] = 3;
                (*returnSize)++;

                left++;
                right--;

                while (left < right && nums[left] == nums[left - 1])
                    left++;

                while (left < right && nums[right] == nums[right + 1])
                    right--;
            }
            else if (sum < 0) {
                left++;
            }
            else {
                right--;
            }
        }
    }

    return result;
}

int main() {

    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int* nums = (int*)malloc(n * sizeof(int));

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    int returnSize;
    int* returnColumnSizes;

    int** result = threeSum(nums, n, &returnSize, &returnColumnSizes);

    printf("\nTriplets with sum = 0:\n");

    if (returnSize == 0) {
        printf("No triplets found\n");
    } else {
        for (int i = 0; i < returnSize; i++) {
            printf("[");
            for (int j = 0; j < 3; j++) {
                printf("%d", result[i][j]);
                if (j < 2) printf(", ");
            }
            printf("]\n");
        }
    }

    for (int i = 0; i < returnSize; i++) {
        free(result[i]);
    }

    free(result);
    free(returnColumnSizes);
    free(nums);

    return 0;
}