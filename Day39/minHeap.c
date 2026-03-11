//Problem Statement: Implement a Min Heap using an array where the smallest element is always at the root.

#include <stdio.h>
#define MAX 1000

int heap[MAX];
int size = 0;

void heapifyUp(int i) {
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

void heapifyDown(int i) {
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

void insert(int val) {
    heap[size++] = val;
    heapifyUp(size - 1);
    printf("Inserted: %d\n", val);
}

void extractMin() {
    if (size == 0) {
        printf("-1\n");
        return;
    }

    printf("ExtractMin: %d\n", heap[0]);
    heap[0] = heap[--size];
    heapifyDown(0);
}

void peek() {
    if (size == 0) {
        printf("-1\n");
        return;
    }

    printf("Peek: %d\n", heap[0]);
}

int main() {
    int n, val;
    char op[20];

    printf("Enter number of operations: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter operation: ");
        scanf("%s", op);

        if (op[0] == 'i') {
            scanf("%d", &val);
            insert(val);
        }
        else if (op[0] == 'e') {
            extractMin();
        }
        else if (op[0] == 'p') {
            peek();
        }
    }

    return 0;
}