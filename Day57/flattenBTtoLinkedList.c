//Given the root of a binary tree, flatten the tree into a "linked list":

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

void flatten(struct Node* root) {
    if (root == NULL) {
        return;
    }

    flatten(root->left);
    flatten(root->right);

    struct Node* leftSubtree = root->left;
    struct Node* rightSubtree = root->right;

    root->left = NULL;
    root->right = leftSubtree;

    struct Node* curr = root;

    while (curr->right != NULL) {
        curr = curr->right;
    }

    curr->right = rightSubtree;
}

void printList(struct Node* root) {
    if (root == NULL) {
        printf("Output: []\n");
        return;
    }

    printf("Output: ");

    struct Node* curr = root;

    while (curr != NULL) {
        if (curr->right != NULL) {
            printf("%d -> ", curr->data);
        }
        else {
            printf("%d", curr->data);
        }

        curr = curr->right;
    }

    printf("\n");
}

void freeList(struct Node* root) {
    while (root != NULL) {
        struct Node* temp = root;
        root = root->right;
        free(temp);
    }
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

    flatten(root);

    printList(root);

    freeList(root);
    free(arr);

    return 0;
}