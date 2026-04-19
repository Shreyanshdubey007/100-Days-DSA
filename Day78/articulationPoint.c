//Given an undirected connected graph with V vertices and adjacency list adj. You are required to find all the vertices
//removing which (and edges through it) disconnects the graph into 2 or more components and return it in sorted manner.

#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int n, m;
int adj[MAX][MAX];
int adjSize[MAX];

int visited[MAX], disc[MAX], low[MAX], ap[MAX];
int timer = 0;

// DFS
void dfs(int u, int parent) {
    visited[u] = 1;
    disc[u] = low[u] = ++timer;

    int children = 0;

    for (int i = 0; i < adjSize[u]; i++) {
        int v = adj[u][i];

        if (v == parent)
            continue;

        if (!visited[v]) {
            children++;

            dfs(v, u);

            if (low[v] < low[u])
                low[u] = low[v];

            // articulation condition
            if (parent != -1 && low[v] >= disc[u])
                ap[u] = 1;
        }
        else {
            if (disc[v] < low[u])
                low[u] = disc[v];
        }
    }

    // root condition
    if (parent == -1 && children > 1)
        ap[u] = 1;
}

int main() {
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &m);

    // initialize
    for (int i = 0; i < n; i++) {
        adjSize[i] = 0;
        visited[i] = 0;
        ap[i] = 0;
    }

    printf("Enter edges (0-based index):\n");
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        adj[u][adjSize[u]++] = v;
        adj[v][adjSize[v]++] = u;
    }

    // run DFS
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, -1);
        }
    }

    // print result
    int found = 0;
    printf("Articulation Points: ");
    for (int i = 0; i < n; i++) {
        if (ap[i]) {
            printf("%d ", i);
            found = 1;
        }
    }

    if (!found)
        printf("-1");

    printf("\n");

    return 0;
}