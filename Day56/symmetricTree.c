//Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

int isMirror(struct Node* left, struct Node* right) {
    if (left == NULL && right == NULL) {
        return 1;
    }

    if (left == NULL || right == NULL) {
        return 0;
    }

    if (left->data != right->data) {
        return 0;
    }

    return isMirror(left->left, right->right) &&
           isMirror(left->right, right->left);
}

bool isSymmetricRecursive(struct Node* root) {
    if (root == NULL) {
        return true;
    }

    return isMirror(root->left, root->right);
}

bool isSymmetricIterative(struct Node* root) {
    if (root == NULL) {
        return true;
    }

    struct Node** queue = (struct Node**)malloc(1000 * sizeof(struct Node*));
    int front = 0;
    int rear = 0;

    queue[rear++] = root->left;
    queue[rear++] = root->right;

    while (front < rear) {
        struct Node* left = queue[front++];
        struct Node* right = queue[front++];

        if (left == NULL && right == NULL) {
            continue;
        }

        if (left == NULL || right == NULL) {
            free(queue);
            return false;
        }

        if (left->data != right->data) {
            free(queue);
            return false;
        }

        queue[rear++] = left->left;
        queue[rear++] = right->right;
        queue[rear++] = left->right;
        queue[rear++] = right->left;
    }

    free(queue);
    return true;
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

    if (isSymmetricRecursive(root)) {
        printf("Recursive  -> Output: true\n");
    }
    else {
        printf("Recursive  -> Output: false\n");
    }

    if (isSymmetricIterative(root)) {
        printf("Iterative  -> Output: true\n");
    }
    else {
        printf("Iterative  -> Output: false\n");
    }

    freeTree(root);
    free(arr);

    return 0;
}