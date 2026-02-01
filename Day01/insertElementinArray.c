//Problem: Write a C program to insert an element x at a given 1-based position pos in an array of n integers.
//Shift existing elements to the right to make space.

#include <stdio.h>

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[1000];
    printf("Enter %d elements of array: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int pos, x;
    printf("Enter position to insert element: ");
    scanf("%d", &pos);
    printf("Enter element to insert: ");
    scanf("%d", &x);

    for (int i = n; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }

    arr[pos - 1] = x;

    printf("Array: ");
    for (int i = 0; i <= n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}