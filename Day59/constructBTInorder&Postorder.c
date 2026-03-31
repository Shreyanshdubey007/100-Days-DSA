//Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and 
//postorder is the postorder traversal of the same tree, construct and return the binary tree.

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

struct Node* buildTree(int* inorder, int inSize, int* postorder, int postSize) {
    if (postSize == 0) {
        return NULL;
    }

    int rootVal = postorder[postSize - 1];
    struct Node* root = createNode(rootVal);

    int idx = findIndex(inorder, inSize, rootVal);

    root->left = buildTree(inorder, idx, postorder, idx);
    root->right = buildTree(inorder + idx + 1, inSize - idx - 1, postorder + idx, postSize - idx - 1);

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
    int first = 1;

    queue[rear++] = root;

    printf("Output: [");

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

    int* inorder = (int*)malloc(n * sizeof(int));
    int* postorder = (int*)malloc(n * sizeof(int));

    printf("Enter inorder traversal: ");

    for (int i = 0; i < n; i++) {
        scanf("%d", &inorder[i]);
    }

    printf("Enter postorder traversal: ");

    for (int i = 0; i < n; i++) {
        scanf("%d", &postorder[i]);
    }

    struct Node* root = buildTree(inorder, n, postorder, n);

    levelOrder(root);

    freeTree(root);
    free(inorder);
    free(postorder);

    return 0;
}