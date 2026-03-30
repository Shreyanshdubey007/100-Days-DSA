//Problem Statement:Construct a binary tree from given preorder and inorder traversal arrays.

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

struct Node* buildTree(int* preorder, int* inorder, int n) {
    if (n == 0) {
        return NULL;
    }

    int rootVal = preorder[0];
    struct Node* root = createNode(rootVal);

    int idx = findIndex(inorder, n, rootVal);

    root->left = buildTree(preorder + 1, inorder, idx);
    root->right = buildTree(preorder + idx + 1, inorder + idx + 1, n - idx - 1);

    return root;
}

void postorder(struct Node* root) {
    if (root == NULL) {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
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

    struct Node* root = buildTree(preorder, inorder, n);

    printf("Postorder traversal: ");
    postorder(root);
    printf("\n");

    freeTree(root);
    free(preorder);
    free(inorder);

    return 0;
}