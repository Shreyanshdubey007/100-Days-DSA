//You are part of a university admissions office and need to keep track of the kth highest test score from applicants in real-time. This helps to determine cut-off marks for interviews and admissions dynamically as new applicants submit their scores.

#include <stdio.h>

#include <stdlib.h>

typedef struct {
    int* minHeap;
    int size;
    int k;
} KthLargest;

void heapifyUp(int* heap, int i) {
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

void heapifyDown(int* heap, int size, int i) {
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

KthLargest* kthLargestCreate(int k, int* nums, int numsSize) {
    KthLargest* obj = (KthLargest*)malloc(sizeof(KthLargest));
    obj->minHeap = (int*)malloc((k + 1) * sizeof(int));
    obj->size = 0;
    obj->k = k;

    for (int i = 0; i < numsSize; i++) {
        if (obj->size < k) {
            obj->minHeap[obj->size++] = nums[i];
            heapifyUp(obj->minHeap, obj->size - 1);
        }
        else if (nums[i] > obj->minHeap[0]) {
            obj->minHeap[0] = nums[i];
            heapifyDown(obj->minHeap, obj->size, 0);
        }
    }

    return obj;
}

int kthLargestAdd(KthLargest* obj, int val) {
    if (obj->size < k) {
        obj->minHeap[obj->size++] = val;
        heapifyUp(obj->minHeap, obj->size - 1);
    }
    else if (val > obj->minHeap[0]) {
        obj->minHeap[0] = val;
        heapifyDown(obj->minHeap, obj->size, 0);
    }

    return obj->minHeap[0];
}

void kthLargestFree(KthLargest* obj) {
    free(obj->minHeap);
    free(obj);
}

int main() {
    int k, n;

    printf("Enter k: ");
    scanf("%d", &k);

    printf("Enter number of initial elements: ");
    scanf("%d", &n);

    int* nums = (int*)malloc(n * sizeof(int));

    printf("Enter %d elements: ", n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    KthLargest* obj = kthLargestCreate(k, nums, n);

    int q, val;

    printf("Enter number of add operations: ");
    scanf("%d", &q);

    for (int i = 0; i < q; i++) {
        printf("Enter value to add: ");
        scanf("%d", &val);
        printf("Kth largest: %d\n", kthLargestAdd(obj, val));
    }

    kthLargestFree(obj);
    free(nums);

    return 0;
}