//Problem Statement: Find shortest distances from source vertex in a weighted graph with non-negative weights.

#include <stdio.h>
#include <limits.h>

#define MAX 100

int n, m;

// adjacency list
int adj[MAX][MAX];
int weight[MAX][MAX];
int adjSize[MAX];

// min heap
int heap[MAX], dist[MAX], size;

// swap
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// heapify
void heapify(int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < size && dist[heap[left]] < dist[heap[smallest]])
        smallest = left;

    if (right < size && dist[heap[right]] < dist[heap[smallest]])
        smallest = right;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapify(smallest);
    }
}

// push into heap
void push(int v) {
    heap[size++] = v;

    int i = size - 1;
    while (i > 0 && dist[heap[(i-1)/2]] > dist[heap[i]]) {
        swap(&heap[i], &heap[(i-1)/2]);
        i = (i-1)/2;
    }
}

// pop min
int pop() {
    int root = heap[0];
    heap[0] = heap[--size];
    heapify(0);
    return root;
}

int main() {
    printf("Enter n and m: ");
    scanf("%d %d", &n, &m);

    // init
    for (int i = 1; i <= n; i++) {
        adjSize[i] = 0;
        dist[i] = INT_MAX;
    }

    printf("Enter edges (u v w):\n");
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);

        adj[u][adjSize[u]] = v;
        weight[u][adjSize[u]++] = w;

        adj[v][adjSize[v]] = u;       // undirected
        weight[v][adjSize[v]++] = w;
    }

    int source;
    printf("Enter source: ");
    scanf("%d", &source);

    // Dijkstra
    dist[source] = 0;
    size = 0;
    push(source);

    while (size > 0) {
        int u = pop();

        for (int i = 0; i < adjSize[u]; i++) {
            int v = adj[u][i];
            int w = weight[u][i];

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                push(v);
            }
        }
    }

    // output
    printf("Distances:\n");
    for (int i = 1; i <= n; i++) {
        printf("%d ", dist[i]);
    }

    return 0;
}