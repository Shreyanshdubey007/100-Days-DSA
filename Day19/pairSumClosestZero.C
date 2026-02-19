//Problem: Given an array of integers, find two elements whose sum is closest to zero.

#include <stdio.h>
#include <stdlib.h>

int absVal(int x) {
    return x < 0 ? -x : x;
}

int main() {
    int n;
    printf("Enter nunber of elements in Array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements in Array: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int minSum = arr[0] + arr[1];
    int a = arr[0], b = arr[1];

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int sum = arr[i] + arr[j];
            if (absVal(sum) < absVal(minSum)) {
                minSum = sum;
                a = arr[i];
                b = arr[j];
            }
        }
    }

    printf("Pair whose sum will be closest to zero: %d %d\n", a, b);

    return 0;
}