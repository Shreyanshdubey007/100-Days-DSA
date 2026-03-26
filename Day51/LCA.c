//Problem Statement:Find the Lowest Common Ancestor (LCA) of two nodes in a Binary Search Tree.

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

struct Node* insert(struct Node* root, int val) {
    if (root == NULL) {
        return createNode(val);
    }

    if (val < root->data) {
        root->left = insert(root->left, val);
    }
    else if (val > root->data) {
        root->right = insert(root->right, val);
    }

    return root;
}

struct Node* findLCA(struct Node* root, int p, int q) {
    if (root == NULL) {
        return NULL;
    }

    if (p < root->data && q < root->data) {
        return findLCA(root->left, p, q);
    }
    else if (p > root->data && q > root->data) {
        return findLCA(root->right, p, q);
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
    int n, val, p, q;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    struct Node* root = NULL;

    printf("Enter %d elements: ", n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insert(root, val);
    }

    printf("Enter two node values: ");
    scanf("%d %d", &p, &q);

    struct Node* lca = findLCA(root, p, q);

    if (lca != NULL) {
        printf("LCA of %d and %d: %d\n", p, q, lca->data);
    }
    else {
        printf("LCA not found\n");
    }

    freeTree(root);

    return 0;
}