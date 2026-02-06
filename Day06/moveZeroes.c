//Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

#include <stdio.h>

void moveZeroes(int* arr, int n) {
    int k = 0;

    if(n == 0)
        return;

    for(int i = 0; i < n; i++){
        if(arr[i] != 0){
            arr[k] = arr[i];
            k++;
        }
    }

    while(k < n){
        arr[k++] = 0;
    }
}

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter array elements: ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    moveZeroes(arr, n);

    printf("Array after moving zeroes: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}