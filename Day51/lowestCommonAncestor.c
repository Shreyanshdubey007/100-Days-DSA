//Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.

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

struct Node* lowestCommonAncestor(struct Node* root, int p, int q) {
    if (root == NULL) {
        return NULL;
    }

    if (p < root->data && q < root->data) {
        return lowestCommonAncestor(root->left, p, q);
    }
    else if (p > root->data && q > root->data) {
        return lowestCommonAncestor(root->right, p, q);
    }
    else {
        return root;
    }
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
    int n, p, q;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    int* arr = (int*)malloc(n * sizeof(int));

    printf("Enter %d values (-1 for NULL): ", n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* root = buildTree(arr, n);

    printf("Enter two node values: ");
    scanf("%d %d", &p, &q);

    struct Node* lca = lowestCommonAncestor(root, p, q);

    if (lca != NULL) {
        printf("LCA of %d and %d: %d\n", p, q, lca->data);
    }
    else {
        printf("LCA not found\n");
    }

    freeTree(root);
    free(arr);

    return 0;
}