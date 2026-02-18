//Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

#include <stdio.h>
#include <stdlib.h>

int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;

    int* answer = (int*)malloc(numsSize * sizeof(int));

    answer[0] = 1;
    for (int i = 1; i < numsSize; i++) {
        answer[i] = answer[i - 1] * nums[i - 1];
    }

    int rightProduct = 1;
    for (int i = numsSize - 1; i >= 0; i--) {
        answer[i] = answer[i] * rightProduct;
        rightProduct *= nums[i];
    }

    return answer;
}

int main() {
    int n;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int* nums = (int*)malloc(n * sizeof(int));

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    int returnSize;
    int* result = productExceptSelf(nums, n, &returnSize);

    printf("Product Except Self array:\n");
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }

    free(nums);
    free(result);

    return 0;
}