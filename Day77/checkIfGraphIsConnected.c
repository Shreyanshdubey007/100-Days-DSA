//Problem Statement: Using BFS or DFS, check if the entire graph is connected.

#include <stdio.h>

#define MAX 100

int n, m;
int graph[MAX][MAX];
int visited[MAX];

// DFS
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

    // initialize
    for (int i = 1; i <= n; i++) {
        visited[i] = 0;
        for (int j = 1; j <= n; j++) {
            graph[i][j] = 0;
        }
    }

    printf("Enter edges:\n");
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1; // undirected
    }

    // start DFS from node 1
    dfs(1);

    // check if all visited
    int connected = 1;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            connected = 0;
            break;
        }
    }

    if (connected)
        printf("CONNECTED\n");
    else
        printf("NOT CONNECTED\n");

    return 0;
}