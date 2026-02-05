/*You are given two integer arrays nums1 and nums2, sorted in non-decreasing order,
and two integers m and n, representing the number of elements in nums1 and nums2 respectively.
Merge nums1 and nums2 into a single array sorted in non-decreasing order.*/

#include <stdio.h>

void merge(int* nums1, int m, int* nums2, int n) {

    // i points to the last valid element in nums1
    int i = m - 1;

    // j points to the last element in nums2
    int j = n - 1;

    // k points to the last position of nums1 (including extra space)
    int k = m + n - 1;

    while (i >= 0 && j >= 0) {

        if (nums1[i] > nums2[j]) {
            nums1[k] = nums1[i];
            i--;    // move left in nums1
        } else {
            nums1[k] = nums2[j];
            j--;    // move left in nums2
        }
        k--;        // move left in nums1
    }

    // If nums2 still has elements left, copy them
    while (j >= 0) {
        nums1[k] = nums2[j];
        j--;
        k--;
    }
}

int main() {

    int m,n;

    printf("Enter number of terms in 1st Array: ");
    scanf("%d", &m);

    printf("Enter number of terms in 2nd Array: ");
    scanf("%d", &n);
    
    int nums1[m + n];
    int nums2[n];

    printf("Enter %d elements of 1st Array: ", m);
    for(int i = 0; i < m; i++)
        scanf("%d", &nums1[i]);

    printf("Enter %d elements of 2nd Array: ", n);
    for(int i = 0; i < n; i++)
        scanf("%d", &nums2[i]);

    merge(nums1, m, nums2, n);

    printf("Merged array: ");
    for (int i = 0; i < m + n; i++) {
        printf("%d ", nums1[i]);
    }
    printf("\n");

    return 0;
}