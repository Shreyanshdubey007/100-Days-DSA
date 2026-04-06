//Problem: Perform DFS starting from a given source vertex using recursion.

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

void addEdge(struct Node** adj, int u, int v) {
    struct Node* newNode = createNode(v);
    newNode->next = adj[u];
    adj[u] = newNode;

    struct Node* revNode = createNode(u);
    revNode->next = adj[v];
    adj[v] = revNode;
}

void dfs(struct Node** adj, int* visited, int node) {
    visited[node] = 1;
    printf("%d ", node);

    struct Node* temp = adj[node];

    while (temp != NULL) {
        if (visited[temp->data] == 0) {
            dfs(adj, visited, temp->data);
        }

        temp = temp->next;
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
    int n, m, s;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &m);

    struct Node** adj = (struct Node**)calloc(n + 1, sizeof(struct Node*));

    for (int i = 0; i < m; i++) {
        int u, v;

        printf("Enter edge %d (u v): ", i + 1);
        scanf("%d %d", &u, &v);

        addEdge(adj, u, v);
    }

    printf("Enter starting vertex: ");
    scanf("%d", &s);

    int* visited = (int*)calloc(n + 1, sizeof(int));

    printf("DFS traversal: ");
    dfs(adj, visited, s);
    printf("\n");

    freeGraph(adj, n);
    free(adj);
    free(visited);

    return 0;
}