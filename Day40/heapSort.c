//Implement Heap Sort using a Max Heap to sort an array in ascending order.
//First build a max heap, then repeatedly extract the maximum element and place it at the end of the array.

#include <stdio.h>

#define MAX 1000

void heapifyDown(int* arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        int temp = arr[largest];
        arr[largest] = arr[i];
        arr[i] = temp;
        heapifyDown(arr, n, largest);
    }
}

void buildMaxHeap(int* arr, int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapifyDown(arr, n, i);
    }
}

void heapSort(int* arr, int n) {
    buildMaxHeap(arr, n);

    for (int i = n - 1; i > 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapifyDown(arr, i, 0);
    }
}

void display(int* arr, int n) {
    printf("Array: ");

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[MAX];

    printf("Enter %d elements: ", n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Before sorting -> ");
    display(arr, n);

    heapSort(arr, n);

    printf("After sorting  -> ");
    display(arr, n);

    return 0;
}