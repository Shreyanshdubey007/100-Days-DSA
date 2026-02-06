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

    if(n == 0)
        return 0;

    for(int i = 1; i < n; i++){
        if(arr[i] != arr[i - 1]){
            arr[k] = arr[i];
            k++;
        }
    }

    printf("Array: ");
    for(int i = 0; i < k; i++){
        printf("%d ", arr[i]);
    }

    return 0;
}