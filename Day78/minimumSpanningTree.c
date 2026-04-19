//Problem Statement: Given weighted undirected graph, compute total weight of Minimum Spanning Tree using Prim’s algorithm.

#include <stdio.h>
#include <limits.h>
#define MAX 100

int n;
int graph[MAX][MAX];

// find node with minimum key
int minKey(int key[], int visited[]) {
    int min = INT_MAX, index = -1;

    for (int i = 0; i < n; i++) {
        if (!visited[i] && key[i] < min) {
            min = key[i];
            index = i;
        }
    }
    return index;
}
int primMST() {
    int key[MAX];
    int visited[MAX];

    // initialize
    for (int i = 0; i < n; i++) {
        key[i] = INT_MAX;
        visited[i] = 0;
    }
    key[0] = 0; // start from node 0

    int totalWeight = 0;

    for (int count = 0; count < n; count++) {
        int u = minKey(key, visited);
        visited[u] = 1;

        totalWeight += key[u];

        for (int v = 0; v < n; v++) {
            if (graph[u][v] && !visited[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
            }
        }
    }

    return totalWeight;
}
int main() {
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (0 if no edge):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    int result = primMST();
    printf("Total weight of MST: %d\n", result);
    return 0;
}