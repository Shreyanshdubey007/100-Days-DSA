//Problem: Write a C program to delete the element at a given 1-based position pos from an array of n integers.
//Shift remaining elements to the left.

#include <stdio.h>

int main() {
    int n, pos;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements of Array: ", n);
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    printf("Enter position to delete Element: "); //1-based position (start from 1, 2, 3...)
    scanf("%d", &pos);

    for(int i = pos - 1; i < n - 1; i++){ //Deleting means shifting elements to the left
        arr[i] = arr[i + 1];
    }

    printf("Updated Array: "); //Array displayed after removing the element
    for(int i = 0; i < n - 1; i++){
        printf("%d ", arr[i]);
    }

    return 0;
}