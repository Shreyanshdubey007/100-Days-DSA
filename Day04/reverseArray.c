//Problem: Given an array of n integers, reverse the array in-place using two-pointer approach.

#include <stdio.h>

void reverseNumber(int *arr, int n);

int main() {

    int n;
    printf("Enter number of terms in array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements of Array: ", n);
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    reverseNumber(arr, n);

    printf("Reversed Array: ");
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }

    return 0;
}

void reverseNumber(int *arr, int n){

    int left = 0;       //Two-pointer approach
    int right = n - 1;
    int temp;

    while(left < right){
        temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;

        left++;
        right--;
    }
}