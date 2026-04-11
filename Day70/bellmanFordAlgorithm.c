//Problem: Compute shortest path from source and detect negative weight cycles using Bellman-Ford.

#include <stdio.h>

#define MAX 100
#define INF 999999

int main() {
    int n, m;
    int edges[MAX][3];
    int dist[MAX];
    int src;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &m);

    printf("Enter edges (u v w):\n");
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &edges[i][0], &edges[i][1], &edges[i][2]);
    }

    printf("Enter source: ");
    scanf("%d", &src);

    // initialize
    for (int i = 0; i < n; i++)
        dist[i] = INF;

    dist[src] = 0;

    // relax edges
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m; j++) {
            int u = edges[j][0];
            int v = edges[j][1];
            int w = edges[j][2];

            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    // check negative cycle
    int hasCycle = 0;
    for (int j = 0; j < m; j++) {
        int u = edges[j][0];
        int v = edges[j][1];
        int w = edges[j][2];

        if (dist[u] != INF && dist[u] + w < dist[v]) {
            hasCycle = 1;
            break;
        }
    }

    if (hasCycle) {
        printf("NEGATIVE CYCLE\n");
    } else {
        printf("Shortest distances:\n");
        for (int i = 0; i < n; i++) {
            printf("Node %d -> %d\n", i, dist[i]);
        }
    }

    return 0;
}