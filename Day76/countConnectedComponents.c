//Problem Statement: Using DFS or BFS, count number of connected components.

#include <stdio.h>
#define MAX 100

int n, m;
int graph[MAX][MAX];
int visited[MAX];

// DFS function
void dfs(int node) {
    visited[node] = 1;

    for (int i = 1; i <= n; i++) {
        if (graph[node][i] == 1 && !visited[i]) {
            dfs(i);
        }
    }
}

int main() {
    int u, v;

    printf("Enter n (nodes) and m (edges): ");
    scanf("%d %d", &n, &m);

    // initialize graph
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            graph[i][j] = 0;
        }
        visited[i] = 0;
    }

    printf("Enter edges:\n");
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1; // undirected
    }

    int components = 0;

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i);
            components++;
        }
    }

    printf("Number of connected components: %d\n", components);

    return 0;
}