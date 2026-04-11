//We will send a signal from a given node k. Return the minimum time it takes for all the n nodes to receive the signal.
//If it is impossible for all the n nodes to receive the signal, return -1.

#include <stdio.h>

#define MAX 101
#define INF 999999

int graph[MAX][MAX];
int dist[MAX];
int visited[MAX];
int n;

// find min distance node
int minDistance() {
    int min = INF, idx = -1;

    for (int i = 1; i <= n; i++) {
        if (!visited[i] && dist[i] < min) {
            min = dist[i];
            idx = i;
        }
    }
    return idx;
}

// Dijkstra
int networkDelay(int k) {
    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }

    dist[k] = 0;

    for (int i = 1; i <= n; i++) {
        int u = minDistance();
        if (u == -1) break;

        visited[u] = 1;

        for (int v = 1; v <= n; v++) {
            if (!visited[v] && graph[u][v] != INF &&
                dist[u] + graph[u][v] < dist[v]) {
                
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    int maxTime = 0;

    for (int i = 1; i <= n; i++) {
        if (dist[i] == INF)
            return -1;
        if (dist[i] > maxTime)
            maxTime = dist[i];
    }

    return maxTime;
}

int main() {
    int edges, u, v, w, k;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    // initialize graph
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            graph[i][j] = INF;
        }
    }

    printf("Enter edges (u v w):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w; // directed
    }

    printf("Enter source k: ");
    scanf("%d", &k);

    int result = networkDelay(k);

    printf("Output: %d\n", result);

    return 0;
}