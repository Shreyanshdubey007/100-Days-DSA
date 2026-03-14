//The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value, and the median is the mean of the two middle values.

#include <stdio.h>
#include <stdlib.h>
#define MAX 50001

typedef struct {
    int maxHeap[MAX];
    int maxSize;
    int minHeap[MAX];
    int minSize;
} MedianFinder;

void maxHeapifyUp(int* heap, int i) {
    while (i > 0) {
        int parent = (i - 1) / 2;

        if (heap[parent] < heap[i]) {
            int temp = heap[parent];
            heap[parent] = heap[i];
            heap[i] = temp;
            i = parent;
        }
        else {
            break;
        }
    }
}

void maxHeapifyDown(int* heap, int size, int i) {
    while (i < size) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int largest = i;

        if (left < size && heap[left] > heap[largest]) {
            largest = left;
        }

        if (right < size && heap[right] > heap[largest]) {
            largest = right;
        }

        if (largest != i) {
            int temp = heap[largest];
            heap[largest] = heap[i];
            heap[i] = temp;
            i = largest;
        }
        else {
            break;
        }
    }
}

void minHeapifyUp(int* heap, int i) {
    while (i > 0) {
        int parent = (i - 1) / 2;

        if (heap[parent] > heap[i]) {
            int temp = heap[parent];
            heap[parent] = heap[i];
            heap[i] = temp;
            i = parent;
        }
        else {
            break;
        }
    }
}

void minHeapifyDown(int* heap, int size, int i) {
    while (i < size) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;

        if (left < size && heap[left] < heap[smallest]) {
            smallest = left;
        }

        if (right < size && heap[right] < heap[smallest]) {
            smallest = right;
        }

        if (smallest != i) {
            int temp = heap[smallest];
            heap[smallest] = heap[i];
            heap[i] = temp;
            i = smallest;
        }
        else {
            break;
        }
    }
}

MedianFinder* medianFinderCreate() {
    MedianFinder* obj = (MedianFinder*)malloc(sizeof(MedianFinder));
    obj->maxSize = 0;
    obj->minSize = 0;
    return obj;
}

void medianFinderAddNum(MedianFinder* obj, int num) {
    obj->maxHeap[obj->maxSize++] = num;
    maxHeapifyUp(obj->maxHeap, obj->maxSize - 1);

    obj->minHeap[obj->minSize++] = obj->maxHeap[0];
    obj->maxHeap[0] = obj->maxHeap[--obj->maxSize];
    maxHeapifyDown(obj->maxHeap, obj->maxSize, 0);
    minHeapifyUp(obj->minHeap, obj->minSize - 1);

    if (obj->minSize > obj->maxSize) {
        obj->maxHeap[obj->maxSize++] = obj->minHeap[0];
        obj->minHeap[0] = obj->minHeap[--obj->minSize];
        maxHeapifyUp(obj->maxHeap, obj->maxSize - 1);
        minHeapifyDown(obj->minHeap, obj->minSize, 0);
    }
}

double medianFinderFindMedian(MedianFinder* obj) {
    if (obj->maxSize > obj->minSize) {
        return (double)obj->maxHeap[0];
    }
    else {
        return (obj->maxHeap[0] + obj->minHeap[0]) / 2.0;
    }
}

void medianFinderFree(MedianFinder* obj) {
    free(obj);
}

int main() {
    MedianFinder* obj = medianFinderCreate();

    int n, choice, num;

    printf("Enter number of operations: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("\nEnter operation (1=addNum, 2=findMedian): ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter number to add: ");
            scanf("%d", &num);
            medianFinderAddNum(obj, num);
            printf("Added: %d\n", num);
        }
        else if (choice == 2) {
            printf("Median: %.1f\n", medianFinderFindMedian(obj));
        }
    }

    medianFinderFree(obj);

    return 0;
}