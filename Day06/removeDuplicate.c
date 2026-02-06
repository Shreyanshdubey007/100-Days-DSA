//Problem: Given a sorted array of n integers, remove duplicates in-place. Print only unique elements in order.

#include <stdio.h>

int main() {

    int n, k = 1;  // Index for unique elements

    printf("Enter number of terms: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d terms of Array: ", n);
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    if(n == 0)  // If elements are entered 0, program ends.
        return 0;

    for(int i = 1; i < n; i++){
        if(arr[i] != arr[i - 1]){  // Checks current element to previous
            arr[k] = arr[i];  // Assigns current value to value at arr[k]
            k++;
        }
    }

    printf("Array: ");  // Prints array after removing all duplicates
    for(int i = 0; i < k; i++){
        printf("%d ", arr[i]);
    }

    return 0;
}