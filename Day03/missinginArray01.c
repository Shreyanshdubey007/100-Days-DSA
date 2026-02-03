//You are given an array arr[] of size n - 1 that contains distinct integers in the range from 1 to n (inclusive).
//This array represents a permutation of the integers from 1 to n with one element missing.
//Your task is to identify and return the missing element.

//1-Based position

#include <stdio.h>

int missingNum(int *arr, int size) {
    long long expectedSum, actualSum = 0;

    // Numbers should be from 1 to size+1
    expectedSum = (long long)(size + 1) * (size + 2) / 2;

    for (int i = 0; i < size; i++) {
        actualSum += arr[i];
    }

    return (int)(expectedSum - actualSum);
}

int main() {

    int arr[] = {1, 2, 3, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    int missing = missingNum(arr, size);

    printf("Missing number is: %d\n", missing);

    return 0;
}