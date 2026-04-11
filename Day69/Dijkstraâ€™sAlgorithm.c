//Problem: Given weighted graph with non-negative edges, compute shortest path from source using priority queue.

#include <stdio.h>
#define MAX 100
#define INF 999999

int graph[MAX][MAX];
int dist[MAX];
int visited[MAX];
int n;

// function to find node with minimum distance
int minDistance() {
    int min = INF, min_index = -1;

    for (int i = 0; i < n; i++) {
        if (!visited[i] && dist[i] < min) {
            min = dist[i];
            min_index = i;
        }
    }
    return min_index;
}

// Dijkstra Algorithm
void dijkstra(int src) {
    // initialize
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }

    dist[src] = 0;

    for (int count = 0; count < n - 1; count++) {
        int u = minDistance(); // get min node
        visited[u] = 1;

        // update distances
        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != INF &&
                dist[u] + graph[u][v] < dist[v]) {
                
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // print result
    printf("Shortest distances from source %d:\n", src);
    for (int i = 0; i < n; i++) {
        printf("Node %d -> %d\n", i, dist[i]);
    }
}

int main() {
    int edges, u, v, w;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    // initialize graph
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }

    printf("Enter edges (u v weight):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w; // remove this line for directed graph
    }

    int src;
    printf("Enter source vertex: ");
    scanf("%d", &src);

    dijkstra(src);

    return 0;
}