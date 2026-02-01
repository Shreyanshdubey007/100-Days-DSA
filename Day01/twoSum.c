//Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
//You may assume that each input would have exactly one solution, and you may not use the same element twice.

#include <stdio.h>
#include <stdlib.h>

// Your original twoSum function
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int* result = malloc(2 * sizeof(int));

    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                result[0] = i;
                result[1] = j;
                *returnSize = 2;
                return result;
            }
        }
    }
    
    *returnSize = 0;
    free(result);
    return NULL;
}

// Main function to test twoSum
int main() {
    int nums[] = {2, 7, 11, 15};   // Example array
    int target = 9;                 // Example target
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int returnSize;

    // Call twoSum
    int* indices = twoSum(nums, numsSize, target, &returnSize);

    // Print the result
    if (indices != NULL) {
        printf("Indices: [%d, %d]\n", indices[0], indices[1]);
        free(indices); // Free allocated memory
    } else {
        printf("No solution found.\n");
    }

    return 0;
}
