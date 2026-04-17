//Given a reference of a node in a connected undirected graph. Return a deep copy (clone) of the graph.

#include <stdio.h>

#include <stdlib.h>

#define MAX 100

int n;
int graph[MAX][MAX];
int visited[MAX];

// DFS to print graph (simulate clone traversal)
void dfs(int node) {
    visited[node] = 1;
    printf("%d ", node);

    for (int i = 0; i < n; i++) {
        if (graph[node][i] && !visited[i]) {
            dfs(i);
        }
    }
}

int main() {
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    printf("DFS traversal (original graph): ");
    dfs(0);

    return 0;
}