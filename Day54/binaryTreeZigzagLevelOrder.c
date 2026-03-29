//Given the root of a binary tree, return the zigzag level order traversal of its nodes' values.

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

void zigzagLevelOrder(struct Node* root) {
    if (root == NULL) {
        printf("Tree is empty\n");
        return;
    }

    struct Node** queue = (struct Node**)malloc(2000 * sizeof(struct Node*));
    int* levelVals = (int*)malloc(2000 * sizeof(int));
    int front = 0;
    int rear = 0;
    int leftToRight = 1;
    int level = 1;

    queue[rear++] = root;

    printf("Zigzag level order traversal:\n");

    while (front < rear) {
        int levelSize = rear - front;

        for (int i = 0; i < levelSize; i++) {
            struct Node* curr = queue[front++];
            levelVals[i] = curr->data;

            if (curr->left != NULL) {
                queue[rear++] = curr->left;
            }

            if (curr->right != NULL) {
                queue[rear++] = curr->right;
            }
        }

        printf("Level %d: [", level);

        if (leftToRight) {
            for (int i = 0; i < levelSize; i++) {
                if (i < levelSize - 1) {
                    printf("%d, ", levelVals[i]);
                }
                else {
                    printf("%d", levelVals[i]);
                }
            }
        }
        else {
            for (int i = levelSize - 1; i >= 0; i--) {
                if (i > 0) {
                    printf("%d, ", levelVals[i]);
                }
                else {
                    printf("%d", levelVals[i]);
                }
            }
        }

        printf("]\n");
        leftToRight = !leftToRight;
        level++;
    }

    free(queue);
    free(levelVals);
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

    zigzagLevelOrder(root);

    freeTree(root);
    free(arr);

    return 0;
}