//Problem: BST Insert

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

void inorder(struct Node* root) {
    if (root == NULL) {
        return;
    }

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
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
    int n, val;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    struct Node* root = NULL;

    printf("Enter %d elements: ", n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insert(root, val);
        printf("Inserted: %d\n", val);
    }

    printf("Inorder traversal: ");
    inorder(root);
    printf("\n");

    freeTree(root);

    return 0;
}