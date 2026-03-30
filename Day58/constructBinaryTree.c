//Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.

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

int findIndex(int* inorder, int n, int val) {
    for (int i = 0; i < n; i++) {
        if (inorder[i] == val) {
            return i;
        }
    }

    return -1;
}

struct Node* buildTree(int* preorder, int preSize, int* inorder, int inSize) {
    if (preSize == 0) {
        return NULL;
    }

    int rootVal = preorder[0];
    struct Node* root = createNode(rootVal);

    int idx = findIndex(inorder, inSize, rootVal);

    root->left = buildTree(preorder + 1, idx, inorder, idx);
    root->right = buildTree(preorder + idx + 1, preSize - idx - 1, inorder + idx + 1, inSize - idx - 1);

    return root;
}

void levelOrder(struct Node* root) {
    if (root == NULL) {
        printf("Output: []\n");
        return;
    }

    struct Node** queue = (struct Node**)malloc(3000 * sizeof(struct Node*));
    int front = 0;
    int rear = 0;

    queue[rear++] = root;

    printf("Output: [");

    int first = 1;

    while (front < rear) {
        struct Node* curr = queue[front++];

        if (!first) {
            printf(", ");
        }

        if (curr == NULL) {
            printf("null");
        }
        else {
            printf("%d", curr->data);
            queue[rear++] = curr->left;
            queue[rear++] = curr->right;
            first = 0;
        }
    }

    printf("]\n");
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

    int* preorder = (int*)malloc(n * sizeof(int));
    int* inorder = (int*)malloc(n * sizeof(int));

    printf("Enter preorder traversal: ");

    for (int i = 0; i < n; i++) {
        scanf("%d", &preorder[i]);
    }

    printf("Enter inorder traversal: ");

    for (int i = 0; i < n; i++) {
        scanf("%d", &inorder[i]);
    }

    struct Node* root = buildTree(preorder, n, inorder, n);

    levelOrder(root);

    freeTree(root);
    free(preorder);
    free(inorder);

    return 0;
}