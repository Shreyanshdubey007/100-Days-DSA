//Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

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

void levelOrder(struct Node* root) {
    if (root == NULL) {
        printf("Tree is empty\n");
        return;
    }

    struct Node** queue = (struct Node**)malloc(2000 * sizeof(struct Node*));
    int front = 0;
    int rear = 0;
    int level = 1;

    queue[rear++] = root;

    printf("Level order traversal:\n");

    while (front < rear) {
        int levelSize = rear - front;

        printf("Level %d: [", level);

        for (int i = 0; i < levelSize; i++) {
            struct Node* curr = queue[front++];

            if (i < levelSize - 1) {
                printf("%d, ", curr->data);
            }
            else {
                printf("%d", curr->data);
            }

            if (curr->left != NULL) {
                queue[rear++] = curr->left;
            }

            if (curr->right != NULL) {
                queue[rear++] = curr->right;
            }
        }

        printf("]\n");
        level++;
    }

    free(queue);
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

    levelOrder(root);

    freeTree(root);
    free(arr);

    return 0;
}