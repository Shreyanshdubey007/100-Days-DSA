//Given the root of a binary tree, return the preorder traversal of its nodes' values.

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

void preorderIterative(struct Node* root) {
    if (root == NULL) {
        printf("Tree is empty\n");
        return;
    }

    struct Node** stack = (struct Node**)malloc(100 * sizeof(struct Node*));
    int top = -1;

    stack[++top] = root;

    printf("Preorder traversal: ");

    while (top != -1) {
        struct Node* curr = stack[top--];
        printf("%d ", curr->data);

        if (curr->right != NULL) {
            stack[++top] = curr->right;
        }

        if (curr->left != NULL) {
            stack[++top] = curr->left;
        }
    }

    printf("\n");
    free(stack);
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

    preorderIterative(root);

    freeTree(root);
    free(arr);

    return 0;
}