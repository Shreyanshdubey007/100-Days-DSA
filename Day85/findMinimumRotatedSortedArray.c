//Given the sorted rotated array nums of unique elements, return the minimum element of this array.

#include <stdio.h>

int findMin(int* nums, int numsSize)
{
    int lo = 0;
    int hi = numsSize - 1;

    while (lo < hi)
    {
        int mid = lo + (hi - lo) / 2;

        if (nums[mid] > nums[hi])
        {
            lo = mid + 1;
        }
        else
        {
            hi = mid;
        }
    }

    return nums[lo];
}

int main()
{
    int n;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int nums[n];

    printf("Enter rotated sorted array: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &nums[i]);
    }

    int result = findMin(nums, n);

    printf("Minimum element: %d\n", result);

    return 0;
}