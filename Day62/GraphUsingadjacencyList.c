//Problem: Build a graph with adjacency list representation. Use linked lists or dynamic arrays.

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

void addEdge(struct Node** adj, int u, int v, int directed) {
    struct Node* newNode = createNode(v);
    newNode->next = adj[u];
    adj[u] = newNode;

    if (directed == 0) {
        struct Node* revNode = createNode(u);
        revNode->next = adj[v];
        adj[v] = revNode;
    }
}

void display(struct Node** adj, int n) {
    printf("\nAdjacency List:\n");

    for (int i = 1; i <= n; i++) {
        printf("Vertex %d -> ", i);

        struct Node* temp = adj[i];

        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }

        printf("\n");
    }
}

void freeGraph(struct Node** adj, int n) {
    for (int i = 1; i <= n; i++) {
        struct Node* temp = adj[i];

        while (temp != NULL) {
            struct Node* toFree = temp;
            temp = temp->next;
            free(toFree);
        }
    }
}

int main() {
    int n, m, choice;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &m);

    printf("Graph type (1=undirected, 2=directed): ");
    scanf("%d", &choice);

    struct Node** adj = (struct Node**)calloc(n + 1, sizeof(struct Node*));

    for (int i = 0; i < m; i++) {
        int u, v;

        printf("Enter edge %d (u v): ", i + 1);
        scanf("%d %d", &u, &v);

        if (choice == 1) {
            addEdge(adj, u, v, 0);
        }
        else {
            addEdge(adj, u, v, 1);
        }
    }

    display(adj, n);

    freeGraph(adj, n);
    free(adj);

    return 0;
}