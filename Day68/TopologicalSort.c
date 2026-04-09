//Problem: Implement topological sorting using in-degree array and queue (Kahnâ€™s Algorithm).

#include <stdio.h>
#define MAX 100

int graph[MAX][MAX];
int indegree[MAX];
int queue[MAX];
int front = 0, rear = -1;
int n;

// enqueue
void enqueue(int x) {
    queue[++rear] = x;
}

// dequeue
int dequeue() {
    return queue[front++];
}

// Kahn's Algorithm
void topoSort() {
    int count = 0;

    // Step 1: calculate indegree
    for (int i = 0; i < n; i++) {
        indegree[i] = 0;
        for (int j = 0; j < n; j++) {
            if (graph[j][i])
                indegree[i]++;
        }
    }

    // Step 2: add nodes with indegree 0
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0)
            enqueue(i);
    }

    printf("Topological Order: ");

    // Step 3: process queue
    while (front <= rear) {
        int node = dequeue();
        printf("%d ", node);
        count++;

        for (int i = 0; i < n; i++) {
            if (graph[node][i]) {
                indegree[i]--;
                if (indegree[i] == 0)
                    enqueue(i);
            }
        }
    }

    // Step 4: check cycle
    if (count != n) {
        printf("\nCycle detected! Topological sort not possible.\n");
    }
}

int main() {
    int edges, u, v;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    // initialize graph
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            graph[i][j] = 0;
    }

    printf("Enter edges (u v):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        graph[u][v] = 1; // directed edge
    }

    topoSort();

    return 0;
}