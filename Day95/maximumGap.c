//Given an integer array nums, return the maximum difference between two successive elements in its sorted form. If the array contains less than two elements, return 0.

#include <stdio.h>
#include <stdlib.h>

int maximumGap(int* nums, int numsSize)
{
    if (numsSize < 2)
    {
        return 0;
    }

    int min = nums[0], max = nums[0];

    for (int i = 1; i < numsSize; i++)
    {
        if (nums[i] < min) min = nums[i];
        if (nums[i] > max) max = nums[i];
    }

    if (min == max)
    {
        return 0;
    }

    int n           = numsSize;
    int bucketSize  = (max - min + n - 2) / (n - 1);
    int bucketCount = (max - min) / bucketSize + 1;

    int *bMin = (int*)malloc(bucketCount * sizeof(int));
    int *bMax = (int*)malloc(bucketCount * sizeof(int));
    int *used = (int*)calloc(bucketCount, sizeof(int));

    for (int i = 0; i < bucketCount; i++)
    {
        bMin[i] =  1000000001;
        bMax[i] = -1;
    }

    for (int i = 0; i < n; i++)
    {
        int idx = (nums[i] - min) / bucketSize;

        if (nums[i] < bMin[idx]) bMin[idx] = nums[i];
        if (nums[i] > bMax[idx]) bMax[idx] = nums[i];

        used[idx] = 1;
    }

    int maxGap  = 0;
    int prevMax = min;

    for (int i = 0; i < bucketCount; i++)
    {
        if (!used[i])
        {
            continue;
        }

        if (bMin[i] - prevMax > maxGap)
        {
            maxGap = bMin[i] - prevMax;
        }

        prevMax = bMax[i];
    }

    free(bMin);
    free(bMax);
    free(used);

    return maxGap;
}

int main()
{
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int nums[n];

    printf("Enter elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &nums[i]);
    }

    int result = maximumGap(nums, n);

    printf("Maximum gap: %d\n", result);

    return 0;
}