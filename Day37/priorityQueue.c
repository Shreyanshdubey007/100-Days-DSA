//Problem Statement: Implement a Priority Queue using an array. An element with smaller value has higher priority.

#include <stdio.h>

#define MAX 1000

int pq[MAX];
int size = 0;

void insert(int val) {
    pq[size++] = val;
    printf("Inserted: %d\n", val);
}

void deleteMin() {
    if (size == 0) {
        printf("-1\n");
        return;
    }

    int minIdx = 0;

    for (int i = 1; i < size; i++) {
        if (pq[i] < pq[minIdx]) {
            minIdx = i;
        }
    }

    printf("Deleted: %d\n", pq[minIdx]);

    for (int i = minIdx; i < size - 1; i++) {
        pq[i] = pq[i + 1];
    }

    size--;
}

void peek() {
    if (size == 0) {
        printf("-1\n");
        return;
    }

    int minIdx = 0;

    for (int i = 1; i < size; i++) {
        if (pq[i] < pq[minIdx]) {
            minIdx = i;
        }
    }

    printf("Peek: %d\n", pq[minIdx]);
}

int main() {
    int n;
    char op[10];
    int val;

    printf("Enter number of operations: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter operation: ");
        scanf("%s", op);

        if (op[0] == 'i') {
            scanf("%d", &val);
            insert(val);
        }
        else if (op[0] == 'd') {
            deleteMin();
        }
        else if (op[0] == 'p') {
            peek();
        }
    }

    return 0;
}