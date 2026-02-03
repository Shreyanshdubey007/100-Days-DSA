//Given an array nums containing n distinct numbers in the range [0, n].
//Return the only number in the range that is missing from the array.

//0-Based position

#include <stdio.h>

int missingNumber(int* arr, int numsSize) {
    long long expectedSum = (long long)numsSize * (numsSize + 1) / 2;
    long long actualSum = 0;

    for(int i = 0; i < numsSize; i++) {
        actualSum += arr[i];
    }

    return (int)(expectedSum - actualSum);
}

int main() {

    int arr[] = {9,6,4,2,3,5,7,0,1};
    int numsSize = sizeof(arr) / sizeof(arr[0]);

    int missing = missingNumber(arr, numsSize);

    printf("Missing number is: %d\n", missing);

    return 0;
}