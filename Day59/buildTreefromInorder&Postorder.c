//Problem Statement:Construct a binary tree from given inorder and postorder traversal arrays.

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
struct Node* buildTree(int* inorder, int* postorder, int n) {
    if (n == 0) {
        return NULL;
    }

    int rootVal = postorder[n - 1];
    struct Node* root = createNode(rootVal);

    int idx = findIndex(inorder, n, rootVal);

    root->left = buildTree(inorder, postorder, idx);
    root->right = buildTree(inorder + idx + 1, postorder + idx, n - idx - 1);

    return root;
}
void preorder(struct Node* root) {
    if (root == NULL) {
        return;
    }

    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
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

    struct Node* root = buildTree(inorder, postorder, n);

    printf("Preorder traversal: ");
    preorder(root);
    printf("\n");

    freeTree(root);
    free(inorder);
    free(postorder);

    return 0;
}