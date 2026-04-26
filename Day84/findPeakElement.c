//Given a 0-indexed integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.

#include <stdio.h>

int findPeakElement(int* nums, int numsSize)
{
    int lo = 0;
    int hi = numsSize - 1;

    while (lo < hi)
    {
        int mid = lo + (hi - lo) / 2;

        if (nums[mid] < nums[mid + 1])
        {
            lo = mid + 1;
        }
        else
        {
            hi = mid;
        }
    }

    return lo;
}

int main()
{
    int n;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int nums[n];

    printf("Enter elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &nums[i]);
    }

    int result = findPeakElement(nums, n);

    printf("Peak element index: %d (value: %d)\n", result, nums[result]);

    return 0;
}