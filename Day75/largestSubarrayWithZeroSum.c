//Problem Statement: Given an array of integers containing both positive and negative values, find the length of the longest contiguous subarray whose sum is equal to zero.

#include <stdio.h>
#define MAX 1000

int main() {
    int n;
    int arr[MAX];

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int sum = 0, maxLen = 0;

    // to store prefix sums and their first index
    int prefixSum[MAX];
    int index[MAX];

    int size = 0; // number of stored sums

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        // case 1: sum becomes 0
        if (sum == 0) {
            maxLen = i + 1;
        }

        // check if sum already exists
        int found = 0;
        for (int j = 0; j < size; j++) {
            if (prefixSum[j] == sum) {
                int len = i - index[j];
                if (len > maxLen)
                    maxLen = len;
                found = 1;
                break;
            }
        }

        // store sum if not found
        if (!found) {
            prefixSum[size] = sum;
            index[size] = i;
            size++;
        }
    }

    printf("Length: %d\n", maxLen);

    return 0;
}