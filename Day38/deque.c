//Problem: Deque (Double-Ended Queue)

#include <stdio.h>

#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* frontNode = NULL;
struct Node* rearNode = NULL;
int dequeSize = 0;

struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void push_front(int val) {
    struct Node* newNode = createNode(val);

    if (frontNode == NULL) {
        frontNode = newNode;
        rearNode = newNode;
    }
    else {
        newNode->next = frontNode;
        frontNode->prev = newNode;
        frontNode = newNode;
    }

    dequeSize++;
    printf("push_front: %d\n", val);
}

void push_back(int val) {
    struct Node* newNode = createNode(val);

    if (rearNode == NULL) {
        frontNode = newNode;
        rearNode = newNode;
    }
    else {
        newNode->prev = rearNode;
        rearNode->next = newNode;
        rearNode = newNode;
    }

    dequeSize++;
    printf("push_back: %d\n", val);
}

void pop_front() {
    if (frontNode == NULL) {
        printf("Deque is empty\n");
        return;
    }

    printf("pop_front: %d\n", frontNode->data);
    struct Node* temp = frontNode;
    frontNode = frontNode->next;

    if (frontNode != NULL) {
        frontNode->prev = NULL;
    }
    else {
        rearNode = NULL;
    }

    free(temp);
    dequeSize--;
}

void pop_back() {
    if (rearNode == NULL) {
        printf("Deque is empty\n");
        return;
    }

    printf("pop_back: %d\n", rearNode->data);
    struct Node* temp = rearNode;
    rearNode = rearNode->prev;

    if (rearNode != NULL) {
        rearNode->next = NULL;
    }
    else {
        frontNode = NULL;
    }

    free(temp);
    dequeSize--;
}

void front() {
    if (frontNode == NULL) {
        printf("Deque is empty\n");
        return;
    }

    printf("Front: %d\n", frontNode->data);
}

void back() {
    if (rearNode == NULL) {
        printf("Deque is empty\n");
        return;
    }

    printf("Back: %d\n", rearNode->data);
}

void empty() {
    if (dequeSize == 0) {
        printf("Empty: true\n");
    }
    else {
        printf("Empty: false\n");
    }
}

void size_deque() {
    printf("Size: %d\n", dequeSize);
}

void display() {
    if (frontNode == NULL) {
        printf("Deque is empty\n");
        return;
    }

    printf("Deque (front to rear): ");
    struct Node* temp = frontNode;

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

void clear() {
    while (frontNode != NULL) {
        struct Node* temp = frontNode;
        frontNode = frontNode->next;
        free(temp);
    }

    rearNode = NULL;
    dequeSize = 0;
    printf("Deque cleared\n");
}

void reverse() {
    if (frontNode == NULL) {
        printf("Deque is empty\n");
        return;
    }

    struct Node* curr = frontNode;
    struct Node* temp = NULL;

    while (curr != NULL) {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
    }

    temp = frontNode;
    frontNode = rearNode;
    rearNode = temp;

    printf("Deque reversed\n");
}

void sort_deque() {
    if (frontNode == NULL) {
        printf("Deque is empty\n");
        return;
    }

    int arr[dequeSize];
    int i = 0;
    struct Node* temp = frontNode;

    while (temp != NULL) {
        arr[i++] = temp->data;
        temp = temp->next;
    }

    for (int i = 0; i < dequeSize - 1; i++) {
        for (int j = 0; j < dequeSize - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int t = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = t;
            }
        }
    }

    temp = frontNode;

    for (int i = 0; i < dequeSize; i++) {
        temp->data = arr[i];
        temp = temp->next;
    }

    printf("Deque sorted\n");
}

int main() {
    int n, choice, val;

    printf("Enter number of operations: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("\nEnter operation:\n");
        printf("1=push_front  2=push_back\n");
        printf("3=pop_front   4=pop_back\n");
        printf("5=front       6=back\n");
        printf("7=empty       8=size\n");
        printf("9=display     10=clear\n");
        printf("11=reverse    12=sort\n");
        printf("Choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter value: ");
            scanf("%d", &val);
            push_front(val);
        }
        else if (choice == 2) {
            printf("Enter value: ");
            scanf("%d", &val);
            push_back(val);
        }
        else if (choice == 3) {
            pop_front();
        }
        else if (choice == 4) {
            pop_back();
        }
        else if (choice == 5) {
            front();
        }
        else if (choice == 6) {
            back();
        }
        else if (choice == 7) {
            empty();
        }
        else if (choice == 8) {
            size_deque();
        }
        else if (choice == 9) {
            display();
        }
        else if (choice == 10) {
            clear();
        }
        else if (choice == 11) {
            reverse();
        }
        else if (choice == 12) {
            sort_deque();
        }
    }

    return 0;
}