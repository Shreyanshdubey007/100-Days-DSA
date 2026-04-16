//Return true if and only if it is bipartite.

#include <stdio.h>

#define MAX 100

int n;
int graph[MAX][MAX];
int color[MAX];

// DFS
int dfs(int node, int c) {
    color[node] = c;

    for (int i = 0; i < n; i++) {
        if (graph[node][i]) {
            if (color[i] == -1) {
                if (!dfs(i, 1 - c))
                    return 0;
            }
            else if (color[i] == c) {
                return 0;
            }
        }
    }
    return 1;
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

    // initialize colors
    for (int i = 0; i < n; i++)
        color[i] = -1;

    int isBipartite = 1;

    for (int i = 0; i < n; i++) {
        if (color[i] == -1) {
            if (!dfs(i, 0)) {
                isBipartite = 0;
                break;
            }
        }
    }

    if (isBipartite)
        printf("Graph is Bipartite\n");
    else
        printf("Graph is NOT Bipartite\n");

    return 0;
}