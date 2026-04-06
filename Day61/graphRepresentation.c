//Problem: Build a graph with n vertices and m edges using adjacency matrix representation.
//The graph may be directed or undirected.

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m, choice;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &m);

    int** adj = (int**)malloc(n * sizeof(int*));

    for (int i = 0; i < n; i++) {
        adj[i] = (int*)calloc(n, sizeof(int));
    }

    printf("Graph type (1=undirected, 2=directed): ");
    scanf("%d", &choice);

    for (int i = 0; i < m; i++) {
        int u, v;

        printf("Enter edge %d (u v): ", i + 1);
        scanf("%d %d", &u, &v);

        u--;
        v--;

        if (choice == 1) {
            adj[u][v] = 1;
            adj[v][u] = 1;
        }
        else {
            adj[u][v] = 1;
        }
    }

    printf("\nAdjacency Matrix:\n");
    printf("  ");

    for (int i = 0; i < n; i++) {
        printf("%d ", i + 1);
    }

    printf("\n");

    for (int i = 0; i < n; i++) {
        printf("%d ", i + 1);

        for (int j = 0; j < n; j++) {
            printf("%d ", adj[i][j]);
        }

        printf("\n");
    }

    for (int i = 0; i < n; i++) {
        free(adj[i]);
    }

    free(adj);

    return 0;
}