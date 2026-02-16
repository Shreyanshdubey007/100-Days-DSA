//Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.

#include <stdio.h>

// function to reverse array
void reverse(int arr[], int start, int end)
{
    while(start < end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        start++;
        end--;
    }
}

int main()
{
    int n, k;

    scanf("%d", &n);

    int nums[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &nums[i]);

    scanf("%d", &k);

    // important when k > n
    k = k % n;

    // step 1: reverse whole array
    reverse(nums, 0, n-1);

    // step 2: reverse first k elements
    reverse(nums, 0, k-1);

    // step 3: reverse remaining elements
    reverse(nums, k, n-1);

    // print result
    for(int i = 0; i < n; i++)
        printf("%d ", nums[i]);

    return 0;
}