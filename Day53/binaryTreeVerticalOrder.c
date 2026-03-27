//Problem Statement:Given a binary tree, print its vertical order traversal. Nodes that lie on the same vertical line should be printed together from top to bottom and from left to right.

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* buildTree(int* arr, int n) {
    if (n == 0 || arr[0] == -1) {
        return NULL;
    }

    struct Node** queue = (struct Node**)malloc(n * sizeof(struct Node*));
    int front = 0;
    int rear = 0;

    struct Node* root = createNode(arr[0]);
    queue[rear++] = root;

    int i = 1;

    while (i < n && front < rear) {
        struct Node* curr = queue[front++];

        if (i < n && arr[i] != -1) {
            curr->left = createNode(arr[i]);
            queue[rear++] = curr->left;
        }
        i++;

        if (i < n && arr[i] != -1) {
            curr->right = createNode(arr[i]);
            queue[rear++] = curr->right;
        }
        i++;
    }

    free(queue);
    return root;
}

#define MAX 1000

int colNodes[MAX][MAX];
int colCount[MAX];
int minCol, maxCol;

void findVertical(struct Node* root, int col) {
    if (root == NULL) {
        return;
    }

    if (col < minCol) {
        minCol = col;
    }

    if (col > maxCol) {
        maxCol = col;
    }

    int idx = col + 500;
    colNodes[idx][colCount[idx]++] = root->data;

    findVertical(root->left, col - 1);
    findVertical(root->right, col + 1);
}

void freeTree(struct Node* root) {
    if (root == NULL) {
        return;
    }

    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    int n;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    int* arr = (int*)malloc(n * sizeof(int));

    printf("Enter %d values (-1 for NULL): ", n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* root = buildTree(arr, n);

    minCol = 0;
    maxCol = 0;

    for (int i = 0; i < MAX; i++) {
        colCount[i] = 0;
    }

    findVertical(root, 0);

    printf("Vertical order traversal:\n");

    for (int col = minCol; col <= maxCol; col++) {
        int idx = col + 500;

        for (int i = 0; i < colCount[idx]; i++) {
            if (i < colCount[idx] - 1) {
                printf("%d ", colNodes[idx][i]);
            }
            else {
                printf("%d", colNodes[idx][i]);
            }
        }

        printf("\n");
    }

    freeTree(root);
    free(arr);

    return 0;
}