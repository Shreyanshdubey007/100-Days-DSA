//Return true if you can finish all courses. Otherwise, return false.

#include <stdio.h>
#include <stdbool.h>

#define MAX 2000

int graph[MAX][MAX];
int visited[MAX];
int recStack[MAX];
int n;

bool dfs(int node) {
    visited[node] = 1;
    recStack[node] = 1;

    for (int i = 0; i < n; i++) {
        if (graph[node][i]) {
            if (!visited[i] && dfs(i))
                return true;
            else if (recStack[i])
                return true;
        }
    }

    recStack[node] = 0;
    return false;
}

bool canFinish() {
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i))
                return false;
        }
    }
    return true;
}

int main() {
    int edges, u, v;

    printf("Enter number of courses: ");
    scanf("%d", &n);

    printf("Enter number of prerequisites: ");
    scanf("%d", &edges);

    // initialize
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        recStack[i] = 0;
        for (int j = 0; j < n; j++)
            graph[i][j] = 0;
    }

    printf("Enter prerequisites (a b):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        graph[v][u] = 1;  // b -> a
    }

    if (canFinish())
        printf("true\n");
    else
        printf("false\n");

    return 0;
}