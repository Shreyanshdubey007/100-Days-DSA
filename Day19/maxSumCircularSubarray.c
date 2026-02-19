//Given a circular integer array nums of length n, return the maximum possible sum of a non-empty subarray of nums.

#include <stdio.h>

int maxSubarraySumCircular(int* nums, int numsSize) {
    int totalSum = 0;

    int maxSum = nums[0];
    int currMax = 0;

    int minSum = nums[0];
    int currMin = 0;

    for (int i = 0; i < numsSize; i++) {
        totalSum += nums[i];

        currMax = (currMax > 0) ? currMax + nums[i] : nums[i];
        if (currMax > maxSum)
            maxSum = currMax;

        currMin = (currMin < 0) ? currMin + nums[i] : nums[i];
        if (currMin < minSum)
            minSum = currMin;
    }

    if (maxSum < 0)
        return maxSum;

    int circularMax = totalSum - minSum;
    return (maxSum > circularMax) ? maxSum : circularMax;
}

int main() {
    int n;
    printf("Enter nunber of elements in Array: ");
    scanf("%d", &n);

    int nums[n];

    printf("Enter %d elements in Array: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    int result = maxSubarraySumCircular(nums, n);
    printf("%d\n", result);

    return 0;
}