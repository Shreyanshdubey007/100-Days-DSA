//Design your implementation of the circular double-ended queue (deque).

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int* arr;
    int front;
    int rear;
    int size;
    int capacity;
} MyCircularDeque;

MyCircularDeque* myCircularDequeCreate(int k) {
    MyCircularDeque* obj = (MyCircularDeque*)malloc(sizeof(MyCircularDeque));
    obj->arr = (int*)malloc(k * sizeof(int));
    obj->front = 0;
    obj->rear = 0;
    obj->size = 0;
    obj->capacity = k;
    return obj;
}

bool myCircularDequeIsEmpty(MyCircularDeque* obj) {
    if (obj->size == 0) {
        return true;
    }
    else {
        return false;
    }
}

bool myCircularDequeIsFull(MyCircularDeque* obj) {
    if (obj->size == obj->capacity) {
        return true;
    }
    else {
        return false;
    }
}

bool myCircularDequeInsertFront(MyCircularDeque* obj, int value) {
    if (myCircularDequeIsFull(obj)) {
        return false;
    }

    obj->front = (obj->front - 1 + obj->capacity) % obj->capacity;
    obj->arr[obj->front] = value;
    obj->size++;
    return true;
}

bool myCircularDequeInsertLast(MyCircularDeque* obj, int value) {
    if (myCircularDequeIsFull(obj)) {
        return false;
    }

    obj->arr[obj->rear] = value;
    obj->rear = (obj->rear + 1) % obj->capacity;
    obj->size++;
    return true;
}

bool myCircularDequeDeleteFront(MyCircularDeque* obj) {
    if (myCircularDequeIsEmpty(obj)) {
        return false;
    }

    obj->front = (obj->front + 1) % obj->capacity;
    obj->size--;
    return true;
}

bool myCircularDequeDeleteLast(MyCircularDeque* obj) {
    if (myCircularDequeIsEmpty(obj)) {
        return false;
    }

    obj->rear = (obj->rear - 1 + obj->capacity) % obj->capacity;
    obj->size--;
    return true;
}

int myCircularDequeGetFront(MyCircularDeque* obj) {
    if (myCircularDequeIsEmpty(obj)) {
        return -1;
    }

    return obj->arr[obj->front];
}

int myCircularDequeGetRear(MyCircularDeque* obj) {
    if (myCircularDequeIsEmpty(obj)) {
        return -1;
    }

    return obj->arr[(obj->rear - 1 + obj->capacity) % obj->capacity];
}

void myCircularDequeFree(MyCircularDeque* obj) {
    free(obj->arr);
    free(obj);
}

int main() {
    int k, n, choice, val;

    printf("Enter deque capacity: ");
    scanf("%d", &k);

    MyCircularDeque* dq = myCircularDequeCreate(k);

    printf("Enter number of operations: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("\nEnter operation:\n");
        printf("1=insertFront  2=insertLast\n");
        printf("3=deleteFront  4=deleteLast\n");
        printf("5=getFront     6=getRear\n");
        printf("7=isEmpty      8=isFull\n");
        printf("Choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter value: ");
            scanf("%d", &val);
            if (myCircularDequeInsertFront(dq, val)) {
                printf("Inserted %d at front: true\n", val);
            }
            else {
                printf("Insert front failed: false\n");
            }
        }
        else if (choice == 2) {
            printf("Enter value: ");
            scanf("%d", &val);
            if (myCircularDequeInsertLast(dq, val)) {
                printf("Inserted %d at rear: true\n", val);
            }
            else {
                printf("Insert last failed: false\n");
            }
        }
        else if (choice == 3) {
            if (myCircularDequeDeleteFront(dq)) {
                printf("Deleted from front: true\n");
            }
            else {
                printf("Delete front failed: false\n");
            }
        }
        else if (choice == 4) {
            if (myCircularDequeDeleteLast(dq)) {
                printf("Deleted from rear: true\n");
            }
            else {
                printf("Delete last failed: false\n");
            }
        }
        else if (choice == 5) {
            printf("Front element: %d\n", myCircularDequeGetFront(dq));
        }
        else if (choice == 6) {
            printf("Rear element: %d\n", myCircularDequeGetRear(dq));
        }
        else if (choice == 7) {
            if (myCircularDequeIsEmpty(dq)) {
                printf("Is empty: true\n");
            }
            else {
                printf("Is empty: false\n");
            }
        }
        else if (choice == 8) {
            if (myCircularDequeIsFull(dq)) {
                printf("Is full: true\n");
            }
            else {
                printf("Is full: false\n");
            }
        }
    }

    myCircularDequeFree(dq);

    return 0;
}