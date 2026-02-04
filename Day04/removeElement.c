/*
Problem:
Given an integer array nums and an integer val, remove all occurrences of val from the array in-place.
Rearrange the array such that the first k elements contain only the elements not equal to val.
The order of elements may change and no extra array should be used.
Return k, the number of elements remaining after removal.
Elements beyond the first k positions are not important.
*/

#include <stdio.h>

int removeElement(int* nums, int numsSize, int val) {
    
    int k = 0;
    
    for(int i = 0; i < numsSize; i++){
        if(val != nums[i]){
            nums[k] = nums[i];
            k += 1;
        }    
    }
    return k;
}

int main() {
    int nums[] = {3, 2, 2, 3};
    int val = 3;
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    int k = removeElement(nums, numsSize, val);

    printf("k = %d\n", k);
    printf("Updated array: ");

    for(int i = 0; i < k; i++){
        printf("%d ", nums[i]);
    }

    return 0;
}