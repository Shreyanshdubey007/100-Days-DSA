//Given two integer arrays nums1 and nums2, return an array of their intersection.
//Each element in the result must appear as many times as it shows in both arrays and you may return the result in any order.

#include <stdio.h>
#include <stdlib.h>

int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int freq[1001] = {0};

    for (int i = 0; i < nums1Size; i++) {
        freq[nums1[i]]++;
    }

    int maxSize = nums1Size < nums2Size ? nums1Size : nums2Size;
    int* result = (int*)malloc(maxSize * sizeof(int));
    int k = 0;

    for (int i = 0; i < nums2Size; i++) {
        if (freq[nums2[i]] > 0) {
            result[k++] = nums2[i];
            freq[nums2[i]]--;
        }
    }

    *returnSize = k;
    return result;
}

int main() {
    int nums1[] = {1, 2, 2, 1};
    int nums2[] = {2, 2};

    int nums1Size = sizeof(nums1) / sizeof(nums1[0]);
    int nums2Size = sizeof(nums2) / sizeof(nums2[0]);

    int returnSize;
    int* result = intersect(nums1, nums1Size, nums2, nums2Size, &returnSize);

    printf("Intersection: ");
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }

    free(result);
    return 0;
}