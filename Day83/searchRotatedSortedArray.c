//Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

#include <stdio.h>

int search(int* nums, int numsSize, int target)
{
    int lo = 0;
    int hi = numsSize - 1;

    while (lo <= hi)
    {
        int mid = lo + (hi - lo) / 2;

        if (nums[mid] == target)
        {
            return mid;
        }

        if (nums[lo] <= nums[mid])
        {
            if (nums[lo] <= target && target < nums[mid])
            {
                hi = mid - 1;
            }
            else
            {
                lo = mid + 1;
            }
        }
        else
        {
            if (nums[mid] < target && target <= nums[hi])
            {
                lo = mid + 1;
            }
            else
            {
                hi = mid - 1;
            }
        }
    }

    return -1;
}

int main()
{
    int n, target;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int nums[n];

    printf("Enter rotated sorted array:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &nums[i]);
    }

    printf("Enter target: ");
    scanf("%d", &target);

    int result = search(nums, n, target);

    printf("Index of target: %d\n", result);

    return 0;
}