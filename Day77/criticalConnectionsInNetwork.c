//Return all critical connections in the network in any order.

#include <stdio.h>
#define MAX 100

int n, m;
int graph[MAX][MAX];
int disc[MAX], low[MAX], visited[MAX];
int timeCounter = 0;

// DFS
void dfs(int u, int parent) {
    visited[u] = 1;
    disc[u] = low[u] = timeCounter++;

    for (int v = 0; v < n; v++) {
        if (graph[u][v]) {

            if (v == parent) continue;

            if (!visited[v]) {
                dfs(v, u);

                if (low[v] < low[u])
                    low[u] = low[v];

                if (low[v] > disc[u]) {
                    printf("Critical Connection: %d - %d\n", u, v);
                }
            }
            else {
                if (disc[v] < low[u])
                    low[u] = disc[v];
            }
        }
    }
}
int main() {
    int u, v;

    printf("Enter number of nodes and edges: ");
    scanf("%d %d", &n, &m);

    // initialize
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }
    printf("Enter edges:\n");
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1;
    }
    dfs(0, -1);
    return 0;
}